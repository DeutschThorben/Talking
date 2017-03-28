#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    m_server = new QTcpServer();

    if (!m_server->isListening()) {
        m_server->listen(QHostAddress::Any, 1024);
        ui->textEdit_work->setText("Server is working start");
    }
    else {
        return;
    }

    connect(m_server, SIGNAL(newConnection()), this, SLOT(onConnection()));
}

Server::~Server()
{
    disconnect(m_server, SIGNAL(newConnection()), this, SLOT(onConnection()));
    delete ui;
}

void Server::onConnection()
{
    QTcpSocket *socked = m_server->nextPendingConnection();
    SocketClient *new_client = new SocketClient(socked);
    // SocketMessage *message = SocketMessage::getInstance();
    // message->onClientRegist(new_client);

    // move new client to one thread
    QThread *thread = new QThread();
    new_client->moveToThread(thread);
    thread->start();

    ui->textEdit_work->setText("A client is connected");
}
