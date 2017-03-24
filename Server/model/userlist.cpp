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
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;
    bool ret = false;

    query.prepare("insert into user (name, keyword, state) values(:name, :keyword, :state)");
    query.bindValue(0, user->getUserName());
    query.bindValue(":keyword", user->getUserKeyword());
    query.bindValue(":state", 0);
    query.exec();

    ret = query.next();
    ControlSqlite::getInstance()->onDestroyConnect();
    return ret;
    // onAddUser   <-Introduction
}

/*
 *  onLoginUser
 *  Introduction: User login
 *  ReturnValue: login success (true), login failure (false)
 */
bool UserList::onLoginUser(UserInformation *user)
{
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;
    bool ret = false;

    query.prepare("select name,keyword from user where name = :name and keyword = :keyword");
    query.bindValue(":name", user->getUserName());
    query.bindValue(":keyword", user->getUserKeyword());
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
        query.bindValue(":name", user->getUserName());
        query.bindValue(":state", 1);
        query.exec();
    }
    ret = query.next();
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
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;

    query.prepare("update user set state = :state where name = :name");
    query.bindValue(":state", 0);
    query.bindValue(":name", user->getUserName());
    query.exec();

    ControlSqlite::getInstance()->onDestroyConnect();
    // onRemoveUser   <-Introduction
}

QString UserList::getUserNameFromServer()
{
    ControlSqlite::getInstance()->onCreateConnect();
    QSqlQuery query;

    query.prepare()
}
