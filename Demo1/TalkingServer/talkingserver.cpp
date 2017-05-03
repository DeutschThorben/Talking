#include "talkingserver.h"
#include "ui_talkingserver.h"

TalkingServer::TalkingServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TalkingServer)
{
    ui->setupUi(this);

    m_server = new QTcpServer();
    m_tableCommon = new TableCommon();
    m_socketMessage = SocketMessage::getInstance();

    if (!m_server->isListening()) {
        m_server->listen(QHostAddress::Any, 1024);
    }
    else {
        return;
    }

    // fresh user list
    showAllUser();

    // get new connect signal
    connect(m_server, SIGNAL(newConnection()), this, SLOT(onConnection()));

    // button click signal
    connect(ui->btn_delete, SIGNAL(clicked()), this, SLOT(onDeleteUserClicked()));
    connect(ui->btn_empty, SIGNAL(clicked(bool)), this, SLOT(onClearListWork()));
    connect(ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(onExitClicked()));

    // get name from list
    connect(ui->list_user, SIGNAL(currentTextChanged(QString)), this, SLOT(onGetListUserName(QString)));
}

TalkingServer::~TalkingServer()
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    disconnect(m_server, SIGNAL(newConnection()), this, SLOT(onConnection()));
    disconnect(ui->btn_delete, SIGNAL(clicked()), this, SLOT(onDeleteUserClicked()));
    disconnect(ui->btn_empty, SIGNAL(clicked(bool)), this, SLOT(onClearListWork()));
    disconnect(ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(onExitClicked()));
    disconnect(ui->list_user, SIGNAL(currentTextChanged(QString)), this, SLOT(onGetListUserName(QString)));
    disconnect(new_client, SIGNAL(onUserStateChange(QString, int, int)), this, SLOT(onUserStateChange(QString,int, int)));
    disconnect(new_client, SIGNAL(onUserFriendAdd(QString,QString)), this, SLOT(onUserAddOther(QString,QString)));
//    disconnect(new_client, SIGNAL(onUserChangeState(QString, int)), this, SLOT(onUserChangeState(QString, int)));

    delete ui;
}

/*
 * onConnection
 * Introduction: create new thread and lientControl for new connection
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingServer::onConnection()
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    QTcpSocket *new_socket = m_server->nextPendingConnection();
    new_client = new ClientControl(new_socket, m_socketMessage);
    qDebug("[%s] new socket is [%p], socketMessage is [%p]", __PRETTY_FUNCTION__, new_socket, m_socketMessage);

    // accept state change signal from clientcontrol
    connect(new_client, SIGNAL(onUserStateChange(QString, int, int)), this, SLOT(onUserStateChange(QString,int, int)), Qt::DirectConnection);
    connect(new_client, SIGNAL(onUserFriendAdd(QString,QString)), this, SLOT(onUserAddOther(QString,QString)), Qt::DirectConnection);
//    connect(new_client, SIGNAL(onUserChangeState(QString, int)), this, SLOT(onUserChangeState(QString, int)), Qt::DirectConnection);

    // move new client to a thread
    QThread *new_thread = new QThread();
    new_client->moveToThread(new_thread);
    new_thread->start();
    // onConnection   <-Introduction
}

/*
 * onDeleteUserClicked
 * Introduction: delete choose user from user table
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingServer::onDeleteUserClicked()
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);

    QString word = "Are you sure to delet this user [ " + user_name + " ] from server ?";
    QMessageBox::StandardButton message = QMessageBox::question(NULL, "Please make sure", word, QMessageBox::Yes|QMessageBox::No, QMessageBox::No);
    if (QMessageBox::Yes == message) {
        m_tableCommon->onDeleteUser(user_name);
        QMessageBox message(QMessageBox::NoIcon, "Result", "Delete success", QMessageBox::Ok);
        message.exec();
    }

    // fresh user list
    showAllUser();
    // onDeleteUserClicked   <-Introduction
}

/*
 * onClearListWork
 * Introduction: clear the list of work message
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingServer::onClearListWork()
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    ui->list_message->clear();
    // onClearListWork   <-Introduction
}

/*
 * onExitClicked
 * Introduction: close server
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingServer::onExitClicked()
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    close();
    // onExitClicked   <-Introduction
}

/*
 * onGetListUserName
 * Introduction: get the name from user list
 * Formal parameter: [choose the name from user list]
 * ReturnValue: nothing
 */
