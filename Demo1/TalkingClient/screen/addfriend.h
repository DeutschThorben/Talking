#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include <QMessageBox>

#include "model/clientcommon.h"

namespace Ui {
class AddFriend;
}

class AddFriend : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriend(ClientCommon *clientCommon, QString name, QWidget *parent = 0);
    ~AddFriend();

    void resultOfFindFriend(QString, int);

signals:

private slots:
    void onBtnFindClicked();
    void onBtnEmptyClicked();
    void onBtnExitClicked();

private:
    ClientCommon *m_clientCommon;
    QString m_name;
    Ui::AddFriend *ui;


    void whetherAgreeToFriend(QString);

    virtual void closeEvent();
};

#endif // ADDFRIEND_H
