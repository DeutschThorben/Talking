#include "friendlist.h"
#include "ui_friendlist.h"

FriendList::FriendList(ClientCommon* clientCommon, QString name, int state, QWidget *parent) :
    QWidget(parent),
    m_clientCommon(clientCommon),
    m_name(name),
    m_state(state),
    ui(new Ui::FriendList)
{
    ui->setupUi(this);

    m_socket = m_clientCommon->onGetSocket();

    new_addFriend = new AddFriend(m_clientCommon, m_name);

    ui->label_name->setText(m_name);

    addItemInCombox();

//    ui->comboBox->te

    connect(ui->btn_addFriend, SIGNAL(clicked(bool)), this, SLOT(onAddNewFriendClicked()));
    connect(ui->btn_makeMasses, SIGNAL(clicked(bool)), this, SLOT(onMakeMassesClicked()));
    connect(ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(onExitClicked()));

    connect(ui->list_friend, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTalkingWithOther(QListWidgetItem*)));
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
    ShowFriendList f_bag;
    m_socket->read((char*)(&f_bag), sizeof(ShowFriendList));

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
    case User_FriendList:
        showAllFriendOnList(f_bag);
        break;
    default:
        break;
    }

    // onFeedBackFromServer   <-Introduction
}

/*
 * showAllFriendOnList
 * Introduction: show my friend list to screen
 * Formal parameter: [frient list from server]
 * ReturnValue: nothing
 */
void FriendList::showAllFriendOnList(ShowFriendList f_bag)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->list_friend->clear();
    QString f_name;
    int f_state;

    for (int i = 0; i < f_bag.i; i++) {
        f_name = m_clientCommon->onCharToQString(f_bag.f_name[i]);
        f_state = f_bag.f_state[i];
        QListWidgetItem *f_item = new QListWidgetItem(changeFriendState(f_state), QObject::tr(f_name.toStdString().c_str()));
        ui->list_friend->addItem(f_item);
    }
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
    qDebug("[%s] state is [%d]", __PRETTY_FUNCTION__, m_state);
    QIcon f_state;

    switch (m_state) {
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
    ui->comboBox->addItem(QIcon(":/new/prefix1/picture/offline.png"), "offline");
    ui->comboBox->addItem(QIcon(":/new/prefix1/picture/online.png"), "online");
    ui->comboBox->addItem(QIcon(":/new/prefix1/picture/hiding.png"), "hiding");
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
    disconnect(ui->list_friend, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTalkingWithOther(QListWidgetItem*)));
    disconnect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onChangeMyState(int)));

    if (NULL != m_socket) {
        disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackFromServer()));
    }
    // closeEvent   <-Introduction
}
