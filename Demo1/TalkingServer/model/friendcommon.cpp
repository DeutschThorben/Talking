#include "friendcommon.h"

FriendCommon::FriendCommon(QObject *parent) : QObject(parent)
{

}

/*
 * onCreateFriendList
 * Introduction: create a new friend table for new user
 * Formal parameter: [new user's name]
 * ReturnValue: nothing
 */
void FriendCommon::onCreateFriendList(QString m_name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlFrientTable::getInstance()->onCreateConnect();
    QSqlQuery query;
    QString word = "create table " + m_name +" (ID integer primary key autoincrement, name verchar(20))";

    bool ret = query.exec(word);
    bool tmp = query.next();
    qDebug("[%s] ret = [%d]", __PRETTY_FUNCTION__, ret);
    qDebug("[%s] tmp = [%d]", __PRETTY_FUNCTION__, tmp);
    ControlFrientTable::getInstance()->onDestroyConnect();
    // onCreateFriendList   <-Introduction
}

/*
 * onAddNewFriend
 * Introduction: insert a new friend to friend list
 * Formal parameter: [user's name, new friend's name]
 * ReturnValue: nothing
 */
 void FriendCommon::onAddNewFriend(QString m_name, QString f_name)
 {
     qDebug("[%s]", __PRETTY_FUNCTION__);
     ControlFrientTable::getInstance()->onCreateConnect();
     QSqlQuery query;
     QString word = "insert into " + m_name + " (name) values (:name)";

     query.prepare(word);
     query.bindValue(":name", f_name);
     bool ret = query.exec();

     qDebug("[%s] ret = [%d]", __PRETTY_FUNCTION__, ret);
     ControlFrientTable::getInstance()->onDestroyConnect();
     // onAddNewFriend   <-Introduction
 }

 /*
  * onSelectNameForID
  * Introduction: select name for ID, when show all user is using
  * Formal parameter: [select ID]
  * ReturnValue: want select name
  */
 QString FriendCommon::onSelectNameForID(QString name, int n_ID)
 {
     ControlFrientTable::getInstance()->onCreateConnect();
     QSqlQuery query;
     QString word = "select name from " + name + " where ID = :ID";
     QString result_name;

     query.prepare(word);
     query.bindValue(":ID", n_ID);
     query.exec();
     while (query.next()) {
         result_name = query.value("name").toString();
     }

     ControlFrientTable::getInstance()->onDestroyConnect();
     return result_name;
     // onSelectNameForID   <-Introduction
 }

 /*
  * onGetMaxID
  * Introduction: get the max ID of user table
  * Formal parameter: nothing
  * ReturnValue: the max ID of table
  */
 int FriendCommon::onGetMaxID(QString name)
 {
     qDebug("[%s] select_name is [%s]", __PRETTY_FUNCTION__, name.toStdString().c_str());
     ControlFrientTable::getInstance()->onCreateConnect();
     int maxValue = 0;
     QString word = "select max(ID) as maxID from " + name;

     QSqlQuery query(word);
     query.exec();
     while (query.next()) {
         maxValue = query.value(0).toInt();
     }
     ControlFrientTable::getInstance()->onDestroyConnect();
     qDebug("[%s] maxValue is [%d]", __PRETTY_FUNCTION__, maxValue);
     return maxValue;
     // onGetMaxID   <-Introduction
 }

 /*
  * onListBiggerLine
  * Introduction: get the max line of user table
  * Formal parameter: nothing
  * ReturnValue: the max line of table
  */
 int FriendCommon::onListBiggerLine(QString name)
 {
     ControlFrientTable::getInstance()->onCreateConnect();
     QString word = "select count(*) as numberoforders from " + name;
     QSqlQuery query;
     query.prepare(word);
     query.exec();
     int maxNum = 0;

     while (query.next()) {
         maxNum = query.value(0).toInt();
     }
     ControlFrientTable::getInstance()->onDestroyConnect();
     return maxNum;
     // onListBiggerLine   <-Introduction
 }
