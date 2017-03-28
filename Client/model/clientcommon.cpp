#include "clientcommon.h"

ClientCommon::ClientCommon(QTcpSocket *sockfd, QObject *parent) : QObject(parent), m_socked(sockfd)
{

}

/*
 *  onReadPackage
 *  Instruction: get news from server
 *  ReturnValue: package from server
 */
Package ClientCommon::onReadPackage()
{
    Package bag = {EMPTY};
    m_socked->read((char*)(&bag), sizeof(Package));
    return bag;
    // onReadPackage   <-Introduction
}

/*
 *  onWritePackage
 *  Instruction: take the package from client to server
 *  ReturnValue: nothing
 */
void ClientCommon::onWritePackage(PackageType head, QString name, QString keyword, QString otherUser, QString talkingInformation)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = {EMPTY};
    bag.head = head;
    bag.name = name;
    bag.keyword = keyword;
    bag.otherUser = otherUser;
    bag.talkingInformation = talkingInformation;

    qDebug("[%s] bag.head is [%d]", __PRETTY_FUNCTION__, bag.head);
    qDebug("[%s] bag.name is [%s]", __PRETTY_FUNCTION__, bag.name.toStdString().c_str());
    qDebug("[%s] bag.keyword is [%s]", __PRETTY_FUNCTION__, bag.keyword.toStdString().c_str());
    qDebug("[%s] bag.otherUser is [%s]", __PRETTY_FUNCTION__, bag.otherUser.toStdString().c_str());
    qDebug("[%s] bag.talkingInformation is [%s]", __PRETTY_FUNCTION__, bag.talkingInformation.toStdString().c_str());

    m_socked->write((char*)(&bag), sizeof(Package));
    qDebug("[%s] package is sent to server already", __PRETTY_FUNCTION__);
    // onWritePackage   <-Introduction
}
