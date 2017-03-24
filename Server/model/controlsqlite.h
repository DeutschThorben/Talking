#ifndef CONTROLSQLITE_H
#define CONTROLSQLITE_H

#include <QObject>
#include <QSqlDatabase>

class ControlSqlite : public QObject
{
    Q_OBJECT
public:
    static ControlSqlite *getInstance();
    void onCreateConnect();
    void onDestroyConnect();

signals:

public slots:

private:
    explicit ControlSqlite(QObject *parent = 0);

    static ControlSqlite *instance;
    QSqlDatabase db;
};

#endif // CONTROLSQLITE_H
