#include "controlfrienttable.h"
#include<QDebug>

ControlFrientTable* ControlFrientTable::instance = NULL;

ControlFrientTable::ControlFrientTable(QObject *parent) : QObject(parent)
{
    qDebug("[%s]111111111", __PRETTY_FUNCTION__);
//    if (db.contains("qt_sql_default_connection")) {
//        qDebug("[%s]222222222", __PRETTY_FUNCTION__);
//        db.database("qt_sql_default_connection");
//    }
//    else {
//        db = QSqlDatabase::addDatabase("QSQLITE");

        qDebug("[%s] isValid is [%d]", __PRETTY_FUNCTION__,db.isValid());
        qDebug() << db.databaseName();
//    }
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
    db.setDatabaseName("friend.db");
    db.open();

    QSqlError ret = db.lastError();
    qDebug("[%s] databaseText is [%s]", __PRETTY_FUNCTION__, ret.databaseText().toStdString().c_str());
    qDebug("[%s] Error Type is [%d]", __PRETTY_FUNCTION__, ret.type());
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

void ControlFrientTable::setDb(QSqlDatabase m_db)
{
    db = m_db;
}
