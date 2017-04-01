#include "userlist.h"

UserList::UserList(QObject *parent) : QObject(parent)
{

}

/*
 *  onAddUser
 *  Introduction: new user register
 *  ReturnValue: register success (true), register failure (false)
 */
bool UserList::onAddUser(UserInformation *user)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;
    bool ret = false;

    query.prepare("insert into user (name, keyword, state) values(:name, :keyword, :state)");
    query.bindValue(0, user->getUserName());
    query.bindValue(":keyword", user->getUserKeyword());
    query.bindValue(":state", 0);
    query.exec();

    ret = query.next();
    qDebug("[%s] A new user is add in sqlite success already", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onDestroyConnect();
    return ret;
    // onAddUser   <-Introduction
}

/*
 *  onLoginUser
 *  Introduction: User login
 *  ReturnValue: login success (true), login failure (false)
 */
bool UserList::onLoginUser(QString name, QString keyword)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;
    bool ret = false;

    query.prepare("select name,keyword from user where name = :name and keyword = :keyword");
    query.bindValue(":name", name);
    query.bindValue(":keyword", keyword);
    query.exec();

    ret = query.next();
    if (!ret) {
        // user login failure
        ControlSqlite::getInstance()->onDestroyConnect();
        return ret;
    }
    else {
        // change user state
        query.prepare("update user set state where name = :name");
        query.bindValue(":name", name);
        query.bindValue(":state", 1);
        query.exec();
    }
    ControlSqlite::getInstance()->onDestroyConnect();
    return ret;
    // onLoginUser   <-Introduction
}

/*
 *  onRegisterUser
 *  Introduction: judged username has been using
 *  ReturnValue: never use (false), is using (true)
 */
bool UserList::onIsRegisterUser(UserInformation *user)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;
    bool ret = false;

    query.prepare("select name from user where name = :name");
    query.bindValue(":name", user->getUserName());
    query.exec();

    ret = query.next();

    ControlSqlite::getInstance()->onDestroyConnect();
    return ret;
    // onRegisterUser   <-Introduction
}

/*
 *  onRemoveUser
 *  Introduction: user exit and change user state
 *  ReturnValue: nothing
 */
void UserList::onRemoveUser(UserInformation *user)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;

    query.prepare("update user set state = :state where name = :name");
    query.bindValue(":state", 0);
    query.bindValue(":name", user->getUserName());
    query.exec();

    ControlSqlite::getInstance()->onDestroyConnect();
    // onRemoveUser   <-Introduction
}

void UserList::onDeleteUser(QString name)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;

    query.prepare("delete from user where name = :name");
    query.bindValue(":name", name);
    query.exec();

    ControlSqlite::getInstance()->onDestroyConnect();
    // onDeleteUser   <-Introduction
}

//QString UserList::getUserNameFromServer()
//{
//    ControlSqlite::getInstance()->onCreateConnect();
//    QSqlQuery query;

//    query.prepare()
//}

/*
 *  onSelectSomeName
 *  Introduction: find user'name by ID
 *  ReturnValue: the name of user
 */
QString UserList::onSelectSomeName(int m_ID)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();

    QSqlQuery query;
    QString m_name;

    query.prepare("select name from user where ID = :ID");
    query.bindValue(":ID", m_ID);
    query.exec();

    while (query.next()) {
        m_name = query.value("name").toString();
        qDebug("[%s] m_name = [%s]", __PRETTY_FUNCTION__, m_name.toStdString().c_str());
    }

    ControlSqlite::getInstance()->onDestroyConnect();
    return m_name;
    // onSelectSomeName   <-Introduction
}

/*
 *  onSelectSomeState
 *  Introduction: find user'state by ID
 *  ReturnValue: the state of user
 */
int UserList::onSelectSomeState(int m_ID)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();

    QSqlQuery query;
    int m_state = 0;

    query.prepare("select state from user where ID = :ID");
    query.bindValue(":ID", m_ID);
    query.exec();

    while (query.next()) {
        m_state = query.value("state").toInt();
        qDebug("[%s] m_state = [%d]", __PRETTY_FUNCTION__, m_state);
    }
    ControlSqlite::getInstance()->onDestroyConnect();
    return m_state;
    // onSelectSomeState   <-Introduction
}

/*
 *  onListBiggerLine
 *  Introduction: get the table max line
 *  ReturnValue: the max line of table
 */
int UserList::onListBiggerLine()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query("select count(*) as numberoforders from user");
    int num = 0;

    while (query.next()) {
        num = query.value(0).toInt();
    }
    qDebug("[%s] the max line is [%d]", __PRETTY_FUNCTION__, num);
    ControlSqlite::getInstance()->onDestroyConnect();
    return num;
    // onListBiggerLine   <-Introduction
}

int UserList::onMaxID()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ControlSqlite::getInstance()->onCreateConnect();
    int maxValue;

    QSqlQuery query("select max(ID) as maxID from user");

    while(query.next()) {
        maxValue = query.value(0).toInt();
    }

    return maxValue;
    // onMaxID   <-Introduction
}
