#ifndef TABLECOMMON_H
#define TABLECOMMON_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "model/controltable.h"

class TableCommon : public QObject
{
    Q_OBJECT
public:
    explicit TableCommon(QObject *parent = 0);

    bool onAddNewUser(QString, QString);
    bool onIsRegistUser(QString);
    bool onIsCorrectKeywordLogin(QString, QString);
    void onDeleteUser(QString);

    QString onSelectNameForID(int);
    int onGetMaxID();
    int onListBiggerLine();
signals:

public slots:
};

#endif // TABLECOMMON_H
