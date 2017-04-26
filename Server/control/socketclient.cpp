#include "socketclient.h"
#include "control/socketmessage.h"

SocketClient::SocketClient(QTcpSocket *socket, QObject *parent) : QObject(parent), m_socket(socket)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    m_userList = new UserList();
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()), Qt::DirectConnection);
}

SocketClient::~SocketClient()
{
    delete m_userList;
    m_userList = NULL;
}

void SocketClient::onReadyRead()
{
    Package bag = onReadPackage();
    qDebug("[%s] PackageType is [%d]", __PRETTY_FUNCTION__, bag.head);

    QString m_name = onCharToQString(bag.name);
    QString m_keyword = onCharToQString(bag.keyword);
    QString m_otherUser = onCharToQString(bag.otherUser);
    QString m_talkInformation = onCharToQString(bag.talkingInformation);

    SocketMessage *m_message = SocketMessage::getInstance();

    switch (bag.head) {
    case USER_Regist:
        qDebug("[%s] Client is registing", __PRETTY_FUNCTION__);
        onNewUserRegist(m_name, m_keyword);
        break;
    case USER_Login:
        qDebug("[%s] Client is loading", __PRETTY_FUNCTION__);
        onUserLogin(m_name, m_keyword, bag.result);
        break;
    case USER_Regist_IsSameName:
        qDebug("[%s] ", __PRETTY_FUNCTION__);
        onWhetherIsSame(m_name);
        break;
    case USER_Talking:
        qDebug("[%s] Client is talking with other", __PRETTY_FUNCTION__);
        onTalkingWithOther(m_name, m_otherUser, m_talkInformation);
        break;
    case USER_FindFriend:
        qDebug("[%s] Client add new friend", __PRETTY_FUNCTION__);
        onFindNewFriend(m_otherUser, bag.result);
        break;
    case USER_Online_Back:
        qDebug("[%s] Client is online already back", __PRETTY_FUNCTION__);
        onAlreadyOnlineStateBack(m_name, m_otherUser, bag.result);
        break;
    case USER_StateChange:
        qDebug("[%s] Client's state change", __PRETTY_FUNCTION__);
        onUserStateChange(m_name, bag.result);
        break;
//    case USER_Exit:
//        qDebug("[%s] Client exit", __PRETTY_FUNCTION__);
//        m_message->sendStateToAll(USER_Exit, m_name, 0);
//        m_message->deleteOnlineUser(m_name);
//        emit UserStateChange("Exit", m_name);
//        break;
    default:
        break;
    }
    // onReadyRead   <-Introduction
}

/*
 *  onReadPackage
 *  Introduction: get news from client
 *  ReturnValue: package from client
 */
Package SocketClient::onReadPackage()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = {EMPTY};
    m_socket->read((char*)(&bag), sizeof(Package));
    qDebug("[%s] receive package from client", __PRETTY_FUNCTION__);
    return bag;
    // onReadPackage   <-Introduction
}

/*
 *  onWritePackage
 *  Introduction: take the package from server to client
 *  ReturnValue: nothing
 */
void SocketClient::onWritePackage(PackageType head, QString name, QString otherUser, QString talkingInformation, int result)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = {EMPTY};

    // push the new to the package
    bag.head = head;
    bag.result = result;
    strncpy(bag.name, onQStringChangeToChar(name), 20);
    strncpy(bag.otherUser, onQStringChangeToChar(otherUser), 20);
    strncpy(bag.talkingInformation, onQStringChangeToChar(talkingInformation), 40);

    qDebug("[%s]head is [%d]", __PRETTY_FUNCTION__, bag.head);
    qDebug("[%s] bag.name is [%s]", __PRETTY_FUNCTION__, bag.name);
    qDebug("[%s] bag.keyword is [%s]", __PRETTY_FUNCTION__, bag.keyword);
    qDebug("[%s] bag.otherUser is [%s]", __PRETTY_FUNCTION__, bag.otherUser);
    qDebug("[%s]result is [%d]", __PRETTY_FUNCTION__, bag.result);

    SocketMessage *m_message = SocketMessage::getInstance();
    QTcpSocket *sockfd = m_message->onFindSockedByName(otherUser);

    if ((NULL != sockfd) && (m_socket != sockfd)) {
        // talking with other
        qDebug("[%s] send message to other   socket is [%p]", __PRETTY_FUNCTION__, sockfd);
        sockfd->write((char*)(&bag), sizeof(Package));
    }
    else {
        // feedback client
        qDebug("[%s] send message to myself", __PRETTY_FUNCTION__);
        qDebug("[%s] 111111send message to myself [%p]", __PRETTY_FUNCTION__, m_socket);
        m_socket->write((char*)(&bag), sizeof(Package));
    }
    // onWritePackage   <-Introduction
}

/*
 *  onNewUserRegist
 *  Introduction: client regist new user ( USER_Regist )
 *  ReturnValue: register success (1), register failure (0)
 */
void SocketClient::onNewUserRegist(QString name, QString keyword)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    int ret = 0;
    UserInformation *user_information = new UserInformation(name, keyword);

    if (m_userList->onAddUser(user_information)) {
        // user register success
        ret = 1;
        emit UserStateChange("Regist", name);
    }
    else {
        // user register failure
        ret = 0;
    }

    qDebug("[%s] take the bag to client about regist ret = [%d]", __PRETTY_FUNCTION__, ret);
    onWritePackage(USER_Regist, "", "", "", ret);
    // onNewUserRegist   <-Introduction
}

