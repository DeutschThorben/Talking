#ifndef FRIENDCOMMON_H
#define FRIENDCOMMON_H

#include <QObject>
#include <QSqlQuery>
#include <QVariant>

#include "model/controlfrienttable.h"

class FriendCommon : public QObject
{
    Q_OBJECT
public:
    explicit FriendCommon(QObject *parent = 0);

    // create a user's friend table
    void onCreateFriendList(QString);
    // add a new friend
    void onAddNewFriend(QString, QString);

    QString onSelectNameForID(QString, int);
    int onGetMaxID(QString);
    int onListBiggerLine(QString);
signals:

public slots:
};

#endif // FRIENDCOMMON_H
