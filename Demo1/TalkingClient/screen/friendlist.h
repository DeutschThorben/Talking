#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QWidget>
#include <QListWidget>
#include <QComboBox>
#include <QCloseEvent>

#include "model/clientcommon.h"

#include "screen/addfriend.h"
#include "screen/talking.h"

namespace Ui {
class FriendList;
}

class FriendList : public QWidget
{
    Q_OBJECT

public:
    explicit FriendList(ClientCommon* clientCommon, QString name, int state, QWidget *parent = 0);
    ~FriendList();

private slots:
    // action of button
    void onAddNewFriendClicked();
    void onMakeMassesClicked();
    void onExitClicked();

    // action of friend list
    void onTalkingWithOther(QListWidgetItem*);

    // change the state of my
    void onChangeMyState(int);

    // message from server
    void onFeedBackFromServer();

protected:
    virtual void closeEvent(QCloseEvent *);

private:
    ClientCommon *m_clientCommon;
    QString m_name;
    int m_state;
    int tmp;
    Ui::FriendList *ui;

    QTcpSocket *m_socket;
    AddFriend *new_addFriend;
    Talking *new_talking;


    void showAllFriendOnList(ShowFriendList);
    QIcon changeFriendState(int);
    void addItemInCombox();

    void sendMyStateToFriend(int);
};

#endif // FRIENDLIST_H
