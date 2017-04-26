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
    explicit AddFriend(QString name, QWidget *parent = 0);
    ~AddFriend();

    void resultOfFindFriend(QString, int);

signals:
    void addFriendSuccess();

private slots:
    void onBtnFindClicked();
    void onBtnEmptyClicked();
    void onBtnExitClicked();

private:
    Ui::AddFriend *ui;
    QString m_name;
    ClientCommon *m_clientCommon;

    virtual void closeEvent();
};

#endif // ADDFRIEND_H
