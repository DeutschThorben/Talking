#include "socketmessage.h"

SocketMessage* SocketMessage::instance = NULL;

SocketMessage::SocketMessage(QObject *parent) : QObject(parent)
{

}

SocketMessage* SocketMessage::getInstance()
{
    if (NULL == instance) {
        instance = new SocketMessage();
    }
    return instance;
}

/*
 *  onClientRegist
 *  Introduction: push online user into vector (not always maybe registered)
 *  ReturnValue: nothing
 */
void SocketMessage::onClientRegist(SocketClient *client)
{
    vector_clients.push_back(client);
    // onClientRegist   <-Introduction
}

void SocketMessage::insertOnlineUser(QString name, QTcpSocket *socket)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    map_onlineUser.insert(name, socket);
}

bool SocketMessage::isUserOnline(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QMap<QString, QTcpSocket*>::const_iterator iter;
    for (iter = map_onlineUser.constBegin(); iter != map_onlineUser.constEnd(); ++iter) {
        qDebug("[%s] %s", __PRETTY_FUNCTION__, iter.key().toStdString().c_str());
        if (name == iter.key()) {
            return true;
        }
    }
    return false;
}

QTcpSocket* SocketMessage::onFindSockedByName(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QTcpSocket *tmp = map_onlineUser.value(name);
    qDebug("[%s] tmp is [%d]", __PRETTY_FUNCTION__, tmp);
    return map_onlineUser.value(name);
}

void SocketMessage::sendStateToAll(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QMap<QString, QTcpSocket*>::const_iterator iter;
    for (iter = map_onlineUser.constBegin(); iter != map_onlineUser.constEnd(); ++iter) {
        ((SocketClient*)(*iter))->sendOnlineUserToEvery(name, iter.value());
    }
}
