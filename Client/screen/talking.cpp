#include "talking.h"
#include "ui_talking.h"

Talking::Talking(QTcpSocket *sockfd, QString name, QString otherName, QWidget *parent) :
    QWidget(parent),
    m_socked(sockfd),
    m_name(name),
    m_otherName(otherName),
    ui(new Ui::Talking)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->setupUi(this);
    m_clientCommon = ClientCommon::getInstance();
    m_clientCommon->setSocket(m_socked);

    connect(m_socked, SIGNAL(readyRead()), this, SLOT(onFeedBackTalking()));

    connect(ui->btn_send, SIGNAL(clicked()), this, SLOT(onSendMessageToServerClicked()));
}

Talking::~Talking()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    disconnect(m_socked, SIGNAL(readyRead()), this, SLOT(onFeedBackTalking()));

    disconnect(ui->btn_send, SIGNAL(clicked()), this, SLOT(onSendMessageToServerClicked()));

    delete m_clientCommon;
    delete ui;
}

void Talking::onSendMessageToServerClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    if ("" == m_otherName) {
        QMessageBox::warning(NULL, "Warning", "Please choose one user to talking from list friend", QMessageBox::Ok);
    }
    else {
        QString m_message = ui->textEdit_inputScreen->toPlainText();
        qDebug("[%s] send message is [%s]", __PRETTY_FUNCTION__, m_message.toStdString().c_str());
        m_clientCommon->onWritePackage(USER_Talking, m_name, "",  m_otherName, m_message);

        ui->textEdit_talkScreen->append(m_message);
    }
    // onSendMessageToServerClicked   <-Introduction
}

void Talking::onFeedBackTalking()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = m_clientCommon->onReadPackage();

    if (USER_Talking == bag.head) {

    }
    // onFeedBackTalking   <-Introduction
}
