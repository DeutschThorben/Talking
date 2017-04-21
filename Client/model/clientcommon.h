#ifndef CLIENTCOMMON_H
#define CLIENTCOMMON_H

#include <QObject>
#include <QSqlQuery>
#include <QtNetwork/QTcpSocket>

#include "model/package.h"
#include "model/friendlist.h"

class ClientCommon : public QObject
{
    Q_OBJECT
public:
    static ClientCommon* getInstance();

    Package onReadPackage();
    void onWritePackage(PackageType head = EMPTY, QString name = "", QString keyword = "", QString otherUser = "", QString talkingInformation = "", int result = 0);

    const char* onQStringChangeToChar(QString b_text);
    QString onCharToQString(char *b_text);

    void setSocket(QTcpSocket*);

    // create new friend table when a new user has registed
    void createFriendList(QString);

    // add a new friend to friend list
    void addAFriendUser(QString, QString);

    // take all name of friend to screen
    QString findAllFriendName(int, QString);

    // take all state of friend to screen
    int findAllFriendState(QString, QString);

    // select a name from friend list
    bool selectNameFromFriendList(QString, QString);

    // change user state
    void changeFriendState(QString, QString, int);

    // delete a friend
    void deleteAFriendUser(QString, QString);

    // get max number of friend
    int getFriendMax(QString);

signals:

public slots:

private:
    explicit ClientCommon(QObject *parent = 0);

    QTcpSocket *m_socked;
    static ClientCommon *instance;
};

#endif // CLIENTCOMMON_H
