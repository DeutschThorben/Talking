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
    qDebug("[%s] name is [%s], socket is [%p]", __PRETTY_FUNCTION__, name.toStdString().c_str(), socket);
    map_onlineUser.insert(name, socket);
    // insertOnlineUser   <-Introduction
}

void SocketMessage::deleteOnlineUser(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QMap<QString, QTcpSocket*>::iterator iter;
    for (iter = map_onlineUser.begin(); iter != map_onlineUser.end(); ++iter) {
        qDebug("[%s] %s", __PRETTY_FUNCTION__, iter.key().toStdString().c_str());
        if (name == iter.key()) {
            map_onlineUser.erase(iter);
            break;
        }
    }
    // deleteOnlineUser   <-Introduction
}

bool SocketMessage::isUserOnline(QString name)
{
    qDebug("[%s] name is [%s]", __PRETTY_FUNCTION__, name.toStdString().c_str());
    QMap<QString, QTcpSocket*>::const_iterator iter;
    for (iter = map_onlineUser.constBegin(); iter != map_onlineUser.constEnd(); ++iter) {
        qDebug("[%s] %s", __PRETTY_FUNCTION__, iter.key().toStdString().c_str());
        if (name == iter.key()) {
            qDebug("[%s]", __PRETTY_FUNCTION__);
            return true;
        }
    }
    return false;
    // isUserOnline   <-Introduction
}

QTcpSocket* SocketMessage::onFindSockedByName(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QTcpSocket *tmp = map_onlineUser.value(name);
    qDebug("[%s] tmp is [%p]", __PRETTY_FUNCTION__, tmp);
    return map_onlineUser.value(name);
}

void SocketMessage::sendStateToAll(PackageType head, QString name, int state)
{
    qDebug("[%s] name is [%s]", __PRETTY_FUNCTION__, name.toStdString().c_str());

    QMap<QString, QTcpSocket*>::const_iterator iter;
    for (iter = map_onlineUser.constBegin(); iter != map_onlineUser.constEnd(); ++iter) {
        qDebug("[%s] socket is [%p]", __PRETTY_FUNCTION__, iter.value());
        qDebug("[%s] name is [%s]", __PRETTY_FUNCTION__, iter.key().toStdString().c_str());
        SocketClient* m_socketClient = new SocketClient(iter.value());
        m_socketClient->sendOnlineUserToEvery(head, name, iter.value(), state);
        qDebug("[%s] 22222", __PRETTY_FUNCTION__);
//        return iter;
    }
}
