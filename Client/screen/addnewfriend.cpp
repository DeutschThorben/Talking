#include "addnewfriend.h"
#include "ui_addnewfriend.h"

AddNewFriend::AddNewFriend(QTcpSocket *sockfd, QString name, QWidget *parent) :
    QWidget(parent),
    m_socket(sockfd),
    m_name(name),
    ui(new Ui::AddNewFriend)
{
    ui->setupUi(this);

//    setAttribute(Qt::WA_DeleteOnClose);

    m_clientCommon = ClientCommon::getInstance();
    m_clientCommon->setSocket(sockfd);

    connect(ui->btn_find, SIGNAL(clicked()), this, SLOT(onFindThisNameClicked()));
    connect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onExitScreenClicked()));
    connect(sockfd, SIGNAL(readyRead()), this, SLOT(onFeedBackFind()));
}

AddNewFriend::~AddNewFriend()
{
//    disconnect(ui->btn_find, SIGNAL(clicked(bool)), this, SLOT(onFindThisNameClicked()));
//    disconnect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onExitScreenClicked()));
//    disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackFind()));

//    delete m_clientCommon;
//    delete ui;

//    m_clientCommon = NULL;
}

/*
 *  onFindThisNameClicked
 *  Introduction: send name about find friend to server
 *  ReturnValue: nothing
 */
void AddNewFriend::onFindThisNameClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString m_findName = ui->lineEdit_name->text();

    if (m_clientCommon->selectNameFromFriendList(m_findName, m_name)) {
        QMessageBox::warning(NULL, "Warning", "This user is been your friend");
    }
    else {
        m_clientCommon->onWritePackage(USER_FindFriend, "", "", m_findName);
    }
    // onFindThisNameClicked   <-Introduction
}

/*
 *  onExitScreenClicked
 *  Introduction: Exit screen of addNewFriend
 *  ReturnValue: nothing
 */
void AddNewFriend::onExitScreenClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    disconnect(ui->btn_find, SIGNAL(clicked(bool)), this, SLOT(onFindThisNameClicked()));
    disconnect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onExitScreenClicked()));
    disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackFind()));

    delete m_clientCommon;
    delete ui;

    m_clientCommon = NULL;

    close();
    // onExitScreenClicked   <-Introduction
}

void AddNewFriend::onFeedBackFind()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = m_clientCommon->onReadPackage();

    qDebug("[%s] head is [%d], result is [%d]", __PRETTY_FUNCTION__, bag.head, bag.result);
    if (USER_FindFriend == bag.head) {
        if (1 == bag.result) {
            QString tmp = "Find this user about '" + ui->lineEdit_name->text() + "', would you want add him ?";
            QMessageBox message(QMessageBox::NoIcon, "Result", tmp, QMessageBox::Yes|QMessageBox::No, NULL);
            if (QMessageBox::Yes == message.exec()) {
                QMessageBox next_message(QMessageBox::NoIcon, "Result", "Add success.", QMessageBox::Ok);
                if (QMessageBox::Ok == next_message.exec()) {
                    m_clientCommon->addAFriendUser(ui->lineEdit_name->text(), m_name);
                    emit addFriendSuccess();
                    close();
                }
            }
        }
        else {
            QString result = "Not find the name about " + ui->lineEdit_name->text();
            QMessageBox::critical(NULL, "Error", result, QMessageBox::Ok);
        }
    }
    // onFeedBackFind   <-Introduction
}
