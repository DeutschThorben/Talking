#ifndef USERLIST_H
#define USERLIST_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include "model/userinformation.h"
#include "model/controlsqlite.h"
#include<QDebug>

class UserList : public QObject
{
    Q_OBJECT
public:
    explicit UserList(QObject *parent = 0);

    bool onAddUser(UserInformation *user);
    bool onLoginUser(QString name, QString keyword);
    bool onIsRegisterUser(UserInformation *user);
    void onRemoveUser(QString name);
    void onDeleteUser(QString name);

    QString onSelectSomeName(int m_ID);
    bool onSelectSomeNameByName(QString);

    int onSelectSomeState(int m_ID);
    int onMaxID();

    int onListBiggerLine();

//    QString getUserNameFromServer();
    int getUserStateFromServer();

signals:

public slots:

private:
    QString user_name;
    int state;
};

#endif // USERLIST_H
