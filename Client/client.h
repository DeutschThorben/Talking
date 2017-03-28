#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

#include "model/package.h"
#include "model/clientcommon.h"

#include "screen/resign.h"
#include "screen/talking.h"

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

    void onReadFromServer();

private:
    Ui::Client *ui;

    // Resign *m_resign;
    QTcpSocket *m_socked;
    ClientCommon *m_clientCommon;
};

#endif // CLIENT_H
