#include "server.h"
#include "ui_server.h"
#include <QColor>
#include <QColorDialog>

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    m_server = new QTcpServer();
    m_userList = new UserList();

    if (!m_server->isListening()) {
        m_server->listen(QHostAddress::Any, 1024);
    }
    else {
        return;
    }

    // show the all user list
    onShowAllUser();

    connect(m_server, SIGNAL(newConnection()), this, SLOT(onConnection()));

    connect(ui->btn_delete, SIGNAL(clicked()), this, SLOT(onBtnDeleteClicked()));
    connect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onBtnExitClicked()));
    connect(ui->list_user, SIGNAL(currentTextChanged(QString)), this, SLOT(onGetListText(QString)));
}

Server::~Server()
{
    disconnect(m_server, SIGNAL(newConnection()), this, SLOT(onConnection()));
    disconnect(new_client, SIGNAL(UserStateChange(QString, QString)), this, SLOT(onFreshUserList(QString, QString)));

    disconnect(ui->btn_delete, SIGNAL(clicked()), this, SLOT(onBtnDeleteClicked()));
    disconnect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onBtnExitClicked()));
    disconnect(ui->list_user, SIGNAL(currentTextChanged(QString)), this, SLOT(onGetListText(QString)));

    delete ui;
}

void Server::onConnection()
{
    QTcpSocket *socked = m_server->nextPendingConnection();
    new_client = new SocketClient(socked);
    // SocketMessage *message = SocketMessage::getInstance();
    // message->onClientRegist(new_client);
    connect(new_client, SIGNAL(UserStateChange(QString, QString)), this, SLOT(onFreshUserList(QString, QString)));

    // move new client to one thread
    QThread *thread = new QThread();
    new_client->moveToThread(thread);
    thread->start();
}

/*
 *  onShowAllUser
 *  Introduction: show all user in list
 *  ReturnValue: nothing
 */
void Server::onShowAllUser()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->list_user->clear();
    QString a_name;
    int table_maxID = m_userList->onMaxID();
    int a_state;

    // push all user in server list from table
    for (int ID = 1; ID <= table_maxID; ID++) {
        a_state = m_userList->onSelectSomeState(ID);
        a_name = m_userList->onSelectSomeName(ID);

        if ("" != a_name) {
            QListWidgetItem *m_qlistItem = new QListWidgetItem(onChangeState(a_state), QObject::tr(a_name.toStdString().c_str()));
            ui->list_user->addItem(m_qlistItem);
            qDebug("[%s] name [%d] is [%s]", __PRETTY_FUNCTION__, ID, a_name.toStdString().c_str());
        }
    }
//    ui->list_user->sortItems();
    // onShowAllUser   <-Introduction
}

QIcon Server::onChangeState(int m_state)
{
    QIcon m_icon;
    switch (m_state) {
    case 1:
        m_icon = QIcon(QObject::tr("other/online.png"));
        break;
    case 0:
        m_icon = QIcon(QObject::tr("other/offline.png"));
    default:
        break;
    }
    return m_icon;
}

void Server::onBtnDeleteClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    QString tmp = "Are you sure to delete the user by name of " + m_listText + " ?";
    QMessageBox::StandardButton message = QMessageBox::question(NULL, "Remind", tmp, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (QMessageBox::Yes == message) {
        m_userList->onDeleteUser(m_listText);
    }
    else {

    }

    // fresh user list
    onShowAllUser();

    // onBtnDeleteClicked   <-Introduction
}

void Server::onBtnExitClicked()
{
    close();
}

void Server::onGetListText(QString list_text)
{
    qDebug("[%s] this list name is [%s]", __PRETTY_FUNCTION__, list_text.toStdString().c_str());
    m_listText = list_text;
    // onBtnDeleteClicked   <-Introduction
}

void Server::onFreshUserList(QString state, QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    onShowAllUser();

    QString show_text = "";

    if ("Regist" == state) {
        show_text = show_text + "User: " + name + " is resgis already";
    }
    else if ("Login" == state) {
        show_text = show_text + "User: " + name + " is login already";
    }
    ui->list_work->addItem(new QListWidgetItem(QObject::tr(show_text.toStdString().c_str())));
    // onFreshUserList   <-Introduction
}
