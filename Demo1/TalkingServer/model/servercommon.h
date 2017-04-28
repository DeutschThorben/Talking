#ifndef SERVERCOMMON_H
#define SERVERCOMMON_H

#include <QObject>
#include <QTcpSocket>

#include "model/package.h"

#include "control/socketmessage.h"

class ServerCommon : public QObject
{
    Q_OBJECT
public:
    explicit ServerCommon(QObject *parent = 0);

    // read and write
    void onWriteToClient(PackageType head = EMPTY, int result = 0, QString name = "", QString keyword = "", QString otherUser = "", QString message = "");
    Package onReadPackageFromClient();

    // Type change
    QString onCharToQString(const char*);
    const char* onQStringToChar(QString);

    // find socket of the client
    void onSetMySocket(QTcpSocket*);

    void onSetSocketMessage(SocketMessage*);

signals:

public slots:

private:
    QTcpSocket *m_sockfd;
    SocketMessage *m_message;
};

#endif // SERVERCOMMON_H
