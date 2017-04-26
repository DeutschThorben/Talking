#ifndef REGISTUSER_H
#define REGISTUSER_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>

#include "model/clientcommon.h"

namespace Ui {
class RegistUser;
}

class RegistUser : public QWidget
{
    Q_OBJECT

public:
    explicit RegistUser(QWidget *parent = 0);
    ~RegistUser();

private slots:
    void onOKClicked();
    void onEmptyClicked();

    void onFeedBackRegist();

    void onLabelNameChange();
    void onLabelKWChange();
    void onLabelKWAChange();

private:
    Ui::RegistUser *ui;

    QTcpSocket *m_socket;
    ClientCommon *m_clientCommon;

    int m_result;

    void onLabelNameResult(int);
};

#endif // REGISTUSER_H
