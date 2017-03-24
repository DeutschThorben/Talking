#include "socketclient.h"

SocketClient::SocketClient(QTcpSocket *socket, QObject *parent) : QObject(parent), m_socket(socket)
{
    m_userList = new UserList();
    m_message = SocketMessage::getInstance();
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

SocketClient::~SocketClient()
{
    delete m_userList;
    m_userList = NULL;

    delete m_message;
    m_message = NULL;
}

void SocketClient::onReadyRead()
{
    Package bag = onReadPackage();
    switch (bag.head) {
    case USER_Regist:
        onNewUserRegist(bag.name, bag.keyword);
        break;
    case USER_Login:
        onUserLogin(bag.name, bag.keyword);
        break;
    case USER_Talking:
        onTalkingWithOther(bag.name, bag.otherUser, bag.talkingInformation);
        break;
    default:
        break;
    }
}

/*
 *  onReadPackage
 *  Introduction: get news from client
 *  ReturnValue: package from client
 */
Package SocketClient::onReadPackage()
{
    Package bag = {EMPTY};
    m_socket->read((char*)(&bag), sizeof(Package));
    return bag;
    // onReadPackage   <-Introduction
}

/*
 *  onWritePackage
 *  Introduction: take the package from server to client
 *  ReturnValue: nothing
 */
void SocketClient::onWritePackage(PackageType head, QString name, QString talkingInformation, int result)
{
    Package bag = {EMPTY};
    bag.head = head;
    bag.name = name;
    bag.talkingInformation = talkingInformation;
    bag.result = result;

    QTcpSocket *sockfd = m_message->onFindSockedByName(name);

    if (m_socket != sockfd) {
        // talking with other
        sockfd->write((char*)(&bag), sizeof(Package));
    }
    else {
        // feedback client
        m_socket->write((char*)(&bag), sizeof(Package));
    }
    // onWritePackage   <-Introduction
}

/*
 *  onNewUserRegist
 *  Introduction: client regist new user
 *  ReturnValue: have same username already (2), register success (1), register failure (0)
 */
void SocketClient::onNewUserRegist(QString name, QString keyword)
{
    int ret = 0;
    UserInformation *user_information = new UserInformation(name, keyword);

    if (m_userList->onIsRegisterUser(user_information)) {
        // this username is registered already
        ret = 2;
    }
    else{
        if (m_userList->onAddUser(user_information)) {
            // user register success
            ret = 1;
        }
        else {
            // user register failure
            ret = 0;
        }
    }
    onWritePackage(USER_Regist, "", "", ret);
    // onNewUserRegist   <-Introduction
}

/*
 *  onUserLogin
 *  Introduction: client user login
 *  ReturnValue: login success (1), login failure (0), user login already (2)
 */
void SocketClient::onUserLogin(QString name, QString keyword)
{
    int ret = 0;
    UserInformation *user_information = new UserInformation(name, keyword);
    if (m_message->isUserOnline(name)) {
        // this user is logined already
        ret = 2;
    }
    else {
        if (m_userList->onLoginUser(user_information)) {
            // user login success
            ret = 1;
        }
        else {
            // user login failure
            ret = 0;
        }
    }
    onWritePackage(USER_Login, "", "", ret);
    // onUserLogin   <-Introduction
}

void SocketClient::onTalkingWithOther(QString name, QString otherUser, QString talkInformation)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString new_information = name + ": " + talkInformation;
    qDebug("[%s] information is: %s", __PRETTY_FUNCTION__, new_information.toStdString().c_str());
    onWritePackage(USER_Talking, otherUser, new_information);
}
