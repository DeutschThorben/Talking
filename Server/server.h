#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QThread>
#include "control/socketclient.h"
#include "control/socketmessage.h"

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

private:
    Ui::Server *ui;
    QTcpServer *m_server;
};

#endif // SERVER_H
