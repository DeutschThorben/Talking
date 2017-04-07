#include "clientcommon.h"
ClientCommon* ClientCommon::instance = NULL;

ClientCommon::ClientCommon(QObject *parent) : QObject(parent)
{

}

ClientCommon* ClientCommon::getInstance()
{
    if (NULL == instance) {
        instance = new ClientCommon();
    }
    return instance;
}

/*
 *  onReadPackage
 *  Instruction: get news from server
 *  ReturnValue: package from server
 */
Package ClientCommon::onReadPackage()
{
    qDebug("[%s]      socket is [%p]", __PRETTY_FUNCTION__, m_socked);
    Package bag = {EMPTY};
    m_socked->read((char*)(&bag), sizeof(Package));

    qDebug("[%s] bag.head is [%d]", __PRETTY_FUNCTION__, bag.head);
    qDebug("[%s] bag.name is [%s]", __PRETTY_FUNCTION__, bag.name);
    qDebug("[%s] bag.keyword is [%s]", __PRETTY_FUNCTION__, bag.keyword);
    qDebug("[%s] bag.otherUser is [%s]", __PRETTY_FUNCTION__, bag.otherUser);
    qDebug("[%s] bag.talkingInformation is [%s]", __PRETTY_FUNCTION__, bag.talkingInformation);


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
    qDebug("[%s]  socket is [%p]", __PRETTY_FUNCTION__, m_socked);
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

void ClientCommon::setSocket(QTcpSocket *socket)
{
    qDebug("[%s] socket is [%p]", __PRETTY_FUNCTION__, socket);
    m_socked = socket;
}


void ClientCommon::createFriendList(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    FriendList::getInstance()->onCreateConnect();
    QSqlQuery query;

    QString word = "create table " + name +" (ID integer primary key autoincrement, name verchar(20), state integer)";
//    query.prepare("create table :name (ID integer primary key autoincrement, name verchar(20), state integer)");
//    query.bindValue(":name", name);

    bool ret = query.exec(word);
    bool tmp = query.next();
    qDebug("[%s] ret = [%d]", __PRETTY_FUNCTION__, ret);
    qDebug("[%s] tmp = [%d]", __PRETTY_FUNCTION__, tmp);
    FriendList::getInstance()->onDestroyConnect();
    // createFriendList   <-Introduction
}

void ClientCommon::addAFriendUser(QString f_name, QString m_name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    FriendList::getInstance()->onCreateConnect();
    QSqlQuery query;
    QString word = "insert into " + m_name + "(name, state) values(:name, :state)";

    query.prepare(word);
    query.bindValue(":name", f_name);
    query.bindValue(":state", 0);
    bool ret = query.exec();
    bool tmp = query.next();
    qDebug("[%s] ret = [%d]", __PRETTY_FUNCTION__, ret);
    qDebug("[%s] tmp = [%d]", __PRETTY_FUNCTION__, tmp);
    FriendList::getInstance()->onDestroyConnect();
    // addAFriendUser   <-Introduction
}

QString ClientCommon::findAllFriendName(int m_ID, QString m_name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    FriendList::getInstance()->onCreateConnect();
    QSqlQuery query;
    QString word = "select name from " + m_name + " where ID = :ID";
    QString f_name;

    query.prepare(word);
    query.bindValue(":ID", m_ID);
    query.exec();

    while (query.next()) {
        f_name = query.value("name").toString();
    }

    FriendList::getInstance()->onDestroyConnect();
    return f_name;
    // findAllFriendName   <-Introduction
}

int ClientCommon::findAllFriendState(QString f_name, QString m_name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    FriendList::getInstance()->onCreateConnect();

    QSqlQuery query;
    QString word = "select state from " + m_name + " where name = :name";
    int m_state = 0;

    query.prepare(word);
    query.bindValue(":name", f_name);
    query.exec();

    while (query.next()) {
        m_state = query.value("state").toInt();
    }
    FriendList::getInstance()->onDestroyConnect();
    return m_state;
    // onSelectSomeState   <-Introduction
}

void ClientCommon::deleteAFriendUser(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    FriendList::getInstance()->onCreateConnect();
    QSqlQuery query;

    query.prepare("delete from :name where name = :name");
    query.bindValue(":name", name);
    bool ret = query.exec();
    bool tmp = query.next();
    qDebug("[%s] ret = [%d]", __PRETTY_FUNCTION__, ret);
    qDebug("[%s] tmp = [%d]", __PRETTY_FUNCTION__, tmp);
    FriendList::getInstance()->onDestroyConnect();
    // addAFriendUser   <-Introduction
}

int ClientCommon::getFriendMax(QString m_name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    FriendList::getInstance()->onCreateConnect();
    QString word = "select max(ID) as maxID from " + m_name;
    int maxValue;

    QSqlQuery query(word);

    while(query.next()) {
        maxValue = query.value(0).toInt();
    }
    FriendList::getInstance()->onDestroyConnect();

    qDebug("[%s] maxValue is [%d]", __PRETTY_FUNCTION__, maxValue);
    return maxValue;
    // onMaxID   <-Introduction
}
