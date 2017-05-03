#include "registuser.h"
#include "ui_registuser.h"

RegistUser::RegistUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistUser),
    m_result(0)
{
    ui->setupUi(this);
    m_socket = new QTcpSocket();
    m_clientCommon = new ClientCommon();
    m_clientCommon->onSetSocket(m_socket);

    QString m_IP = "127.0.0.1";
    m_socket->connectToHost(m_IP.toStdString().c_str(), 1024);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackRegist()));
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(onOKClicked()));
    connect(ui->btn_empty, SIGNAL(clicked()), this, SLOT(onEmptyClicked()));

    connect(ui->lineEdit_name, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelNameChange()));
    connect(ui->lineEdit_KW, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelKWChange()));
    connect(ui->lineEdit_KWA, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelKWAChange()));
}

RegistUser::~RegistUser()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackRegist()));
    disconnect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(onOKClicked()));
    disconnect(ui->btn_empty, SIGNAL(clicked()), this, SLOT(onEmptyClicked()));

    disconnect(ui->lineEdit_name, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelNameChange()));
    disconnect(ui->lineEdit_KW, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelKWChange()));
    disconnect(ui->lineEdit_KWA, SIGNAL(cursorPositionChanged(int,int)), this, SLOT(onLabelKWAChange()));

    delete m_socket;
    delete m_clientCommon;
    delete ui;
}

/*
 * onFeedBackRegist
 * Introduction: the feedback from server
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void RegistUser::onFeedBackRegist()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = m_clientCommon->onReadPackageFromServer();
    if (User_Regist == bag.head) {
        // The result of regist
        if (result_Success == bag.result) {
            // Regist success
            QMessageBox message(QMessageBox::NoIcon, "Message", "Regist success", QMessageBox::Ok);
            if (QMessageBox::Ok == message.exec()) {
                // Create friend list in server
                m_clientCommon->onWritePackageToServer(User_CreateFriendList, 0, ui->lineEdit_name->text());
                close();
            }
        }
        else if (result_Failure == bag.result) {
            // Regist failure
            QMessageBox::critical(NULL, "Error", "Regist failure !", QMessageBox::Ok);
        }
    }
    else if (User_IsSameName) {
        // The result of is name has been used
        onLabelNameResult(bag.result);
    }
    // onFeedBackRegist   <-Introduction
}

/*
 * onOKClicked
 * Introduction: send regist message to server
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void RegistUser::onOKClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString m_name = ui->lineEdit_name->text();
    QString m_keyword = ui->lineEdit_KW->text();
    QString m_keywordAgain = ui->lineEdit_KWA->text();

    if (1 == m_result) {
        QMessageBox::critical(NULL, "Error", "This name is registed already", QMessageBox::Ok);
    }
    else {
        if (m_keyword != m_keywordAgain) {
            QMessageBox::critical(NULL, "Error", "Each keyword is not same", QMessageBox::Ok);
        }
        else {
            qDebug("[%s] take the bag to server", __PRETTY_FUNCTION__);
            m_clientCommon->onWritePackageToServer(User_Regist, 0, m_name, m_keyword);
        }
    }
    // onOKClicked   <-Introduction
}

/*
 * onEmptyClicked
 * Introduction: make clean of input
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void RegistUser::onEmptyClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->lineEdit_name->setText("");
    ui->lineEdit_KW->setText("");
    ui->lineEdit_KWA->setText("");

    ui->label_name->setText("");
    ui->label_KW->setText("");
    ui->label_KWA->setText("");
    // onEmptyClicked   <-Introduction
}

/*
 * onLabelNameChange
 * Introduction: judge the name is empty or not
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void RegistUser::onLabelNameChange()
{
    QString m_name = ui->lineEdit_name->text();

    if (m_name.length() == 0) {
        ui->label_name->setText("The name can't is empty");
        QPixmap img(":/new/prefix1/picture/offline.png");
        QPixmap fitPixmap = img.scaled(ui->icon_name->width(), ui->icon_name->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->icon_name->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(false);
    }
    else {
        ui->btn_ok->setEnabled(true);
        m_clientCommon->onWritePackageToServer(User_IsSameName, 0, m_name);
    }
    // onLabelNameChange   <-Introduction
}

/*
 * onLabelNameChange
 * Introduction: judge the keyword has 6 charaters or not
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void RegistUser::onLabelKWChange()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString m_KW = ui->lineEdit_KW->text();

    if ((m_KW.length() < 6) || (m_KW.length() > 6)) {
        ui->label_KW->setText("Keyword must has 6 charaters");
        QPixmap img(":/new/prefix1/picture/offline.png");
        QPixmap fitPixmap = img.scaled(ui->icon_KW->width(), ui->icon_KW->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->icon_KW->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(false);
    }
    else if (m_KW.length() == 6) {
        ui->label_KW->setText("");
        QPixmap img(":/new/prefix1/picture/online.png");
        QPixmap fitPixmap = img.scaled(ui->icon_KW->width(), ui->icon_KW->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->icon_KW->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(true);
    }
    else if (m_KW.length() == 0) {
        ui->label_KW->setText("Keyword can't is empty");
        QPixmap img(":/new/prefix1/picture/offline.png");
        QPixmap fitPixmap = img.scaled(ui->icon_KW->width(), ui->icon_KW->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->icon_KW->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(false);
    }
    onLabelKWAChange();
    // onLabelKWChange   <-Introduction
}

/*
 * onLabelKWAChange
 * Introduction: judge the KWA has same with KW or not
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void RegistUser::onLabelKWAChange()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    QString m_KW = ui->lineEdit_KW->text();
    QString m_KWA = ui->lineEdit_KWA->text();

    if (m_KW == m_KWA) {
        ui->label_KWA->setText("");
        QPixmap img(":/new/prefix1/picture/online.png");
        QPixmap fitPixmap = img.scaled(ui->icon_KWA->width(), ui->icon_KWA->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->icon_KWA->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(true);
    }
    else {
        ui->label_KWA->setText("Twice keyword is not same");
        QPixmap img(":/new/prefix1/picture/offline.png");
        QPixmap fitPixmap = img.scaled(ui->icon_KWA->width(), ui->icon_KWA->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->icon_KWA->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(false);
    }
    // onLabelKWAChange   <-Introduction
}

/*
 * onLabelNameResult
 * Introduction: set name's icon and text
 * Formal parameter: [The result of whether the name is used]
 * ReturnValue: nothing
 */
void RegistUser::onLabelNameResult(int result)
{
    qDebug("[%s] The result is [%d] (has name-2/not find-3)", __PRETTY_FUNCTION__, result);
    if (result_HasName == result) {
        m_result = 1;
        ui->label_name->setText("This name has been used");
        QPixmap img(":/new/prefix1/picture/offline.png");
        QPixmap fitPixmap = img.scaled(ui->icon_name->width(), ui->icon_name->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->icon_name->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(false);
    }
    else if (result_NotFindName == result) {
        m_result = 0;
        ui->label_name->setText("");
        QPixmap img(":/new/prefix1/picture/online.png");
        QPixmap fitPixmap = img.scaled(ui->icon_name->width(), ui->icon_name->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        ui->icon_name->setPixmap(QPixmap(fitPixmap));
        ui->btn_ok->setEnabled(true);
    }
    // onLabelNameResult   <-Introduction
}
