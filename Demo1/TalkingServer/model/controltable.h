#ifndef CONTROLTABLE_H
#define CONTROLTABLE_H

#include <QObject>
#include <QSqlDatabase>

class ControlTable : public QObject
{
    Q_OBJECT
public:
    static ControlTable *getInstance();
    void onCreateConnect();
    void onDestroyConnect();

signals:

public slots:


private:
    explicit ControlTable(QObject *parent = 0);

    static ControlTable *instance;
    QSqlDatabase db;
};

#endif // CONTROLTABLE_H
