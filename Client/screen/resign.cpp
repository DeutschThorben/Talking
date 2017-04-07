#include "resign.h"
#include "ui_resign.h"

Resign::Resign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Resign)
{
    ui->setupUi(this);
    m_socked = new QTcpSocket();
    m_clientCommon = ClientCommon::getInstance();
    m_clientCommon->setSocket(m_socked);

    setAttribute(Qt::WA_DeleteOnClose);

    QString m_IP = "127.0.0.1";
    m_socked->connectToHost(m_IP.toStdString().c_str(), 1024);

    connect(m_socked, SIGNAL(readyRead()), this, SLOT(onFeedBackRegist()));
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(onBtnOkClicked()));
    connect(ui->btn_empty, SIGNAL(clicked()), this, SLOT(onBtnEmptyClicked()));

    connect(ui->user_newName, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelNameChange()));
    connect(ui->user_newKeyword, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelKWChange()));
    connect(ui->user_keywordAgain, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelKWAgainChange()));
}

Resign::~Resign()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    disconnect (ui->btn_ok, SIGNAL(clicked()), this, SLOT(onBtnOkClicked()));
    disconnect(ui->btn_empty, SIGNAL(clicked()), this, SLOT(onBtnEmptyClicked()));
    disconnect(m_socked, SIGNAL(readyRead()), this, SLOT(onFeedBackRegist()));

    disconnect(ui->user_newName, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelNameChange()));
    disconnect(ui->user_newKeyword, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelKWChange()));
    disconnect(ui->user_keywordAgain, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelKWAgainChange()));

    delete m_socked;
    delete m_clientCommon;
    delete ui;
}

/*
 *  onBtnOkClicked
 *  Instruction: send message about registe to server
 *  ReturnValue: nothing
 */
void Resign::onBtnOkClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString m_name = ui->user_newName->text();
    QString m_keyword = ui->user_newKeyword->text();
    QString m_keywordAgain = ui->user_keywordAgain->text();

    if (1 == m_result) {
        QMessageBox::critical(NULL, "Error", "This name is registed already", QMessageBox::Ok);
    }
    else {
        if (m_keyword != m_keywordAgain) {
            QMessageBox::critical(NULL, "Error", "Each keyword is not same", QMessageBox::Ok);
        }
        else {
            qDebug("[%s] take the bag to server", __PRETTY_FUNCTION__);
            m_clientCommon->onWritePackage(USER_Regist, m_name, m_keyword);
        }
    }
    // onBtnOkClicked   <-onBtnEmptyClicked
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

    ui->label_iconName->setText("");
    ui->label_iconKW->setText("");
    ui->label_iconKWA->setText("");
    // onBtnLoginClicked   <-onBtnEmptyClicked
}

/*
 *  onFeedBackRegist
 *  Instruction: Clean all text in regist screen
 *  ReturnValue: regist success (1), regist failure (0)
 */
void Resign::onFeedBackRegist()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    Package bag = {EMPTY};
    m_socked->read((char*)(&bag), sizeof(Package));

    qDebug("[%s] head is [%d]", __PRETTY_FUNCTION__, bag.head);
    qDebug("[%s] result is [%d]", __PRETTY_FUNCTION__, bag.result);
    if (USER_Regist == bag.head) {
        if(1 == bag.result) {
            QMessageBox message(QMessageBox::NoIcon, "Message", "Regist success", QMessageBox::Ok);
            if (QMessageBox::Ok == message.exec()) {
                m_clientCommon->createFriendList(ui->user_newName->text());
                close();
            }
        }
        else {
            QMessageBox::critical(NULL, "Error", "Regist failure !", QMessageBox::Ok);
        }
    }
    else if (USER_Regist_IsSameName == bag.head) {
        onLabelNameResult(bag.result);
    }
    // onFeedBackRegist   <-onBtnEmptyClicked
}

/*
 *  onLabelNameResult
 *  Instruction: Feedback from server about whether the name has been used
 *  ReturnValue: name has been used (1), name is new (0)
 */
