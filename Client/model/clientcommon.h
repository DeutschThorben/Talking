#ifndef CLIENTCOMMON_H
#define CLIENTCOMMON_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include "model/package.h"

class ClientCommon : public QObject
{
    Q_OBJECT
public:
    explicit ClientCommon(QTcpSocket *sockfd, QObject *parent = 0);

    Package onReadPackage();
    void onWritePackage(PackageType head = EMPTY, QString name = "", QString keyword = "", QString otherUser = "", QString talkingInformation = "");

signals:

public slots:

private:
    QTcpSocket *m_socked;
};

#endif // CLIENTCOMMON_H
