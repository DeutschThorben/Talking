#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QString name, QWidget *parent) :
    QWidget(parent),
    m_name(name),
    ui(new Ui::AddFriend)
{
    ui->setupUi(this);

    m_clientCommon = new ClientCommon();
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::resultOfFindFriend(QString find_name, int result)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString word;
    switch (result) {
    case result_Success:
        word = "Find the user of [" + find_name + "], would you want to add him with friend ?";
        QMessageBox message(QMessageBox::NoIcon, "Success", word, QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
        if (QMessageBox::Yes == message.exec()) {
            m_clientCommon->onWritePackageToServer(User_FindFriend, result_WhetherAgreeFriend, m_name, "", find_name);
        }
        break;
    case result_NotFindName:
        word = "Not find the user of [" + find_name + "] in server !";
        QMessageBox::critical(NULL, "Error", word, QMessageBox::Ok);
        break;
    case result_AgreeFriend:
        word = "[" + find_name + "] agreen become friend with you.";
        QMessageBox info(QMessageBox::NoIcon, "Success", word, QMessageBox::Ok);
        if (QMessageBox::Ok == info.exec()) {
            close();
        }
        break;
    case result_Failure:
        word = "[" + f_name + "] reject become friend with you !";
        QMessageBox::warning(NULL, "Sad", word, QMessageBox::Ok);
        break;
    case result_WhetherAgreeFriend:
        word = "User [" + find_name + "] want to add you with friend, would you want to agree ?";
        QMessageBox MAS = QMessageBox::question(NULL, "Information", word, QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
        if (QMessageBox::Yes == MAS.exec()) {
            m_clientCommon->onWritePackageToServer(User_FindFriend, result_AgreeFriend, m_name, "", find_name);
        }
        else if (QMessageBox::No == MAS.exec()) {
            m_clientCommon->onWritePackageToServer(User_FindFriend, result_Failure, m_name, "", find_name);
        }
        break;
    default:
        break;
    }

    // onBtnFindClicked   <-Introduction
}

/*
 * onBtnFindClicked
 * Introduction: send the name to server
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void AddFriend::onBtnFindClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString find_name = ui->lineEdit_name->text();
    m_clientCommon->onWritePackageToServer(User_FindFriend, result_WantFriend, m_name, "", find_name);
    // onBtnFindClicked   <-Introduction
}

/*
 * onBtnEmptyClicked
 * Introduction: clean the lineEdit of name
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void AddFriend::onBtnEmptyClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->lineEdit_name->setText("");
    // onBtnEmptyClicked   <-Introduction
}

/*
 * onBtnExitClicked
 * Introduction: close the screen
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void AddFriend::onBtnExitClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    close();
    // onBtnExitClicked   <-Introduction
}

void AddFriend::closeEvent()
{

}
