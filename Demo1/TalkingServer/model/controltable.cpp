#include "controltable.h"

ControlTable* ControlTable::instance = NULL;

ControlTable::ControlTable(QObject *parent) : QObject(parent)
{
    if (db.contains("qt_sql_default_connection")) {
        db.database("qt_sql_default_connection");
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
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
    db.setDatabaseName("../TalkingServer/user.db");
    db.open();
    // onCreateConnect   <-Introduction
}

void ControlTable::onDestroyConnect()
{
    if (db.isOpen()) {
        db.close();
    }
    db.removeDatabase("../TalkingServer/user.db");
    // onDestroyConnect   <-Introduction
}
