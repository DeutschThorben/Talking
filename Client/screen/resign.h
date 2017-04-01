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
    explicit Resign(QWidget *parent = 0);
    ~Resign();

private slots:
    void onBtnOkClicked();
    void onBtnEmptyClicked();
    void onFeedBackRegist();

    // Edit label change
    void onLabelNameChange();
    void onLabelKWChange();
    void onLabelKWAgainChange();

//    void onIsSameName();

signals:
//    void isSameName();

private:
    Ui::Resign *ui;
    QTcpSocket *m_socked;

    ClientCommon *m_clientCommon;
    void onLabelNameResult(int result);
    bool onBtnOKEnable();

};

#endif // RESIGN_H
