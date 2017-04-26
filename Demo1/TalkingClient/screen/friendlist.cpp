#include "friendlist.h"
#include "ui_friendlist.h"

FriendList::FriendList(QTcpSocket *sockfd, QString name, int state, QWidget *parent) :
    QWidget(parent),
    m_socket(sockfd),
    m_name(name),
    m_state(state),
    ui(new Ui::FriendList)
{
    ui->setupUi(this);

    m_clientCommon = new ClientCommon();
    new_addFriend = new AddFriend();

    ui->label_name->setText(m_name);

    addItemInCombox();

//    ui->comboBox->te

    connect(ui->btn_addFriend, SIGNAL(clicked(bool)), this, SLOT(onAddNewFriendClicked()));
    connect(ui->btn_makeMasses, SIGNAL(clicked(bool)), this, SLOT(onMakeMassesClicked()));
    connect(ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(onExitClicked()));

    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTalkingWithOther(QListWidgetItem*)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onChangeMyState(int)));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackFromServer()));
}

FriendList::~FriendList()
{
    delete ui;
}

/*
 * onAddNewFriendClicked
 * Introduction: add the screen of addFriend
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void FriendList::onAddNewFriendClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    new_addFriend->show();
    connect(new_addFriend, SIGNAL(addFriendSuccess()), this, SLOT(onFreshFriendList()));
    // onAddNewFriendClicked   <-Introduction
}

void FriendList::onMakeMassesClicked()
{

}

/*
 * onExitClicked
 * Introduction: exit this screen
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void FriendList::onExitClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    close();
    // onExitClicked   <-Introduction
}

/*
 * onTalkingWithOther
 * Introduction: open the screen of talking
 * Formal parameter: [touch the item of friend list]
 * ReturnValue: nothing
 */
void FriendList::onTalkingWithOther(QListWidgetItem *item)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    new_talking = new Talking(m_name, item->text());
    new_talking->show();
    // onTalkingWithOther   <-Introduction
}

/*
 * onChangeMyState
 * Introduction: change my state
 * Formal parameter: [change state]
 * ReturnValue: nothing
 */
void FriendList::onChangeMyState(int state)
{
    qDebug("[%s] change state is [%d]", __PRETTY_FUNCTION__, state);
    m_state = state;
    sendMyStateToFriend(m_state);
    // onChangeMyState   <-Introduction
}

void FriendList::onFeedBackFromServer()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    Package bag = m_clientCommon->onReadPackageFromServer();

    QString name = m_clientCommon->onCharToQString(bag.name);                           // name of other
    QString m_otherUser = m_clientCommon->onCharToQString(bag.otherUser);       // name of myself
    QString m_message = m_clientCommon->onCharToQString(bag.message);

    switch (bag.head) {
    case User_FindFriend:
        new_addFriend->resultOfFindFriend(name, bag.result);
        break;
    case User_Talking:

        break;
    case User_TalkingAll:

        break;
    case User_StateChange:
        showAllFriendOnList();
        break;
    default:
        break;
    }

    // onFeedBackFromServer   <-Introduction
}

/*
 * onFreshFriendList
 * Introduction: fresh the friend list
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void FriendList::onFreshFriendList()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    showAllFriendOnList();
    // onFreshFriendList   <-Introduction
}


void FriendList::showAllFriendOnList()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->listWidget->clear();



    // showAllFriendOnList   <-Introduction
}

/*
 * changeFriendState
 * Introduction: change the state from number to icon
 * Formal parameter: [number of state]
 * ReturnValue: icon of state
 */
QIcon FriendList::changeFriendState(int m_state)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QIcon f_state;

    switch (state) {
    case state_offline:
        f_state = QIcon(QObject::tr(":/new/prefix1/failure.png"));
        break;
    case state_online:
        f_state = QIcon(QObject::tr(":/new/prefix1/true.png"));
        break;
    default:
        break;
    }
    return f_state;
    // changeFriendState   <-Introduction
}

/*
 * addItemInCombox
 * Introduction: add item in combox
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void FriendList::addItemInCombox()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->comboBox->addItem(QIcon(":/new/prefix1/failure.png"), "offline");
    ui->comboBox->addItem(QIcon(":/new/prefix1/true.png"), "online");
    ui->comboBox->addItem(QIcon(":/new/prefix1/warning.png"), "hiding");
    // addItemInComBox   <-Introduction
}

/*
 * sendMyStateToFriend
 * Introduction: send my state to my friend when it has change
 * Formal parameter: [my state]
 * ReturnValue: nothing
 */
void FriendList::sendMyStateToFriend(int state)
{
    qDebug("[%s] my state is [%d]", __PRETTY_FUNCTION__, state);
    m_clientCommon->onWritePackageToServer(User_StateChange, state, m_name);
    // sendMyStateToFriend   <-Introduction
}

/*
 * closeEvent
 * Introduction: action of close the screen
 * Formal parameter: nothing
 * ReturnValue: nothing
 */
void FriendList::closeEvent()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    sendMyStateToFriend(state_offline);

    disconnect(ui->btn_addFriend, SIGNAL(clicked(bool)), this, SLOT(onAddNewFriendClicked()));
    disconnect(ui->btn_makeMasses, SIGNAL(clicked(bool)), this, SLOT(onMakeMassesClicked()));
    disconnect(ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(onExitClicked()));
    disconnect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTalkingWithOther(QListWidgetItem*)));
    disconnect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onChangeMyState(int)));

    if (NULL != new_addFriend) {
        disconnect(new_addFriend, SIGNAL(addFriendSuccess()), this, SLOT(onFreshFriendList()));
    }

    if (NULL != m_socket) {
        disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackFromServer()));
    }
    // closeEvent   <-Introduction
}
