#include "servercommon.h"

ServerCommon::ServerCommon(QObject *parent) : QObject(parent)
{

}

/*
 * onWriteToClient
 * Introduction: send the package to client
 * Formal parameter: [the information of package]
 * ReturnValue: nothing
 */
void ServerCommon::onWriteToClient(PackageType head, int result, QString name, QString keyword, QString otherUser, QString message)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    Package bag;

    bag.head = head;
    bag.result = result;
    strncpy(bag.name, onQStringToChar(name), 20);
    strncpy(bag.keyword, onQStringToChar(keyword), 10);
    strncpy(bag.otherUser, onQStringToChar(otherUser), 20);
    strncpy(bag.message, onQStringToChar(message), 60);

    qDebug("[%s] head is [%d]", __PRETTY_FUNCTION__, bag.head);
    qDebug("[%s] bag.name is [%s]", __PRETTY_FUNCTION__, bag.name);
    qDebug("[%s] bag.keyword is [%s]", __PRETTY_FUNCTION__, bag.keyword);
    qDebug("[%s] bag.otherUser is [%s]", __PRETTY_FUNCTION__, bag.otherUser);
    qDebug("[%s] result is [%d]", __PRETTY_FUNCTION__, bag.result);

    QTcpSocket *m_socket = m_message->onSelectSocketByName(otherUser);
    if ((NULL != m_socket) && (m_socket != m_sockfd)) {
        qDebug("[%s] send the package to other", __PRETTY_FUNCTION__);
        m_socket->write((char*)(&bag), sizeof(Package));
    }
    else {
        qDebug("[%s] send the package to myself", __PRETTY_FUNCTION__);
        m_sockfd->write((char*)(&bag), sizeof(Package));
    }
    // onWriteToClient   <-Introduction
}

/*
 * onReadPackageFromClient
 * Introduction: get the package from client
 * Formal parameter: nothing
 * ReturnValue: package from client
 */
Package ServerCommon::onReadPackageFromClient()
{
    Package bag;
    m_sockfd->read((char*)(&bag), sizeof(Package));
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    return bag;
    // onReadPackageFromClient   <-Introduction
}

/*
 * onCharToQString
 * Introduction: change the type of word about char to QString
 * Formal parameter: [word of char]
 * ReturnValue: word of QString
 */
QString ServerCommon::onCharToQString(const char *before_word)
{
    QString after_word = QString::fromStdString(before_word);
    return after_word;
    // onCharToQString   <-Introduction
}

/*
 * onQStringToChar
 * Introduction: change the type of word about QString to char
 * Formal parameter: [word of QString]
 * ReturnValue: word of char*
 */
const char* ServerCommon::onQStringToChar(QString before_word)
{
    const char* after_word = before_word.toStdString().data();
    return after_word;
    // onQStringToChar   <-Introduction
}

/*
 * onSetMySocket
 * Introduction: get the server socket of the client
 * Formal parameter: [server socket of client]
 * ReturnValue: nothing
 */
void ServerCommon::onSetMySocket(QTcpSocket *m_socket)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    m_sockfd = m_socket;
    // onSetMySocket   <-Introduction
}

void ServerCommon::onSetSocketMessage(SocketMessage *m_socketMessage)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    m_message = m_socketMessage;
    // onSetSocketMessage   <-Introduction
}
