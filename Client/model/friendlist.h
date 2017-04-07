#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QObject>
#include <QSqlDatabase>

class FriendList : public QObject
{
    Q_OBJECT
public:
    static FriendList *getInstance();
    void onCreateConnect();
    void onDestroyConnect();
signals:

public slots:

private:
    explicit FriendList(QObject *parent = 0);

    static FriendList *instance;
    QSqlDatabase db;
};

#endif // FRIENDLIST_H
