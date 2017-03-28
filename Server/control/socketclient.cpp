#include "socketclient.h"

SocketClient::SocketClient(QTcpSocket *socket, QObject *parent) : QObject(parent), m_socket(socket)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
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
    qDebug("[%s] PackageType is [%d]", __PRETTY_FUNCTION__, bag.head);
    switch (bag.head) {
    case USER_Regist:
        qDebug("[%s]1111", __PRETTY_FUNCTION__);
        onNewUserRegist(bag.name, bag.keyword);
        qDebug("[%s]2222", __PRETTY_FUNCTION__);
        break;
    case USER_Login:
        qDebug("[%s]3333", __PRETTY_FUNCTION__);
        onUserLogin(bag.name, bag.keyword);
        break;
    case USER_Login_IsSameName:
        onWhetherIsSame(bag.name);
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
    }
    else {
        // user register failure
        ret = 0;
    }

    qDebug("[%s] take the bag to client about regist", __PRETTY_FUNCTION__);
    onWritePackage(USER_Regist, "", "", ret);
    // onNewUserRegist   <-Introduction
}

/*
 *  onWhetherIsSame
 *  Introduction: judged username whether is same ( USER_Login_IsSameName )
 *  ReturnValue: The name is same (1), not same (0)
 */
void SocketClient::onWhetherIsSame(QString name)
{
    int ret = 0;
    UserInformation *user_information = new UserInformation(name, "");
    if (m_userList->onIsRegisterUser(user_information)) {
        ret = 1;
    }
    else {
        ret = 0;
    }

    onWritePackage(USER_Regist, "", "", ret);
    // onWhetherIsSame   <-Introduction
}

/*
 *  onUserLogin
 *  Introduction: client user login ( USER_Login )
 *  ReturnValue: login success (1), login failure (0), user login already (2)
 */
void SocketClient::onUserLogin(QString name, QString keyword)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
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
