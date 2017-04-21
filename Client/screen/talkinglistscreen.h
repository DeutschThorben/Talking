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

enum MyState {
    State_Offline = 0,
    State_Online,
    State_Hiding,
    Nothing
};

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
    void onSetUserStateClicked(int);
    void onError();

protected:
    virtual void closeEvent();

private:
    QIcon onChangeFriendState(int state);
    void onShowAllFriendUser();

    void onFriendStateChange(QString, int);
    void onFriendStateAlreadyOnline(QString, int);
//    void onStateChange(int);

    void sendMyStateToFriend(int);
    void addItemInComBox();



    QTcpSocket *m_socket;
    QString m_name;
    int m_state;
    Ui::TalkingListScreen *ui;

    ClientCommon *m_clientCommon;

    AddNewFriend *new_addFriend;
    Talking *new_talking;


};

#endif // TALKINGLISTSCREEN_H
