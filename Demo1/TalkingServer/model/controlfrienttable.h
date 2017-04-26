#ifndef CONTROLFRIENTTABLE_H
#define CONTROLFRIENTTABLE_H

#include <QObject>
#include <QSqlDatabase>

class ControlFrientTable : public QObject
{
    Q_OBJECT
public:
    static ControlFrientTable *getInstance();
    void onCreateConnect();
    void onDestroyConnect();

signals:

private:
    explicit ControlFrientTable(QObject *parent = 0);

    static ControlFrientTable *instance;
    QSqlDatabase db;
};

#endif // CONTROLFRIENTTABLE_H
