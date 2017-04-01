#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QObject>
#include <iostream>
#include <QtNetwork/QTcpSocket>
#include "control/package.h"
#include "control/socketmessage.h"
#include "model/userlist.h"
#include "model/userinformation.h"

class SocketClient : public QObject
{
    Q_OBJECT
public:
    explicit SocketClient(QTcpSocket *socket, QObject *parent = 0);
    ~SocketClient();

    // regist new user
    void onNewUserRegist(QString name, QString keyword);
    // user login
    void onUserLogin(QString name, QString keyword);
    // userName whether is same
    void onWhetherIsSame(QString name);
    // user is talking with other user
    void onTalkingWithOther(QString name, QString otherUser, QString talkInformation);

signals:
    void UserStateChange(QString, QString);

public slots:
    void onReadyRead();

private:
    Package onReadPackage();
    void onWritePackage(PackageType head = EMPTY, QString name = "", QString otherUser = "", QString talkingInformation = "", int result = 0);

    const char* onQStringChangeToChar(QString b_text);
    QString onCharToQString(const char *b_text);

    QTcpSocket *m_socket;
    UserList  *m_userList;
    SocketMessage *m_message;
};

#endif // SOCKETCLIENT_H
