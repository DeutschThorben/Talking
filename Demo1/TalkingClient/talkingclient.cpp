#include "talkingclient.h"
#include "ui_talkingclient.h"

TalkingClient::TalkingClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TalkingClient)
{
    ui->setupUi(this);

    m_socket = new QTcpSocket();
    m_clientCommon = new ClientCommon();

    addItemCombox();

    connect(ui->btn_login, SIGNAL(clicked(bool)), this, SLOT(onLoginClicked()));
    connect(ui->btn_regist, SIGNAL(clicked(bool)), this, SLOT(onRegistClicked()));
    connect(ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(onExitClicked()));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onChooseLoginState(int)));

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadFromServer()));
}

TalkingClient::~TalkingClient()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    delete m_clientCommon;
    delete ui;
}

/*
 * onLoginClicked
 * Introduction: make connect with server and apply for loading
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingClient::onLoginClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    m_name = ui->lineEdit_name->text();
    QString m_keyword = ui->lineEdit_KWD->text();

    // make connect with server
    QString m_count = "127.0.0.1";
    m_socket->connectToHost(m_count.toStdString().c_str(), 1024);
    m_clientCommon->onSetSocket(m_socket);
    m_clientCommon->onWritePackageToServer(User_Login, m_state, m_name, m_keyword);
    // onLoginClicked   <-Introduction
}

/*
 * onRegistClicked
 * Introduction: open regist screen
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingClient::onRegistClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    RegistUser *m_regist = new RegistUser();
    m_regist->show();
    // onRegistClicked   <-Introduction
}

/*
 * onExitClicked
 * Introduction: exit client
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingClient::onExitClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    close();
    // onExitClicked   <-Introduction
}

/*
 * onReadFromServer
 * Introduction: make action about result from server
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingClient::onReadFromServer()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = m_clientCommon->onReadPackageFromServer();

    switch(bag.result) {
    case result_alreadyLoading:
        // This user is already login
        QMessageBox::warning(NULL, "Warning", "This user has been loading !", QMessageBox::Ok);
        break;
    case result_KeywordMistake:
        // Keyword is mistake
        QMessageBox::critical(NULL, "Error", "Keywork mistake !", QMessageBox::Ok);
        break;
    case result_NotFindName:
        // Not find this user in server
        QMessageBox::critical(NULL, "Error", "Not exist this user !", QMessageBox::Ok);
        break;
    case result_Success:
        // Login success
        m_clientCommon->onSetSocket(m_socket);
        FriendList *screen_friendList = new FriendList(m_socket, m_name, m_state);
        screen_friendList->show();
        close();
        break;
    default:
        break;
    }

    // onReadFromServer   <-Introduction
}

/*
 * onChooseLoginState
 * Introduction: choose a state for user login
 * Formal parameter: [choose state]
 * ReturnValue: nothing
 */
void TalkingClient::onChooseLoginState(int state)
{
    qDebug("[%s] change state is [%d]", __PRETTY_FUNCTION__, state);
    m_state = state;
    // onChooseLoginState   <-Introduction
}

/*
 * addItemInCombox
 * Introduction: add item in combox
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingClient::addItemCombox()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->comboBox->addItem(QIcon(":/new/prefix1/failure.png"), "offline");
    ui->comboBox->addItem(QIcon(":/new/prefix1/true.png"), "online");
    ui->comboBox->addItem(QIcon(":/new/prefix1/warning.png"), "hiding");
    // addItemInComBox   <-Introduction
}

/*
 * closeEvent
 * Introduction: action when screen close and thread not close
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void TalkingClient::closeEvent()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    disconnect(ui->btn_login, SIGNAL(clicked(bool)), this, SLOT(onLoginClicked()));
    disconnect(ui->btn_regist, SIGNAL(clicked(bool)), this, SLOT(onRegistClicked()));
    disconnect(ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(onExitClicked()));

    disconnect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onChooseLoginState(int)));

    if (NULL != m_socket) {
        disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadFromServer()));
    }
    // closeEvent   <-Introduction
}
