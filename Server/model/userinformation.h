#ifndef USERINFORMATION_H
#define USERINFORMATION_H

#include <QObject>

class UserInformation : public QObject
{
    Q_OBJECT
public:
    explicit UserInformation(QString name, QString keyword, QObject *parent = 0);

    int getUserID();
    QString getUserKeyword();
    QString getUserName();
    QString getUserState();

signals:

public slots:

private:
    int m_userID;
    QString m_userKeyword;
    QString m_userName;
    QString m_userState;
};

#endif // USERINFORMATION_H
