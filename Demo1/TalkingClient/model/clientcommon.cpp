#include "clientcommon.h"

ClientCommon::ClientCommon(QObject *parent) : QObject(parent)
{

}

/*
 * onReadPackageFromServer
 * Instruction: read package from server
 * Formal parameter: nothing
 * ReturnValue: bag information of server
 */
Package ClientCommon::onReadPackageFromServer()
{
    Package bag = {EMPTY};
    u_socket->read((char*)(&bag), sizeof(Package));

    qDebug("[%s] bag.head is [%d]", __PRETTY_FUNCTION__, bag.head);
    qDebug("[%s] bag.result is [%d]", __PRETTY_FUNCTION__, bag.result);
    qDebug("[%s] bag.name is [%s]", __PRETTY_FUNCTION__, bag.name);
    qDebug("[%s] bag.keyword is [%s]", __PRETTY_FUNCTION__, bag.keyword);
    qDebug("[%s] bag.otherUser is [%s]", __PRETTY_FUNCTION__, bag.otherUser);
    qDebug("[%s] bag.message is [%s]", __PRETTY_FUNCTION__, bag.message);

    return bag;
    // onReadPackageFromServer   <-Introduction
}

/*
 * onWritePackageToServer
 * Instruction: send information to server in package
 * Formal parameter: [information of package about send to server]
 * ReturnValue: nothing
 */
void ClientCommon::onWritePackageToServer(PackageType head, int result, QString name, QString keyword, QString otherUser, QString message)
{
    qDebug("[%s] socket is [%p]", __PRETTY_FUNCTION__, u_socket);
    Package bag = {EMPTY};
    bag.head = head;
    bag.result = result;

    strncpy(bag.name, onQStringChangeToChar(name), 20);
    strncpy(bag.keyword, onQStringChangeToChar(keyword), 10);
    strncpy(bag.otherUser, onQStringChangeToChar(otherUser), 20);
    strncpy(bag.message, onQStringChangeToChar(message), 60);

    u_socket->write((char*)(&bag), sizeof(Package));
    // onWritePackageToServer   <-Introduction
}

/*
 * onSetSocket
 * Instruction: get socket of client
 * Formal parameter: [socket of client]
 * ReturnValue: nothing
 */
void ClientCommon::onSetSocket(QTcpSocket *sockfd)
{
    qDebug("[%s] socket is [%p]", __PRETTY_FUNCTION__, sockfd);
    u_socket = sockfd;
    // onSetSocket   <-Introduction
}

/*
 * onGetSocket
 * Instruction: get socket to client
 * Formal parameter: nothing
 * ReturnValue: socket of client
 */
QTcpSocket* ClientCommon::onGetSocket()
{
    qDebug("[%s] socket is [%p]", __PRETTY_FUNCTION__, u_socket);
    return u_socket;
    // onGetSocket   <-Introduction
}

/*
 * onQStringChangeToChar
 * Instruction: change type from QString to char*
 * Formal parameter: [change text of QString]
 * ReturnValue: char* text
 */
const char* ClientCommon::onQStringChangeToChar(QString b_text)
{
    const char* a_text = b_text.toStdString().data();
    return a_text;
    // onQStringChangeToChar   <-Introduction
}

/*
 * onCharToQString
 * Instruction: change type from char* to QString
 * Formal parameter: [change text of char*]
 * ReturnValue: QString text
 */
QString ClientCommon::onCharToQString(char *b_text)
{
    QString a_text = QString::fromStdString(b_text);
    return a_text;
    // onCharToQString   <-Introduction
}
