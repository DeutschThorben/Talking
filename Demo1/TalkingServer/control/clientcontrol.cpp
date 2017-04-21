#include "clientcontrol.h"

ClientControl::ClientControl(QTcpSocket *sockfd, QObject *parent)
: QObject(parent),
  m_socket(sockfd)
{
    m_serverCommon = new ServerCommon();
    m_tableCommon = new TableCommon();
    m_socketMessage = new SocketMessage();

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onPackageRead()));
}

ClientControl::~ClientControl()
{

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
        onFindNewFriend(m_otherUser);
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
 * ReturnValue: loading success (1), keyword wrong (3), not find user (2)
 */
void ClientControl::onUserLoading(QString login_name, QString login_keyword, int login_state)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    int result = 0;
    if (m_tableCommon->onIsRegistUser(login_name)) {
        if (m_tableCommon->onIsCorrectKeywordLogin(login_name, login_keyword)) {
            // login success
            result = result_Success;

            // add this user to map_state and map_online
            if (state_online == m_state) {
                m_socketMessage->onAddUserToOnline(login_name, m_socket);
            }
            m_socketMessage->onAddUserToState(login_name, login_state);

            // send signal to server to change list state
            emit onUserStateChange(login_name, "Login");

            // send the user's state to him friend
            onSendMyStateToFriend(login_name, login_staten);
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
