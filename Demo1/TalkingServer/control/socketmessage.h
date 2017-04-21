#ifndef SOCKETMESSAGE_H
#define SOCKETMESSAGE_H

#include <QObject>
#include <QMap>
#include <QIcon>
#include <QTcpSocket>

enum user_state {
    state_offline = 0,
    state_online,
    state_hiding,
    nothing
};

class SocketMessage : public QObject
{
    Q_OBJECT
public:
    explicit SocketMessage(QObject *parent = 0);


    /// action of online map
    // user is loading and state is online
    void onAddUserToOnline(QString, QTcpSocket*);
    // user exit
    void onRemoveUserFromOnline(QString);
    // find socket of name
    QTcpSocket* onSelectSocketByName(QString);

    /// action of state map
    // when user has loaded
    void onAddUserToState(QString, int);
    // user change state of himself
    void onChangeState(QString, int);
    // get some user's state
    int onSelectStateByName(QString);
    // when user exit
    void onRemoveUserFromState(QString);

    // change user's state from int to icon
    QIcon onChangeStateToIcon(int);

signals:

public slots:

private:
    QMap<QString, int> map_userState;
    QMap<QString, QTcpSocket*> map_onlineUser;

};

#endif // SOCKETMESSAGE_H
