#ifndef CLIENTCONTROL_H
#define CLIENTCONTROL_H

#include <QObject>

#include "control/socketmessage.h"

#include "model/servercommon.h"
#include "model/tablecommon.h"
#include "model/friendcommon.h"

enum result_Action {
    result_Failure = 0,
    result_Success,
    result_HasName,
    result_NotFindName,
    result_KeywordMistake,
    result_WhetherAgreeFriend,
    result_AgreeFriend,
    result_WantFriend,
    result_alreadyLoading
};

class ClientControl : public QObject
{
    Q_OBJECT
public:
    explicit ClientControl(QTcpSocket *sockfd, SocketMessage *socketMessage, QObject *parent = 0);
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
    void onFindNewFriend(QString, QString, int);

    // send my state to everyone
    void onSendMyStateToFriend(QString, int);

    // create a new friend list
    void onCreateAFriendList(QString);

    // user's state change
    void onClientStateChange(QString, int);

    void onGetFriendList(QString, QTcpSocket*);

signals:
    // user add or delete
    void onUserStateChange(QString, int, int);
    // user add friend success
    void onUserFriendAdd(QString, QString);
    // user's state change
//    void onUserChangeState(QString, int);

public slots:
    void onPackageRead();

    void onFriendListToEveryone(QString, QTcpSocket*);

private:
    QTcpSocket *m_socket;
    SocketMessage *m_socketMessage;
    ServerCommon *m_serverCommon;
    TableCommon *m_tableCommon;
    FriendCommon *m_friendCommon;

};

#endif // CLIENTCONTROL_H
