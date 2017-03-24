#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include "model/package.h"

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();



private slots:
    void onBtnLoginClicked();
    void onBtnRegistClicked();
    void onBtnExitClicked();

private:
    Ui::Client *ui;

    QTcpSocket *m_socked;

    Package onReadPackage();
    void onWritePackage(PackageType head = EMPTY, QString name = "", QString keyword = "", QString otherUser = "", QString talkingInformation = "");
};

#endif // CLIENT_H