void TalkingServer::onGetListUserName(QString n_name)
{
    qDebug("[%s] Get name is [%s]", __PRETTY_FUNCTION__, n_name.toStdString().c_str());
    user_name = n_name;
    // onGetListUserName   <-Introduction
}

/*
 * showAllUser
 * Introduction: show all user and them state to the server list
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingServer::showAllUser(QString name, int state)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    ui->list_user->clear();
    int table_maxID = m_tableCommon->onGetMaxID();
    QString a_name;
    int a_state = 0;

    for (int ID = 1; ID <= table_maxID; ID++) {
        a_name = m_tableCommon->onSelectNameForID(ID);
        if ("" != a_name) {
            if (name == a_name) {
                // user's state is NotOffline
                a_state = state;
            }
            else {
                // user's state is other
                a_state = m_socketMessage->onSelectStateByName(a_name);
            }
            qDebug("[%s], name is [%s] state is [%d]", __PRETTY_FUNCTION__,a_name.toStdString().c_str(), a_state);
            QListWidgetItem *m_userItem = new QListWidgetItem(m_socketMessage->onChangeStateToIcon(a_state), QObject::tr(a_name.toStdString().c_str()));
            ui->list_user->addItem(m_userItem);
        }
    }
    // showAllUser   <-Introduction
}

/*
 * onUserStateChange
 * Introduction: show information about user's state change
 * Formal parameter: [user's name, will change state]
 * ReturnValue: nothing
 */
void TalkingServer::onUserStateChange(QString a_name, int a_state, int type)
{
    qDebug("[%s] name is [%s], state is [%d]", __PRETTY_FUNCTION__, a_name.toStdString().c_str(), a_state);
    QString word;
    if ((0 == type) && (state_offline != a_state) && (state_regist != a_state)) {
        word = word + "User [ " + a_name + " ] is loading already";
        ui->list_message->addItem(new QListWidgetItem(QObject::tr(word.toStdString().c_str())));
    }

    switch(a_state) {
    case state_regist:
        word = word + "User [ " + a_name + " ] is registed already";
        break;
    case state_offline:
        word = word + "User [ " + a_name + " ] is exit already";
        break;
    case state_NotOffline:
        word = word + "User [ " + a_name + " ] change state to NotOffline";
        break;
    case state_online:
        word = word + "User [ " + a_name + " ] change state to online";
        break;
    case state_hiding:
        word = word + "User [ " + a_name + " ] change state to hiding";
        break;
    default :
        break;
    }
    ui->list_message->addItem(new QListWidgetItem(QObject::tr(word.toStdString().c_str())));
    showAllUser(a_name, a_state);
    // onUserStateChange   <-Introduction
}

/*
 * onUserAddOther
 * Introduction: friend change
 * Formal parameter: [user's name, other user's name]
 * ReturnValue: nothing
 */
void TalkingServer::onUserAddOther(QString m_name, QString f_name)
{
    qDebug("[%s] ", __PRETTY_FUNCTION__);
    QString word = "User [" + f_name + "] add the user [" + m_name + "] with friend";
    ui->list_message->addItem(new QListWidgetItem(QObject::tr(word.toStdString().c_str())));
    // onUserAddOther   <-Introduction
}

//void TalkingServer::onUserChangeState(QString name, int state)
//{
//    qDebug("[%s] ", __PRETTY_FUNCTION__);
//    showAllUser(name, state);
//    // onUserChangeState   <-Introduction
//}
