#ifndef CLIENTCOMMON_H
#define CLIENTCOMMON_H

#include <QObject>
#include <QTcpSocket>

#include "model/package.h"

enum result_Action {
    result_Failure = 0,
    result_Success,
    result_HasName,
    result_NotFindName,
    result_KeywordMistake,
    result_WhetherAgreeFriend,
    result_AgreeFriend,
    result_WantFriend,
    result_alreadyLoading
};

enum myState {
    state_offline,
    state_online,
    state_hiding
};

class ClientCommon : public QObject
{
    Q_OBJECT
public:
    explicit ClientCommon(QObject *parent = 0);

    Package onReadPackageFromServer();
    void onWritePackageToServer(PackageType head = EMPTY, int result = 0, QString name = "", QString keyword = "", QString otherUser = "", QString message = "");

    void onSetSocket(QTcpSocket*);
    QTcpSocket* onGetSocket();

    const char* onQStringChangeToChar(QString b_text);
    QString onCharToQString(char *b_text);

signals:

public slots:

private:

    QTcpSocket *u_socket;
};

#endif // CLIENTCOMMON_H
