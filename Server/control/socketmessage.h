#ifndef SOCKETMESSAGE_H
#define SOCKETMESSAGE_H

#include <QObject>
#include <QMap>
#include <iostream>
#include <QtNetwork/QTcpSocket>

#include "control/socketclient.h"

class SocketMessage : public QObject
{
    Q_OBJECT
public:
    static SocketMessage* getInstance();

    void onClientRegist(SocketClient *client);
    bool isUserOnline(QString name);
    void insertOnlineUser(QString, QTcpSocket*);
    void deleteOnlineUser(QString);
    QTcpSocket* onFindSockedByName(QString name);

    void sendStateToAll(PackageType, QString, int);

signals:

public slots:

private:
    explicit SocketMessage(QObject *parent = 0);

    QVector<SocketClient*> vector_clients;
    QMap<QString, QTcpSocket*> map_onlineUser;
    static SocketMessage* instance;
};

#endif // SOCKETMESSAGE_H
