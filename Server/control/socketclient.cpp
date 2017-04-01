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

    QString m_name = onCharToQString(bag.name);
    QString m_keyword = onCharToQString(bag.keyword);
    QString m_otherUser = onCharToQString(bag.otherUser);
    QString m_talkInformation = onCharToQString(bag.talkingInformation);

    switch (bag.head) {
    case USER_Regist:
        qDebug("[%s] Client is registing", __PRETTY_FUNCTION__);
        onNewUserRegist(m_name, m_keyword);
        break;
    case USER_Login:
        qDebug("[%s] Client is loading", __PRETTY_FUNCTION__);
        onUserLogin(m_name, m_keyword);
        break;
    case USER_Regist_IsSameName:
        qDebug("[%s] ", __PRETTY_FUNCTION__);
        onWhetherIsSame(m_name);
        break;
    case USER_Talking:
        qDebug("[%s] Client is talking with other", __PRETTY_FUNCTION__);
        onTalkingWithOther(m_name, m_otherUser, m_talkInformation);
        break;
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

    QTcpSocket *sockfd = m_message->onFindSockedByName(name);

    if ((NULL != sockfd) && (m_socket != sockfd)) {
        // talking with other
        qDebug("[%s] send message to other", __PRETTY_FUNCTION__);
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
        ret = 0;
        emit UserStateChange("Regist", name);
    }
    else {
        // user register failure
        ret = 1;
    }

    qDebug("[%s] take the bag to client about regist", __PRETTY_FUNCTION__);
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
        qDebug("[%s]dddd", __PRETTY_FUNCTION__);
        ret = 1;
    }
    else {
        qDebug("[%s]eeee", __PRETTY_FUNCTION__);
        ret = 0;
    }

    qDebug("[%s] ret = [%d]", __PRETTY_FUNCTION__, ret);
    onWritePackage(USER_Regist_IsSameName, "", "", "", ret);
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
    if (m_message->isUserOnline(name)) {
        // this user is logined already
        ret = 2;
    }
    else {
        if (m_userList->onLoginUser(name, keyword)) {
            // user login success
            ret = 1;
            emit UserStateChange("Login", name);
        }
        else {
            // user login failure
            ret = 0;
        }
    }
    onWritePackage(USER_Login, "", "", "", ret);
    // onUserLogin   <-Introduction
}

void SocketClient::onTalkingWithOther(QString name, QString otherUser, QString talkInformation)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString new_information = name + ": " + talkInformation;
    qDebug("[%s] information is: %s", __PRETTY_FUNCTION__, new_information.toStdString().c_str());
    onWritePackage(USER_Talking, otherUser, new_information);
}

/*
 *  onQStringChangeToChar
 *  Instruction: change type from QString to char*
 *  ReturnValue: char* text
 */
const char* SocketClient::onQStringChangeToChar(QString b_text)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
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
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString a_text = QString::fromStdString(b_text);
    return a_text;
    // onCharToQString   <-Introduction
}
