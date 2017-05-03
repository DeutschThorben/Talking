#ifndef USERINFORMATION_H
#define USERINFORMATION_H

#include <QObject>

class UserInformation : public QObject
{
    Q_OBJECT
public:
    explicit UserInformation(QObject *parent = 0);

signals:

public slots:
};

#endif // USERINFORMATION_H
