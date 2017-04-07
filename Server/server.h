#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QListWidget>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QThread>
#include <QIcon>
#include <QMessageBox>

#include "control/socketclient.h"
#include "control/socketmessage.h"

#include "model/userlist.h"

using namespace::std;

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

public slots:
    void onConnection();

    void onBtnDeleteClicked();
    void onBtnExitClicked();

    void onFreshUserList(QString state, QString name);

    void onGetListText(QString list_text);
    void onUserExit(QString);

private:
    Ui::Server *ui;
    QTcpServer *m_server;
    SocketClient *new_client;

    UserList *m_userList;
    QString m_listText;

    void onShowAllUser();
    QIcon onChangeState(int m_state);

};

#endif // SERVER_H
