#ifndef TALKINGLISTSCREEN_H
#define TALKINGLISTSCREEN_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QListWidget>
#include <QIcon>
#include <QCloseEvent>

#include "screen/addnewfriend.h"
#include "screen/makemasses.h"
#include "screen/talking.h"

namespace Ui {
class TalkingListScreen;
}

class TalkingListScreen : public QWidget
{
    Q_OBJECT

public:
    explicit TalkingListScreen(QTcpSocket *sockfd, QString name, QWidget *parent = 0);
    ~TalkingListScreen();

private slots:
    void onFreshFriendList();
    void onAddNewFriendClicked();
    void onMakeMassesClicked();
    void onTalkingWithOtherClicked(QListWidgetItem*);
    void onFeedBackFromServer();

protected:
    virtual void closeEvent(QCloseEvent* event);

private:
    QIcon onChangeFriendState(int state);
    void onShowAllFriendUser();



    QTcpSocket *m_socket;
    QString m_name;
    Ui::TalkingListScreen *ui;

    ClientCommon *m_clientCommon;

    AddNewFriend *new_addFriend;
};

#endif // TALKINGLISTSCREEN_H
