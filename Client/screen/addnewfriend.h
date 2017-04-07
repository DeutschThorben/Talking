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
    explicit AddNewFriend(QTcpSocket *sockfd, QString name, QWidget *parent = 0);
    ~AddNewFriend();

private slots:
    void onFindThisNameClicked();

    void onFeedBackFind();

signals:
    void addFriendSuccess();

private:
    QTcpSocket *m_socket;
    QString m_name;
    Ui::AddNewFriend *ui;

    ClientCommon *m_clientCommon;
};

#endif // ADDNEWFRIEND_H
