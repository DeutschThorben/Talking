#ifndef CLIENTCONTROL_H
#define CLIENTCONTROL_H

#include <QObject>

#include "control/socketmessage.h"

#include "model/servercommon.h"
#include "model/tablecommon.h"

enum result_Action {
    result_Failure = 0,
    result_Success,
    result_NotFindName,
    result_KeywordMistake
};

class ClientControl : public QObject
{
    Q_OBJECT
public:
    explicit ClientControl(QTcpSocket *sockfd, QObject *parent = 0);
    ~ClientControl();

    // regist
    void onNewUserRegist(QString, QString);
    // login
    void onUserLoading(QString, QString, int);
    // talking with other
    void onUserTalkingWithOther(QString, QString, QString);
    // talking with all
    void onUserTalkingInMasses(QString, QString);
    // judge the name is been used
    void onIsTheNameHasBeenUsed(QString);
    // add other with friend
    void onFindNewFriend(QString);

    // send my state to everyone
    void onSendMyStateToFriend(QString, int);

signals:
    void onUserStateChange(QString, QString);

public slots:
    void onPackageRead();

private:
    QTcpSocket *m_socket;

    ServerCommon *m_serverCommon;
    TableCommon *m_tableCommon;
    SocketMessage *m_socketMessage;
};

#endif // CLIENTCONTROL_H
