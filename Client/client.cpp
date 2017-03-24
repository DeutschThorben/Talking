#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    m_socked = new QTcpSocket();
}

Client::~Client()
{
    delete ui;
}

void Client::onBtnLoginClicked()
{
    QString m_name = ui->lineEdit_name->text();
    QString m_keyword = ui->lineEdit_keyword->text();
}

void Client::onBtnRegistClicked()
{

}

void Client::onBtnExitClicked()
{

}

Package Client::onReadPackage()
{
    Package bag = {EMPTY};
    return m_socked->read((char*)(&bag), sizeof(Package));
}

void Client::onWritePackage(PackageType head, QString name, QString keyword, QString otherUser, QString talkingInformation)
{
    Package bag = {EMPTY};
    bag.head = head;
    bag.name = name;
    bag.keyword = keyword;
    bag.otherUser = otherUser;
    bag.talkingInformation = talkingInformation;

    m_socked->write((char*)(&bag), sizeof(Package));
}
