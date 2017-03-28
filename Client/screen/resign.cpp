#include "resign.h"
#include "ui_resign.h"

Resign::Resign(QTcpSocket *sockfd, QWidget *parent) :
    QWidget(parent),
    m_socked(sockfd),
    ui(new Ui::Resign)
{
    ui->setupUi(this);
    m_clientCommon = new ClientCommon(m_socked);

    qDebug("[%s]", __PRETTY_FUNCTION__);
//    connect(this, SIGNAL(isSameName()), this, SLOT(onIsSameName()));
    connect(m_socked, SIGNAL(readyRead()), this, SLOT(onFeedBackRegist()));
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(onBtnOkClicked()));
    connect(ui->btn_empty, SIGNAL(clicked()), this, SLOT(onBtnEmptyClicked()));
}

Resign::~Resign()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
//    disconnect(this, SIGNAL(isSameName()), this, SLOT(onIsSameName()));
    disconnect (ui->btn_ok, SIGNAL(clicked()), this, SLOT(onBtnOkClicked()));
    disconnect(ui->btn_empty, SIGNAL(clicked()), this, SLOT(onBtnEmptyClicked()));
    disconnect(m_socked, SIGNAL(readyRead()), this, SLOT(onFeedBackRegist()));
    delete ui;
}

void Resign::onBtnOkClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString m_name = ui->user_newName->text();
    QString m_keyword = ui->user_newKeyword->text();
    QString m_keywordAgain = ui->user_keywordAgain->text();

    if (m_keyword != m_keywordAgain) {
        QMessageBox::critical(NULL, "Error", "Each keyword is not same", QMessageBox::Ok);
    }
    else {
        qDebug("[%s] take the bag to server", __PRETTY_FUNCTION__);
        // make connect with server
        QString m_IP = "127.0.0.1";
        m_socked->connectToHost(m_IP.toStdString().c_str(), 1024);
        m_clientCommon->onWritePackage(USER_Regist, m_name, m_keyword);
    }
}

/*
 *  onBtnEmptyClicked
 *  Instruction: Clean all text in regist screen
 *  ReturnValue: nothing
 */
void Resign::onBtnEmptyClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->user_newName->setText("");
    ui->user_newKeyword->setText("");
    ui->user_keywordAgain->setText("");
    // onBtnLoginClicked   <-onBtnEmptyClicked
}

void Resign::onFeedBackRegist()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = m_clientCommon->onReadPackage();

    if (USER_Regist == bag.head) {
        if (2 == bag.result) {
            QMessageBox::warning(NULL, "Warning", "This name is registed already", QMessageBox::Ok);
        }
        else if(1 == bag.result) {
            QMessageBox message(QMessageBox::NoIcon, "Message", "Regist success", QMessageBox::Ok);
            if (message.exec() == QMessageBox::Yes) {
                close();
            }
        }
    }
}

//void Resign::onIsSameName()
//{
//    qDebug("[%s]", __PRETTY_FUNCTION__);
//    ui->label_name->setText("ok");
//}
