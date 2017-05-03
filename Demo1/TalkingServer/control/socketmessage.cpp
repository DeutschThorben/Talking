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
    // getInstance   <-Introduction
}

/*
 * onAddUserToOnline
 * Introduction: add a online user into map_online
 * Formal parameter: [user's name, user's socket]
 * ReturnValue: nothing
 */
void SocketMessage::onAddUserToOnline(QString n_name, QTcpSocket *n_socket)
{
    qDebug("[%s] remove user is [%s], socket is [%p]", __PRETTY_FUNCTION__, n_name.toStdString().c_str(), n_socket);
    map_onlineUser.insert(n_name, n_socket);
    // onAddUserToOnline   <-Introduction
}

/*
 * onRemoveUserFromOnline
 * Introduction: delete online user from map_online
 * Formal parameter: [user's name]
 * ReturnValue: nothing
 */
void SocketMessage::onRemoveUserFromOnline(QString n_name)
{
    qDebug("[%s] remove user is [%s]", __PRETTY_FUNCTION__, n_name.toStdString().c_str());
    QMap<QString, QTcpSocket*>::iterator iter;
    for (iter = map_onlineUser.begin(); iter != map_onlineUser.end(); ++iter) {
        if (n_name == iter.key()) {
            map_onlineUser.erase(iter);
            break;
        }
    }
    // onRemoveUserFromOnline   <-Introduction
}

/*
 * onSelectSocketByName
 * Introduction: find the socket of online user
 * Formal parameter: [user's name]
 * ReturnValue: the user's socket
 */
QTcpSocket* SocketMessage::onSelectSocketByName(QString n_name)
{
    qDebug("[%s] the name is [%s], socket is [%p]", __PRETTY_FUNCTION__, n_name.toStdString().c_str(), map_onlineUser.value(n_name));
    return map_onlineUser.value(n_name);
    // onSelectStateFromName   <-Introduction
}

void SocketMessage::onSendMessageToEveryone(PackageType head, QString name, QString message, int state)
{
    qDebug("[%s] head is [%d]", __PRETTY_FUNCTION__, head);
    QMap<QString, QTcpSocket*>::iterator iter;
    for (iter = map_onlineUser.begin(); iter != map_onlineUser.end(); ++iter) {
        qDebug("[%s] name is [%s],  socket is [%p]", __PRETTY_FUNCTION__, iter.key().toStdString().c_str(), iter.value());
        if (name != iter.key()) {
            emit onSendToEveryone(iter.key(), iter.value());
        }
    }
    // onSendMessageToEveryone   <-Introduction
}

/*
 * onAddUserToState
 * Introduction: add a online user into map_state
 * Formal parameter: [user's name, user's state (online)]
 * ReturnValue: nothing
 */
void SocketMessage::onAddUserToState(QString n_name, int n_state)
{
    qDebug("[%s] the name is [%s], the state is [%d]", __PRETTY_FUNCTION__, n_name.toStdString().c_str(), n_state);
    map_userState.insert(n_name, n_state);
    QMap<QString, int>::iterator iter;
    for (iter = map_userState.begin(); iter != map_userState.end(); ++iter) {
        qDebug("[%s] the name is [%s], the state is [%d]", __PRETTY_FUNCTION__, iter.key().toStdString().c_str(), iter.value());

    }
    // onAddUserToState   <-Introduction
}

/*
 * onChangeState
 * Introduction: change the user's state
 * Formal parameter: [user's name, will change the state]
 * ReturnValue: nothing
 */
void SocketMessage::onChangeState(QString n_name, int n_state)
{
    qDebug("[%s] the name is [%s], change state is [%d]", __PRETTY_FUNCTION__, n_name.toStdString().c_str(), n_state);
    QMap<QString, int>::iterator iter;
    for (iter = map_userState.begin(); iter != map_userState.end(); ++iter) {
        if (n_name == iter.key()) {
            iter.value() = n_state;
            break;
        }
    }
    // onChangeState   <-Introduction
}

/*
 * onSelectStateByName
 * Introduction: get some user's state
 * Formal parameter: [select name]
 * ReturnValue: this user's state
 */
int SocketMessage::onSelectStateByName(QString n_name)
{
    qDebug("[%s] the name is [%s]", __PRETTY_FUNCTION__, n_name.toStdString().c_str());
    QMap<QString, int>::iterator iter;
    for (iter = map_userState.begin(); iter != map_userState.end(); iter++) {
        if (n_name == iter.key()) {
            return iter.value();
        }
    }
    return state_offline;
    // onSelectStateByName   <-Introduction
}

/*
 * onRemoveUserFromState
 * Introduction: user exit and delete user in map_state
 * Formal parameter: [want to delete user's name]
 * ReturnValue: nothing
 */
void SocketMessage::onRemoveUserFromState(QString n_name)
{
    qDebug("[%s] remove user is [%s]", __PRETTY_FUNCTION__, n_name.toStdString().c_str());
    QMap<QString, int>::iterator iter;
    for (iter = map_userState.begin(); iter != map_userState.end(); ++iter) {
        qDebug("[%s] user is [%s]", __PRETTY_FUNCTION__, iter.key().toStdString().c_str());
        if (n_name == iter.key()) {
            map_userState.erase(iter);
            break;
        }
    }
    // onRemoveUserFromState   <-Introduction
}

/*
 * onChangeStateToIcon
 * Introduction: get the name from user list
 * Formal parameter: choose the name from user list
 * ReturnValue: state of icon
 */
QIcon SocketMessage::onChangeStateToIcon(int n_state)
{
    qDebug("[%s] state is [%d]", __PRETTY_FUNCTION__, n_state);
    QIcon state_icon;

    switch (n_state) {
    case state_online:
        state_icon = QIcon(QObject::tr(":/new/userState/picture/online.png"));
        break;
    case state_offline:
        state_icon = QIcon(QObject::tr(":/new/userState/picture/offline.png"));
        break;
    case state_hiding:
        state_icon = QIcon(QObject::tr(":/new/userState/picture/hiding.png"));
        break;
    case state_NotOffline:
        state_icon = QIcon(QObject::tr(":/new/userState/picture/notOffline.png"));
        break;
    default:
        break;
    }
    return state_icon;
    // onChangeStateToIcon   <-Introduction
}


