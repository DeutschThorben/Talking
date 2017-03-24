#include "controlsqlite.h"

ControlSqlite* ControlSqlite::instance = NULL;

ControlSqlite::ControlSqlite(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

ControlSqlite* ControlSqlite::getInstance()
{
    if (NULL == instance) {
        instance = new ControlSqlite();
    }
    return instance;
}

void ControlSqlite::onCreateConnect()
{
    db.setDatabaseName("../user.db");
    db.open();
}

void ControlSqlite::onDestroyConnect()
{
    if (db.isOpen()) {
        db.close();
    }
    db.removeDatabase("../user.db");
}
