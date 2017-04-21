#include "tablecommon.h"

TableCommon::TableCommon(QObject *parent) : QObject(parent)
{

}

/*
 * onAddNewUser
 * Introduction: new user register and add it into table
 * Formal parameter: [new name, new keyword]
 * ReturnValue: register success (true), register failure (false)
 */
bool TableCommon::onAddNewUser(QString new_name, QString new_keyword)
{
    ControlTable::getInstance()->onCreateConnect();
    QSqlQuery query;
    bool result = false;

    query.prepare("insert into user (name, keyword) values (:name, :keyword)");
    query.bindValue(":name", new_name);
    query.bindValue(":keyword", new_keyword);
    result = query.exec();

    qDebug("[%s] A new user is add in sqlite success already ret = [%d]", __PRETTY_FUNCTION__, result);
    ControlTable::getInstance()->onDestroyConnect();
    return result;
    // onAddNewUser   <-Introduction
}

/*
 * onIsRegistUser
 * Introduction: whether the name is have in user table
 * Formal parameter: [select name]
 * ReturnValue: the name is have (true), not have (false)
 */
bool TableCommon::onIsRegistUser(QString n_name)
{
    ControlTable::getInstance()->onCreateConnect();
    QSqlQuery query;
    bool result = false;

    query.prepare("select name from user where name = :name");
    query.bindValue(":name", n_name);
    query.exec();

    result = query.next();
    qDebug("[%s] Is this name in table [%d]", __PRETTY_FUNCTION__, result);
    ControlTable::getInstance()->onDestroyConnect();
    return result;
    // onAddNewUser   <-Introduction
}

/*
 * onIsCorrectKeywordLogin
 * Introduction: whether the keyword of the name is correct
 * Formal parameter: [select name, select keyword]
 * ReturnValue: keyword is correct (true), mistake (false)
 */
bool TableCommon::onIsCorrectKeywordLogin(QString n_name, QString n_keyword)
{
    ControlTable::getInstance()->onCreateConnect();
    QSqlQuery query;
    bool result = false;

    query.prepare("select name,keyword from user where name = :name and keyword = :keyword");
    query.bindValue(":name", n_name);
    query.bindValue(":keyword", n_keyword);
    query.exec();
    result = query.next();

    qDebug("[%s] Keyword is [%d]", __PRETTY_FUNCTION__, result);
    ControlTable::getInstance()->onDestroyConnect();
    return result;
    // onIsCorrectKeywordLogin   <-Introduction
}

/*
 * onDeleteUser
 * Introduction: delete a user from table
 * Formal parameter: [delete name]
 * ReturnValue: nothing
 */
void TableCommon::onDeleteUser(QString n_name)
{
    ControlTable::getInstance()->onCreateConnect();
    QSqlQuery query;

    query.prepare("delete from user where name = :name");
    query.bindValue(":name", n_name);
    query.exec();

    ControlTable::getInstance()->onDestroyConnect();
    // onDeleteUser   <-Introduction
}

/*
 * onSelectNameForID
 * Introduction: select name for ID, when show all user is using
 * Formal parameter: [select ID]
 * ReturnValue: want select name
 */
QString TableCommon::onSelectNameForID(int n_ID)
{
    ControlTable::getInstance()->onCreateConnect();
    QSqlQuery query;
    QString result_name;

    query.prepare("select name from user where ID = :ID");
    query.bindValue(":ID", n_ID);
    query.exec();
    while (query.next()) {
        result_name = query.value("name").toString();
    }

    ControlTable::getInstance()->onDestroyConnect();
    return result_name;
    // onSelectNameForID   <-Introduction
}

/*
 * onGetMaxID
 * Introduction: get the max ID of user table
 * Formal parameter: nothing
 * ReturnValue: the max ID of table
 */
int TableCommon::onGetMaxID()
{
    ControlTable::getInstance()->onCreateConnect();
    int maxValue = 0;

    QSqlQuery query("select max(ID) as maxID from user");
    while (query.next()) {
        maxValue = query.value(0).toInt();
    }
    ControlTable::getInstance()->onDestroyConnect();
    return maxValue;
    // onGetMaxID   <-Introduction
}

/*
 * onListBiggerLine
 * Introduction: get the max line of user table
 * Formal parameter: nothing
 * ReturnValue: the max line of table
 */
int TableCommon::onListBiggerLine()
{
    ControlTable::getInstance()->onCreateConnect();
    QSqlQuery query("select count(*) as numberoforders from user");
    int maxNum = 0;

    while (query.next()) {
        maxNum = query.value(0).toInt();
    }
    ControlTable::getInstance()->onDestroyConnect();
    return maxNum;
    // onListBiggerLine   <-Introduction
}
