#include "clientcontrol.h"

ClientControl::ClientControl(QTcpSocket *sockfd, QObject *parent)
    : QObject(parent),
      m_socket(sockfd)
{
    m_serverCommon = new ServerCommon();
    m_tableCommon = new TableCommon();
    m_friendCommon = new FriendCommon();
    m_socketMessage = new SocketMessage();

    m_serverCommon->onSetMySocket(m_socket);
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onPackageRead()));
    connect(m_socketMessage, SIGNAL(onSendToEveryone(QString,QTcpSocket*)), this, SLOT(onFriendListToEveryone(QString,QTcpSocket*)));
}

ClientControl::~ClientControl()
{
//    disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(onPackageRead()));
//    disconnect(m_socketMessage, SIGNAL(onSendToEveryone(QString,QTcpSocket*)), this, SLOT(onFriendListToEveryone(QString,QTcpSocket*)));

    delete m_serverCommon;
    delete m_tableCommon;
    delete m_friendCommon;
    delete m_socketMessage;

    m_serverCommon = NULL;
    m_tableCommon = NULL;
    m_friendCommon = NULL;
    m_socketMessage = NULL;
}

/*
 * onPackageRead
 * Introduction: make action about type of package from client
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void ClientControl::onPackageRead()
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    Package bag = m_serverCommon->onReadPackageFromClient();

    QString m_name = m_serverCommon->onCharToQString(bag.name);
    QString m_keyword = m_serverCommon->onCharToQString(bag.keyword);
    QString m_otherUser = m_serverCommon->onCharToQString(bag.otherUser);
    QString m_message = m_serverCommon->onCharToQString(bag.message);

    switch(bag.head) {
    case User_Regist:
        onNewUserRegist(m_name, m_keyword);
        break;
    case User_Login:
        onUserLoading(m_name, m_keyword, bag.result);
        break;
    case User_Talking:
        onUserTalkingWithOther(m_name, m_otherUser, m_message);
        break;
    case User_TalkingAll:
        onUserTalkingInMasses(m_name, m_message);
        break;
    case User_IsSameName:
        onIsTheNameHasBeenUsed(m_name);
        break;
    case User_FindFriend:
        onFindNewFriend(m_name, m_otherUser, bag.result);
        break;
    case User_CreateFriendList:
        onCreateAFriendList(m_name);
        break;
    case User_StateChange:
        onClientStateChange(m_name, bag.result);
        break;
    default:
        break;
    }
    // onPackageRead   <-Introduction
}

/*
 * onNewUserRegist
 * Introduction: action about a new user want to regist
 * Formal parameter: [regist name, regist keyword]
 * ReturnValue: regist success (1), failure (0)
 */
void ClientControl::onNewUserRegist(QString new_name, QString new_keywork)
{
    // Server don't judge whether the name is been used
    // Client will judge this temporary
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    int result = 0;

    if (m_tableCommon->onAddNewUser(new_name, new_keywork)) {
        result = result_Success;
        emit onUserStateChange(new_name, "Regist");
    }
    else {
        result = result_Failure;
    }
    m_serverCommon->onWriteToClient(User_Regist, result);
    // onNewUserRegist   <-Introduction
}

/*
 * onUserLoading
 * Introduction: action about a  user want to login
 * Formal parameter: [loading name, loading keyword, loading state]
 * ReturnValue: loading success (1), keyword wrong (4), not find user (3)
 */
void ClientControl::onUserLoading(QString login_name, QString login_keyword, int login_state)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    int result = 0;
    if (m_tableCommon->onIsRegistUser(login_name)) {
        if (m_tableCommon->onIsCorrectKeywordLogin(login_name, login_keyword)) {
            // judge the user whether is loading
            int tmp = m_socketMessage->onSelectStateByName(login_name);
            qDebug("[%s] tmp is [%d]", __PRETTY_FUNCTION__, tmp);
            if (state_offline == tmp) {
                // login success
                result = result_Success;

                // add this user to map_state and map_online
                m_socketMessage->onAddUserToOnline(login_name, m_socket);
                m_socketMessage->onAddUserToState(login_name, login_state);

                // send signal to server to change list state
                emit onUserStateChange(login_name, "Login");

                // send friend list to client
                onGetFriendList(login_name, m_socket);
                // inform everyone to get friend list
                onSendMyStateToFriend(login_name, login_state);
            }
            else {
                result = result_alreadyLoading;
            }
        }
        else {
            // keyword is mistake
            result = result_KeywordMistake;
        }
    }
    else {
        // not have this user
        result = result_NotFindName;
    }
    m_serverCommon->onWriteToClient(User_Login, result);
    // onUserLoading   <-Introduction
}


void ClientControl::onUserTalkingWithOther(QString m_name, QString m_other, QString m_message)
{

}

