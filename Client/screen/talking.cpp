#include "talking.h"
#include "ui_talking.h"

Talking::Talking(QString name, QString otherName, QWidget *parent) :
    QWidget(parent),
    m_name(name),
    m_otherName(otherName),
    ui(new Ui::Talking)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->setupUi(this);

//    setAttribute(Qt::WA_DeleteOnClose);

    m_clientCommon = ClientCommon::getInstance();

    connect(ui->btn_send, SIGNAL(clicked()), this, SLOT(onSendMessageToServerClicked()));
    connect(ui->btn_B, SIGNAL(clicked(bool)), this, SLOT(onWordOverStriking()));

    ui->label_name->setText(m_otherName);
}

Talking::~Talking()
{

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

void Talking::MessageFromOther(QString f_message)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    ui->textEdit_talkScreen->append(f_message);
    // MessageFromOther   <-Introduction
}

void Talking::onWordOverStriking()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    ui->textEdit_inputScreen->selectAll();
    // onWordOverStriking   <-Introduction
}

void Talking::onWordColorChange()
{

}

/*
 *  closeEvent
 *  Introduction: disconnect and clean point
 *  Formal parameter: [event]
 *  ReturnValue: nothing
 */
void Talking::closeEvent(QCloseEvent *)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    disconnect(ui->btn_send, SIGNAL(clicked()), this, SLOT(onSendMessageToServerClicked()));
    disconnect(ui->btn_B, SIGNAL(clicked(bool)), this, SLOT(onWordOverStriking()));

    delete ui;
    // closeEvent   <-Introduction
}
