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
    void onWritePackage(PackageType head = EMPTY, QString name = "", QString keyword = "", QString otherUser = "", QString talkingInformation = "");

    const char* onQStringChangeToChar(QString b_text);
    QString onCharToQString(char *b_text);

    void setSocket(QTcpSocket*);

    void createFriendList(QString);
    void addAFriendUser(QString, QString);
    QString findAllFriendName(int, QString);
    int findAllFriendState(QString, QString);
    void deleteAFriendUser(QString name);
    int getFriendMax(QString);

signals:
    void aaa();

public slots:

private:
    explicit ClientCommon(QObject *parent = 0);

    QTcpSocket *m_socked;
    static ClientCommon *instance;
};

#endif // CLIENTCOMMON_H