void ClientControl::onUserTalkingInMasses(QString m_name, QString m_message)
{

}

/*
 * onIsTheNameHasBeenUsed
 * Introduction: whether the name is have in user table
 * Formal parameter: [select name]
 * ReturnValue: the name is used (2), not used (3)
 */
void ClientControl::onIsTheNameHasBeenUsed(QString m_name)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    int ret = 0;
    if (m_tableCommon->onIsRegistUser(m_name)) {
        ret = result_HasName;
    }
    else {
        ret = result_NotFindName;
    }
    m_serverCommon->onWriteToClient(User_IsSameName, ret);
    // onIsTheNameHasBeenUsed   <-Introduction
}

/*
 * onFindNewFriend
 * Introduction: one want to add other to a friend
 * Formal parameter: [my name, other name, information of result]
 * ReturnValue: not find the other(3) / whether the other is agree(5) / other agree(6) / other regist(0)
 */
void ClientControl::onFindNewFriend(QString m_name, QString find_name, int result)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    int ret = 0;
    if (result_WantFriend == result) {
        // find new friend
        if (m_tableCommon->onIsRegistUser(find_name)) {
            ret = result_WhetherAgreeFriend;
        }
        else {
            ret = result_NotFindName;
        }
    }
    else if (result_AgreeFriend == result) {
        ret = result_AgreeFriend;
        m_friendCommon->onAddNewFriend(m_name, find_name);
        onGetFriendList(m_name, m_socket);
        emit onUserFriendAdd(m_name, find_name);
    }
    else if (result_Failure == result) {
        ret = result_Failure;
    }

    m_serverCommon->onWriteToClient(User_FindFriend, ret, m_name, "", find_name);
    // onFindNewFriend   <-Introduction
}

void ClientControl::onSendMyStateToFriend(QString m_name, int m_state)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    m_socketMessage->onSendMessageToEveryone(User_StateChange, m_name, "", m_state);
    // onSendMyStateToFriend   <-Introduction
}

/*
 * onCreateAFriendList
 * Introduction: new regist user create friend list
 * Formal parameter: [apply of name]
 * ReturnValue: nothing
 */
void ClientControl::onCreateAFriendList(QString m_name)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    m_friendCommon->onCreateFriendList(m_name);
    // onCreateAFriendList   <-Introduction
}

/*
 * onClientStateChange
 * Introduction: change state for state_map and online_map
 * Formal parameter: [change state name, change state]
 * ReturnValue: nothing
 */
void ClientControl::onClientStateChange(QString m_name, int m_state)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    if (state_offline == m_state) {
        // user is exit
        m_socketMessage->onRemoveUserFromOnline(m_name);
        m_socketMessage->onRemoveUserFromState(m_name);
    }
    else {
        m_socketMessage->onChangeState(m_name, m_state);
    }
    onSendMyStateToFriend(m_name, m_state);
    // onClientStateChange   <-Introduction
}

/*
 * onGetFriendList
 * Introduction: pack friend's name and them state and send to him
 * Formal parameter: [someone name, his socket]
 * ReturnValue: nothing
 */
void ClientControl::onGetFriendList(QString m_name, QTcpSocket* sockfd)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    ShowFriendList bag;
    QString f_name;
    int f_state = 0;
    int i = 0;

    int maxID = m_friendCommon->onGetMaxID(m_name);
    if (maxID > 0) {
        for (int ID = 1; ID <= maxID; ID++) {
            f_name = m_friendCommon->onSelectNameForID(m_name, ID);
            qDebug("[%s] name is [%s]", __PRETTY_FUNCTION__, f_name.toStdString().c_str());
            if ("" == f_name) {
                // this friend has been delete
                continue;
            }

            f_state = m_socketMessage->onSelectStateByName(f_name);
            qDebug("[%s] state is [%d]", __PRETTY_FUNCTION__, f_state);
            if (state_hiding == f_state) {
                f_state = state_offline;
            }

            strcpy(bag.f_name[i], f_name.toStdString().c_str());
            qDebug("[%s] 111 name is [%s]", __PRETTY_FUNCTION__, bag.f_name[i][20]);
            bag.f_state[i] = f_state;
            qDebug("[%s] state is [%d]", __PRETTY_FUNCTION__, bag.f_state[i]);
            i++;
        }


        bag.head = User_FriendList;
        bag.i = i;
        sockfd->write((char*)(&bag), sizeof(ShowFriendList));
    }
    // onGetFriendList   <-Introduction
}

void ClientControl::onFriendListToEveryone(QString f_name, QTcpSocket *f_socket)
{
    qDebug("[%s] name is [%s], socket is [%p]", __PRETTY_FUNCTION__, f_name.toStdString().c_str(), f_socket);
    onGetFriendList(f_name, f_socket);
    // onFriendListToEveryone   <-Introduction
}