void Resign::onLabelNameResult(int result)
{
    qDebug("[%s] the result is [%d]", __PRETTY_FUNCTION__, result);
    m_result = result;
    if (1 == result) {
        ui->label_name->setText("This name has been used");
        QPixmap img(":/new/prefix1/failure.png");
        QPixmap fitPixmap = img.scaled(ui->label_iconName->width(), ui->label_iconName->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label_iconName->setPixmap(QPixmap(fitPixmap));
        ui->label_name->setVisible(true);
        ui->btn_ok->setEnabled(false);
    }
    else if (0 == result) {
        QPixmap img(":/new/prefix1/true.png");
        QPixmap fitPixmap = img.scaled(ui->label_iconName->width(), ui->label_iconName->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label_iconName->setPixmap(QPixmap(fitPixmap));
        ui->label_name->setText("");
        ui->btn_ok->setEnabled(true);
    }
    // onLabelNameResult   <-onBtnEmptyClicked
}

/*
 *  onLabelNameChange
 *  Instruction: warning the name can't empty
 *  ReturnValue: nothing
 */
void Resign::onLabelNameChange()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString m_name = ui->user_newName->text();

    if (m_name.length() == 0) {
        ui->label_name->setText("The name can't is empty");
        QPixmap img(":/new/prefix1/failure.png");
        QPixmap fitPixmap = img.scaled(ui->label_iconName->width(), ui->label_iconName->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label_iconName->setPixmap(QPixmap(fitPixmap));
        ui->label_name->setVisible(true);
        ui->btn_ok->setEnabled(false);
    }
    else {
        ui->btn_ok->setEnabled(true);
        m_clientCommon->onWritePackage(USER_Regist_IsSameName, m_name);
    }
    // onLabelKWChange   <-onBtnEmptyClicked
}

/*
 *  onLabelKWChange
 *  Instruction: warning the keyword must has six charater
 *  ReturnValue: nothing
 */
void Resign::onLabelKWChange()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString m_KW = ui->user_newKeyword->text();

    if ((m_KW.length() < 6) || (m_KW.length() > 6)) {
        ui->label_keyword->setText("Keyword must has 6 charaters");
        QPixmap img(":/new/prefix1/failure.png");
        QPixmap fitPixmap = img.scaled(ui->label_iconKW->width(), ui->label_iconKW->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label_iconKW->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(false);
    }
    else if (m_KW.length() == 6) {
        ui->label_keyword->setText("");
        QPixmap img(":/new/prefix1/true.png");
        QPixmap fitPixmap = img.scaled(ui->label_iconKW->width(), ui->label_iconKW->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label_iconKW->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(true);
    }
    else if (m_KW.length() == 0) {
        ui->label_keyword->setText("Keyword can't is empty");
        QPixmap img(":/new/prefix1/failure.png");
        QPixmap fitPixmap = img.scaled(ui->label_iconKW->width(), ui->label_iconKW->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->label_iconKW->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(false);
    }
    onLabelKWAgainChange();
    // onLabelKWChange   <-onBtnEmptyClicked
}

/*
 *  onLabelKWAgainChange
 *  Instruction: warning the KWAgain is same as keyword
 *  ReturnValue: nothing
 */
void Resign::onLabelKWAgainChange()
{
    QString m_KW = ui->user_newKeyword->text();
    QString m_KWA = ui->user_keywordAgain->text();

    if (m_KWA.length() == 0) {
        ui->label_keywordAgain->setVisible(false);
        ui->label_iconKWA->setVisible(false);
    }
    else {
        ui->label_keywordAgain->setVisible(true);
        ui->label_iconKWA->setVisible(true);
        if (m_KW == m_KWA) {
            ui->label_keywordAgain->setText("");
            QPixmap img(":/new/prefix1/true.png");
            QPixmap fitPixmap = img.scaled(ui->label_iconKWA->width(), ui->label_iconKWA->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            ui->label_iconKWA->setPixmap(QPixmap(fitPixmap));
            ui->btn_ok->setEnabled(true);
        }
        else {
            ui->label_keywordAgain->setText("Twice keyword is not same");
            QPixmap img(":/new/prefix1/failure.png");
            QPixmap fitPixmap = img.scaled(ui->label_iconKWA->width(), ui->label_iconKWA->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            ui->label_iconKWA->setPixmap(QPixmap(fitPixmap));
            ui->btn_ok->setEnabled(false);
        }
    }
}


void Resign::closeEvent()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
}
