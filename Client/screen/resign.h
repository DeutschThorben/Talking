#ifndef RESIGN_H
#define RESIGN_H

#include <QWidget>
#include <QMessageBox>
#include <QLineEdit>

#include "model/package.h"
#include "model/clientcommon.h"

namespace Ui {
class Resign;
}

class Resign : public QWidget
{
    Q_OBJECT

public:
    explicit Resign(QWidget *parent = 0);
    ~Resign();
    virtual void closeEvent();

private slots:
    void onBtnOkClicked();
    void onBtnEmptyClicked();
    void onFeedBackRegist();

    // Edit label change
    void onLabelNameChange();
    void onLabelKWChange();
    void onLabelKWAgainChange();



signals:

private:
    Ui::Resign *ui;
    QTcpSocket *m_socked;

    ClientCommon *m_clientCommon;

    int m_result;
    void onLabelNameResult(int result);

};

#endif // RESIGN_H
