#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QWidget>
#include <QListWidget>
#include <QComboBox>

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


private:
    QTcpSocket *m_socket;
    QString m_name;
    Ui::FriendList *ui;

    ClientCommon *m_clientCommon;
    AddFriend *new_addFriend;
    Talking *new_talking;

    int m_state;



    void showAllFriendOnList(ShowFriendList);
    QIcon changeFriendState(int);
    void addItemInCombox();

    void sendMyStateToFriend(int);
    virtual void closeEvent();
};

#endif // FRIENDLIST_H
