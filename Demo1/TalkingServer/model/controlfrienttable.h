#ifndef CONTROLFRIENTTABLE_H
#define CONTROLFRIENTTABLE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class ControlFrientTable : public QObject
{
    Q_OBJECT
public:
    static ControlFrientTable *getInstance();
    void onCreateConnect();
    void onDestroyConnect();

    void setDb(QSqlDatabase);
signals:

private:
    explicit ControlFrientTable(QObject *parent = 0);

    static ControlFrientTable *instance;
    QSqlDatabase db;
};

#endif // CONTROLFRIENTTABLE_H
