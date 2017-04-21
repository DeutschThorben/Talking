#include "controltable.h"

ControlTable* ControlTable::instance = NULL;

ControlTable::ControlTable(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

ControlTable* ControlTable::getInstance()
{
    if (NULL == instance) {
        instance = new ControlTable();
    }
    return instance;
    // getInstance   <-Introduction
}

void ControlTable::onCreateConnect()
{
    db.setDatabaseName("../Demo1/TalkingServer/user.db");
    db.open();
    // onCreateConnect   <-Introduction
}

void ControlTable::onDestroyConnect()
{
    if (db.isOpen()) {
        db.close();
    }
    db.removeDatabase("../Demo1/TalkingServer/user.db");
    // onDestroyConnect   <-Introduction
}
