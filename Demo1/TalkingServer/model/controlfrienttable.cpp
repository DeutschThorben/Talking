#include "controlfrienttable.h"

ControlFrientTable* ControlFrientTable::instance = NULL;

ControlFrientTable::ControlFrientTable(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

ControlFrientTable* ControlFrientTable::getInstance()
{
    if (NULL == instance) {
        instance = new ControlFrientTable();
    }
    return instance;
    // getInstance   <-Introduction
}

void ControlFrientTable::onCreateConnect()
{
    db.setDatabaseName("../Demo1/TalkingServer/friend.db");
    db.open();
    // onCreateConnect   <-Introduction
}

void ControlFrientTable::onDestroyConnect()
{
    if (db.isOpen()) {
        db.close();
    }
    db.removeDatabase("../Demo1/TalkingServer/user.db");
    // onDestroyConnect   <-Introduction
}
