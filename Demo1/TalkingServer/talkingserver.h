#ifndef TALKINGSERVER_H
#define TALKINGSERVER_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QMessageBox>
#include <QThread>
#include <QIcon>

#include "control/clientcontrol.h"
#include "control/socketmessage.h"

#include "model/tablecommon.h"

namespace Ui {
class TalkingServer;
}

class TalkingServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TalkingServer(QWidget *parent = 0);
    ~TalkingServer();

private slots:
    // server create connect
    void onConnection();

    // server button action
    void onDeleteUserClicked();
    void onClearListWork();
    void onExitClicked();

    // get name from list with mouse
    void onGetListUserName(QString);

    // user state change
    void onUserStateChange(QString, int, int);
//    void onUserChangeState(QString, int);

    // user add other friend
    void onUserAddOther(QString, QString);

private:
    Ui::TalkingServer *ui;
    QTcpServer *m_server;
    ClientControl *new_client;
    QString user_name;
    TableCommon *m_tableCommon;
    SocketMessage *m_socketMessage;

    void showAllUser(QString = "", int = 0);
};

#endif // TALKINGSERVER_H
