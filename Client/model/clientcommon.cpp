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
    qDebug("[%s]", __PRETTY_FUNCTION__);
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
    strncpy(bag.name, onQStringChangeToChar(name), 20);
    strncpy(bag.keyword, onQStringChangeToChar(keyword), 20);
    strncpy(bag.otherUser, onQStringChangeToChar(otherUser), 20);
    strncpy(bag.talkingInformation, onQStringChangeToChar(talkingInformation), 40);

    qDebug("[%s] bag.head is [%d]", __PRETTY_FUNCTION__, bag.head);
    qDebug("[%s] bag.name is [%s]", __PRETTY_FUNCTION__, bag.name);
    qDebug("[%s] bag.keyword is [%s]", __PRETTY_FUNCTION__, bag.keyword);
    qDebug("[%s] bag.otherUser is [%s]", __PRETTY_FUNCTION__, bag.otherUser);
    qDebug("[%s] bag.talkingInformation is [%s]", __PRETTY_FUNCTION__, bag.talkingInformation);

    m_socked->write((char*)(&bag), sizeof(Package));
    qDebug("[%s] package is sent to server already", __PRETTY_FUNCTION__);
    // onWritePackage   <-Introduction
}

/*
 *  onQStringChangeToChar
 *  Instruction: change type from QString to char*
 *  ReturnValue: char* text
 */
const char* ClientCommon::onQStringChangeToChar(QString b_text)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    const char* a_text = b_text.toStdString().data();
    return a_text;
    // onQStringChangeToChar   <-Introduction
}

/*
 *  onCharToQString
 *  Instruction: change type from char* to QString
 *  ReturnValue: QString text
 */
QString ClientCommon::onCharToQString(char *b_text)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString a_text = QString::fromStdString(b_text);
    return a_text;
    // onCharToQString   <-Introduction
}
