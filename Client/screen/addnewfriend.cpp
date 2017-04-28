#include "addnewfriend.h"
#include "ui_addnewfriend.h"

AddNewFriend::AddNewFriend(QString name, QWidget *parent) :
    QWidget(parent),
    m_name(name),
    ui(new Ui::AddNewFriend)
{
    ui->setupUi(this);

//    setAttribute(Qt::WA_DeleteOnClose);

    m_clientCommon = ClientCommon::getInstance();

    connect(ui->btn_find, SIGNAL(clicked()), this, SLOT(onFindThisNameClicked()));
    connect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onExitScreenClicked()));
}

AddNewFriend::~AddNewFriend()
{

}

/*
 *  onFindThisNameClicked
 *  Introduction: send name about find friend to server
 *  Formal parameter: nothing
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
        m_clientCommon->onWritePackage(USER_FindFriend, "", "", m_findName, "", 4);
    }
    // onFindThisNameClicked   <-Introduction
}

/*
 *  onExitScreenClicked
 *  Introduction: Exit screen of addNewFriend
 *  Formal parameter: nothing
 *  ReturnValue: nothing
 */
void AddNewFriend::onExitScreenClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    close();
    // onExitScreenClicked   <-Introduction
}

/*
 *  onFindFriendIsSuccess
 *  Introduction: result about add new friend
 *  Formal parameter: [whether add new friend success (success_online-1/success_offline-2/failure-0/not agree become friend-3/want add you a friend-4)]
 *  ReturnValue: nothing
 */
void AddNewFriend::onFindFriendIsSuccess(int m_result, QString f_name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    if (1 == m_result || 2 == m_result) {
        QString tmp = "Find this user about '" + ui->lineEdit_name->text() + "', would you want add him ?";
        QMessageBox message(QMessageBox::NoIcon, "Result", tmp, QMessageBox::Yes|QMessageBox::No, NULL);
        if (QMessageBox::Yes == message.exec()) {
            QMessageBox next_message(QMessageBox::NoIcon, "Result", "Add success.", QMessageBox::Ok);
            if (QMessageBox::Ok == next_message.exec()) {
                m_clientCommon->addAFriendUser(ui->lineEdit_name->text(), m_name);
                if (1 == m_result) {
                    // this friend is offline
                    m_clientCommon->changeFriendState(m_name, ui->lineEdit_name->text(), 0);
                }
                else {
                    // this friend is online
                    m_clientCommon->changeFriendState(m_name, ui->lineEdit_name->text(), 1);
                }
                emit addFriendSuccess();
                close();
            }
        }
    }
    else if (0 == m_result){
        QString result = "Not find the name about " + ui->lineEdit_name->text();
        QMessageBox::critical(NULL, "Error", result, QMessageBox::Ok);
    }
    else if (3 == m_result) {
        QMessageBox::warning(NULL, "Sorry", "This user don't agree to become a friend with you!", QMessageBox::Ok);
    }
    else if (4 == m_result) {
//        QString result = "User[ " + f_name + " ] want to add you to a friend, would you agree a frient with him ?";
//        QMessageBox agree_message = QMessageBox::question(NULL, "Question", result, QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
//        if (QMessageBox::Yes == agree_message.exec()) {
//            m_clientCommon->onWritePackage(USER_FindFriend, m_name, "", f_name, "", 1);
//        }
//        else {
//            m_clientCommon->onWritePackage(USER_FindFriend, m_name, "", f_name, "", 0);
//        }
    }
    // onFindFriendIsSuccess   <-Introduction
}

/*
 *  closeEvent
 *  Introduction: disconnect and clean point
 *  Formal parameter: [event]
 *  ReturnValue: nothing
 */
void AddNewFriend::closeEvent()
{
    qDebug("[%s] m_clientCommon is [%p]", __PRETTY_FUNCTION__, m_clientCommon);

    disconnect(ui->btn_find, SIGNAL(clicked(bool)), this, SLOT(onFindThisNameClicked()));
    disconnect(ui->btn_exit, SIGNAL(clicked()), this, SLOT(onExitScreenClicked()));

//    delete ui;
    // closeEvent   <-Introduction
}
