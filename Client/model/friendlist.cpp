#include "friendlist.h"

FriendList* FriendList::instance = NULL;

FriendList::FriendList(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

FriendList* FriendList::getInstance()
{
    if (NULL == instance) {
        instance = new FriendList();
    }
    return instance;
}

void FriendList::onCreateConnect()
{
    db.setDatabaseName("../friendList.db");
    db.open();
}

void FriendList::onDestroyConnect()
{
    if (db.isOpen()) {
        db.close();
    }
    db.removeDatabase("../friendList.db");
}
