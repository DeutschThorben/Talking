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
    qDebug("[%s]  socket is [%p]", __PRETTY_FUNCTION__, socked);
    connect(new_client, SIGNAL(UserStateChange(QString, QString)), this, SLOT(onFreshUserList(QString, QString)), Qt::DirectConnection);

    // move new client to one thread
    QThread *thread = new QThread();
    new_client->moveToThread(thread);
    thread->start();
    // onConnection   <-Introduction
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
        a_name = m_userList->onSelectSomeName(ID);

        if ("" != a_name) {
            a_state = m_userList->onSelectSomeState(ID);
            qDebug("[%s], name is [%s] state is [%d]", __PRETTY_FUNCTION__,a_name.toStdString().c_str(), a_state);
            QListWidgetItem *m_qlistItem = new QListWidgetItem(onChangeState(a_state), QObject::tr(a_name.toStdString().c_str()));
            ui->list_user->addItem(m_qlistItem);
        }
    }
    // onShowAllUser   <-Introduction
}

/*
 *  onChangeState
 *  Introduction: user's state change the icon
 *  ReturnValue: State icon of user
 */
QIcon Server::onChangeState(int m_state)
{
    qDebug("[%s], state is [%d]", __PRETTY_FUNCTION__, m_state);
    QIcon m_icon;
    switch (m_state) {
    case 1:
        m_icon = QIcon(QObject::tr(":/new/prefix1/other/online.png"));
        break;
    case 0:
        m_icon = QIcon(QObject::tr(":/new/prefix1/other/offline.png"));
    default:
        break;
    }
    return m_icon;
    // onChangeState   <-Introduction
}

/*
 *  onBtnDeleteClicked
 *  Introduction: delete user from user list
 *  ReturnValue: nothing
 */
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

/*
 *  onBtnExitClicked
 *  Introduction: close server
 *  ReturnValue: nothing
 */
void Server::onBtnExitClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    close();
    // onBtnExitClicked   <-Introduction
}

/*
 *  onGetListText
 *  Introduction: get state of user name
 *  ReturnValue: nothing
 */
void Server::onGetListText(QString list_text)
{
    qDebug("[%s] this list name is [%s]", __PRETTY_FUNCTION__, list_text.toStdString().c_str());
    m_listText = list_text;
    // onBtnDeleteClicked   <-Introduction
}

/*
 *  onFreshUserList
 *  Introduction: fresh user list when someone state has changed
 *  ReturnValue: nothing
 */
void Server::onFreshUserList(QString state, QString name)
{
    qDebug("[%s] state is [%s]", __PRETTY_FUNCTION__, state.toStdString().c_str());
    QString show_text = "";
    if ("Regist" == state) {
        show_text = show_text + "User: " + name + " is resgis already";
    }
    else if ("Login" == state) {
        show_text = show_text + "User: " + name + " is login already";
    }
    else if ("Exit" == state) {
        m_userList->onRemoveUser(name);
        show_text = show_text + "User:" + name + " has exit";
    }
    ui->list_work->addItem(new QListWidgetItem(QObject::tr(show_text.toStdString().c_str())));
        onShowAllUser();
    // onFreshUserList   <-Introduction
}
