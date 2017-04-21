#ifndef ADDNEWFRIEND_H
#define ADDNEWFRIEND_H

#include <QWidget>
#include <QMessageBox>

#include "model/clientcommon.h"
#include "model/package.h"


namespace Ui {
class AddNewFriend;
}

class AddNewFriend : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewFriend(QString name, QWidget *parent = 0);
    ~AddNewFriend();

    void onFindFriendIsSuccess(int = 0, QString = "");

private slots:
    void onFindThisNameClicked();
    void onExitScreenClicked();

signals:
    void addFriendSuccess();

protected:
    virtual void closeEvent();

private:
    QString m_name;
    Ui::AddNewFriend *ui;

    ClientCommon *m_clientCommon;
};

#endif // ADDNEWFRIEND_H
