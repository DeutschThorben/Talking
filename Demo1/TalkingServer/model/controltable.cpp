#include "controltable.h"

ControlTable* ControlTable::instance = NULL;

ControlTable::ControlTable(QObject *parent) : QObject(parent)
{
    if (db.contains("qt_sql_default_connection")) {
        db.database("qt_sql_default_connection");
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        ControlFrientTable::getInstance()->setDb(db);
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
    bool tmp = false;


    tmp = db.open();
    qDebug("[%s] tmp is [%d]", __PRETTY_FUNCTION__,tmp);
    QSqlError ret = db.lastError();
    qDebug("[%s] databaseText is [%s]", __PRETTY_FUNCTION__, ret.databaseText().toStdString().c_str());
    qDebug("[%s] Error Type is [%d]", __PRETTY_FUNCTION__, ret.type());
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
