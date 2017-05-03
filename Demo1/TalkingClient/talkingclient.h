#ifndef TALKINGCLIENT_H
#define TALKINGCLIENT_H

#include <QMainWindow>
#include <QHostAddress>
#include <QMessageBox>
#include <QCloseEvent>

#include "model/clientcommon.h"

#include "screen/friendlist.h"
#include "screen/registuser.h"

namespace Ui {
class TalkingClient;
}

class TalkingClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit TalkingClient(QWidget *parent = 0);
    ~TalkingClient();

private slots:
    void onLoginClicked();
    void onRegistClicked();
    void onExitClicked();

    void onReadFromServer();

    void onChooseLoginState(int);

protected:
    virtual void closeEvent(QCloseEvent *);

private:
    int m_state;
    Ui::TalkingClient *ui;

    QTcpSocket *m_socket;
    ClientCommon *m_clientCommon;
    QString m_name;


    void addItemCombox();
};

#endif // TALKINGCLIENT_H
