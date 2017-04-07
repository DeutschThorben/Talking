#include "client.h"
#include "ui_client.h"


Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    m_socked = new QTcpSocket();
   //  m_resign = new Resign(m_socked);
    m_clientCommon = ClientCommon::getInstance();

    qDebug("[%s]  socket is [%p]", __PRETTY_FUNCTION__, m_socked);
    connect(m_socked, SIGNAL(readyRead()), this, SLOT(onReadFromServer()));
    connect(ui->btn_regist, SIGNAL(clicked()), this, SLOT(onBtnRegistClicked()));
    connect(ui->btn_login, SIGNAL(clicked()), this, SLOT(onBtnLoginClicked()));
    connect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onBtnExitClicked()));
}

Client::~Client()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    disconnect(ui->btn_regist, SIGNAL(clicked(bool)), this, SLOT(onBtnRegistClicked()));
    disconnect(ui->btn_login, SIGNAL(clicked()), this, SLOT(onBtnLoginClicked()));
    disconnect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onBtnExitClicked()));

    delete m_clientCommon;
    delete ui;
}

/*
 *  onBtnLoginClicked
 *  Instruction: Login server
 *  ReturnValue: nothing
 */
void Client::onBtnLoginClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    m_name = ui->lineEdit_name->text();
    QString m_keyword = ui->lineEdit_keyword->text();

    // make connect with server
    QString m_IP = "127.0.0.1";
    m_socked->connectToHost(m_IP.toStdString().c_str(), 1024);
    m_clientCommon->setSocket(m_socked);
    m_clientCommon->onWritePackage(USER_Login, m_name, m_keyword);

    // onBtnLoginClicked   <-Introduction
}

/*
 *  onBtnRegistClicked
 *  Instruction: Open regist screen and close main screen
 *  RetureValue: nothing
 */
void Client::onBtnRegistClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Resign *m_resign = new Resign();
    m_resign->show();
    // onBtnRegistClicked   <-Introduction
}

void Client::onBtnExitClicked()
{
    close();
}

/*
 *  onReadFromServer
 *  Instruction: To analyse news from server
 *  ReturnValue: nothing
 */
void Client::onReadFromServer()
{
    Package bag = m_clientCommon->onReadPackage();
    qDebug("[%s]", __PRETTY_FUNCTION__);
    if (USER_Login == bag.head) {
        if (1 == bag.result) {
            disconnect(m_socked, SIGNAL(readyRead()), this, SLOT(onReadFromServer()));
            screen_talkingList = new TalkingListScreen(m_socked, m_name);
            screen_talkingList->show();
            close();
        }
        else if (2 == bag.result) {
            QMessageBox::warning(NULL, "warnning", "This user has been logined !");
        }
        else if (0 == bag.result) {
            QMessageBox::critical(NULL, "critical", "Keyword is mistake !");
        }
        else if (3 == bag.result) {
            QMessageBox::critical(NULL, "critical", "Don't have this user !");
        }
    }
    // onReadFromServer   <-Introduction
}
