#include "controlfrienttable.h"

ControlFrientTable* ControlFrientTable::instance = NULL;

ControlFrientTable::ControlFrientTable(QObject *parent) : QObject(parent)
{
    if (db.contains("qt_sql_default_connection")) {
        db.database("qt_sql_default_connection");
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
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
    db.setDatabaseName("../TalkingServer/friend.db");
    db.open();
    // onCreateConnect   <-Introduction
}

void ControlFrientTable::onDestroyConnect()
{
    if (db.isOpen()) {
        db.close();
    }
    db.removeDatabase("../TalkingServer/friend.db");
    // onDestroyConnect   <-Introduction
}
