#ifndef USERLIST_H
#define USERLIST_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "model/userinformation.h"
#include "model/controlsqlite.h"

class UserList : public QObject
{
    Q_OBJECT
public:
    explicit UserList(QObject *parent = 0);

    bool onAddUser(UserInformation *user);
    bool onLoginUser(UserInformation *user);
    bool onIsRegisterUser(UserInformation *user);
    void onRemoveUser(UserInformation *user);

//    QString getUserNameFromServer();
    int getUserStateFromServer();

signals:

public slots:

private:
    QString user_name;
    int state;
};

#endif // USERLIST_H