/*
 *  onWhetherIsSame
 *  Introduction: judged username whether is same ( USER_Login_IsSameName )
 *  ReturnValue: The name is same (1), not same (0)
 */
void SocketClient::onWhetherIsSame(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    int ret = 0;
    UserInformation *user_information = new UserInformation(name, "");
    if (m_userList->onIsRegisterUser(user_information)) {
        ret = 1;
    }
    else {
        ret = 0;
    }

    onWritePackage(USER_Regist_IsSameName, "", "", "", ret);
    // onWhetherIsSame   <-Introduction
}

/*
 *  onUserLogin
 *  Introduction: client user login ( USER_Login )
 *  ReturnValue: login success (1), login failure (0), user login already (2)
 */
void SocketClient::onUserLogin(QString name, QString keyword, int state)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    int ret = 0;
    SocketMessage *m_message = SocketMessage::getInstance();

    if (m_userList->onSelectSomeNameByName(name)) {
        if (m_message->isUserOnline(name)) {
            // this user is logined already
            ret = 2;
        }
        else {
            if (m_userList->onLoginUser(name, keyword)) {
                // user login success
                ret = 1;
                emit UserStateChange("Login", name);
                onUserStateChange(name, state);
                qDebug("[%s] 1111 name is [%s], socket is [%p]", __PRETTY_FUNCTION__, name.toStdString().c_str(), m_socket);
                m_message->insertOnlineUser(name, m_socket);
            }
            else {
                // user keyword is mistake
                ret = 0;
            }
        }
    }
    else {
        // don't have this user
        ret = 3;
    }
    onWritePackage(USER_Login, "", "", "", ret);
    // onUserLogin   <-Introduction
}

void SocketClient::onAlreadyOnlineStateBack(QString m_name, QString f_name, int state)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    SocketMessage *m_message = SocketMessage::getInstance();
//    QMap<QString, QTcpSocket*>::const_iterator iter;
//    m_message->sendStateToAll(USER_Online_Back, name);

    onWritePackage(USER_Online_Back, m_name, f_name, "", state);
    // onAlreadyOnlineStateBack   <-Introduction
}

void SocketClient::onUserStateChange(QString m_name, int state)
{
    qDebug("[%s] state is [%d]", __PRETTY_FUNCTION__, state);
    SocketMessage *m_message = SocketMessage::getInstance();
    m_message->sendStateToAll(USER_StateChange, m_name, state);

    if (0 == state) {
        m_message->deleteOnlineUser(m_name);
    }
    // onUserStateChange   <-Introduction
}

void SocketClient::onTalkingWithOther(QString name, QString otherUser, QString talkInformation)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString new_information = name + ": " + talkInformation;
    qDebug("[%s] information is: %s", __PRETTY_FUNCTION__, new_information.toStdString().c_str());
    onWritePackage(USER_Talking, otherUser, new_information);
}

/*
 *  onFindNewFriend
 *  Introduction: the name whether is exist in user list ( USER_FindFriend )
 *  ReturnValue: has this name and online (2), has this name and offline (1), not this user (0)
 */
void SocketClient::onFindNewFriend(QString name, int result)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    SocketMessage *m_message = SocketMessage::getInstance();
    int ret = 0;
    UserInformation *user_information = new UserInformation(name, "");

    if (4 == result) {
//        onWritePackage(USER_FindFriend, m_name, );
    }


    if (m_userList->onIsRegisterUser(user_information)) {
        if (m_message->isUserOnline(name)) {
            ret = 2;
        }
        else {
            ret = 1;
        }
    }
    else {
        ret = 0;
    }

    onWritePackage(USER_FindFriend, "", "", "", ret);
    // onFindNewFriend   <-Introduction
}

/*
 *  onQStringChangeToChar
 *  Instruction: change type from QString to char*
 *  ReturnValue: char* text
 */
const char* SocketClient::onQStringChangeToChar(QString b_text)
{
    const char* a_text = b_text.toStdString().data();
    return a_text;
    // onQStringChangeToChar   <-Introduction
}

/*
 *  onCharToQString
 *  Instruction: change type from char* to QString
 *  ReturnValue: QString text
 */
QString SocketClient::onCharToQString(const char *b_text)
{
    QString a_text = QString::fromStdString(b_text);
    return a_text;
    // onCharToQString   <-Introduction
}

void SocketClient::sendOnlineUserToEvery(PackageType head, QString m_name, QTcpSocket* sockfd, int state)
{
    qDebug("[%s] name is [%s]", __PRETTY_FUNCTION__, m_name.toStdString().c_str());
    Package bag = {EMPTY};
    qDebug("[%s] 1111111 socket is [%p]", __PRETTY_FUNCTION__, sockfd);
    bag.head = head;
    bag.result = state;
    strncpy(bag.otherUser, onQStringChangeToChar(m_name), 20);
    qDebug("[%s] 33333 otherName is [%s]", __PRETTY_FUNCTION__, bag.otherUser);
    sockfd->write((char*)(&bag), sizeof(Package));
    qDebug("[%s] 44444 head is [%d]", __PRETTY_FUNCTION__, bag.head);
}
