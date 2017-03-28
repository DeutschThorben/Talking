#ifndef RESIGN_H
#define RESIGN_H

#include <QWidget>
#include <QMessageBox>
#include <QtNetwork/QTcpSocket>

#include "model/package.h"
#include "model/clientcommon.h"
#include <QLineEdit>
namespace Ui {
class Resign;
}

class Resign : public QWidget
{
    Q_OBJECT

public:
    explicit Resign(QTcpSocket *sockfd, QWidget *parent = 0);
    ~Resign();

    QTcpSocket *m_socked;

private slots:
    void onBtnOkClicked();
    void onBtnEmptyClicked();
    void onFeedBackRegist();

//    void onIsSameName();

signals:
//    void isSameName();

private:
    Ui::Resign *ui;


    ClientCommon *m_clientCommon;
};

#endif // RESIGN_H
