#include "talkinglistscreen.h"
#include "ui_talkinglistscreen.h"

TalkingListScreen::TalkingListScreen(QTcpSocket *sockfd, QString name, QWidget *parent) :
    QWidget(parent),
    m_socket(sockfd),
    m_name(name),
    m_state(State_Online),
    ui(new Ui::TalkingListScreen)
{
    ui->setupUi(this);

    // send my socket to common
    m_clientCommon = ClientCommon::getInstance();
    m_clientCommon->setSocket(sockfd);

    new_addFriend = new AddNewFriend(m_name);

//    setAttribute(Qt::WA_DeleteOnClose);

    // fresh friend list
    onShowAllFriendUser();

    // set state combox
    addItemInComBox();

    // set user name
    ui->label_name->setText(name);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackFromServer()));
    connect(ui->btn_addNewFriend, SIGNAL(clicked()), this, SLOT(onAddNewFriendClicked()));
    connect(ui->btn_makeMasses, SIGNAL(clicked()), this, SLOT(onMakeMassesClicked()));
    connect(ui->comboBox_state, SIGNAL(currentIndexChanged(int)), this, SLOT(onSetUserStateClicked(int)));
    connect(ui->list_friend, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTalkingWithOtherClicked(QListWidgetItem*)));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError()));
}

TalkingListScreen::~TalkingListScreen()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    disconnect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError()));

    delete m_clientCommon;
    delete new_addFriend;
    delete ui;

    m_clientCommon = NULL;
    new_addFriend = NULL;
}

/*
 *  onAddNewFriendClicked
 *  Introduction: open screen of AddnewFriend
 *  Formal parameter: nothing
 *  ReturnValue: nothing
 */
void TalkingListScreen::onAddNewFriendClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    new_addFriend->show();
    connect(new_addFriend, SIGNAL(addFriendSuccess()), this, SLOT(onFreshFriendList()));
    // onAddNewFriendClicked   <-Introduction
}

void TalkingListScreen::onMakeMassesClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    MakeMasses *new_makeMasses = new MakeMasses();
    new_makeMasses->show();
    // onMakeMassesClicked   <-Introduction
}

void TalkingListScreen::onTalkingWithOtherClicked(QListWidgetItem* item)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QString m_otherName = item->text();

    new_talking = new Talking(m_name, m_otherName);
    new_talking->show();
    // onTalkingWithOtherClicked   <-Introduction
}

/*
 *  onSetUserStateClicked
 *  Introduction: choose myself's state
 *  Formal parameter: nothing
 *  ReturnValue: nothing
 */
void TalkingListScreen::onSetUserStateClicked(int state)
{
    qDebug("[%s] state is [%d]", __PRETTY_FUNCTION__, state);
    m_state = state;
    sendMyStateToFriend(State_Online);
    // onSetUserStateClicked   <-Introduction
}

/*
 *  onShowAllFriendUser
 *  Introduction: show all friend in screen from table
 *  Formal parameter: nothing
 *  ReturnValue: nothing
 */
void TalkingListScreen::onShowAllFriendUser()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->list_friend->clear();

    QString friend_name;
    int friend_state;
    int friend_max = m_clientCommon->getFriendMax(m_name);

    qDebug("[%s] friend_max is [%d]", __PRETTY_FUNCTION__, friend_max);
    for (int ID = 1; ID <= friend_max; ID++) {
        friend_name = m_clientCommon->findAllFriendName(ID, m_name);
        if ("" != friend_name) {
            friend_state = m_clientCommon->findAllFriendState(friend_name, m_name);
            QListWidgetItem *m_qlistItem = new QListWidgetItem(onChangeFriendState(friend_state), QObject::tr(friend_name.toStdString().c_str()));
            ui->list_friend->addItem(m_qlistItem);
        }
    }
    // onShowAllFriendUser   <-Introduction
}

/*
 *  onChangeFriendState
 *  Introduction: change friend's state from number to icon
 *  Formal parameter: [friend's state (online-1/offline-0)]
 *  ReturnValue: online (1), offline (0)
 */
QIcon TalkingListScreen::onChangeFriendState(int state)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QIcon f_state;

    switch (state) {
    case State_Offline:
        f_state = QIcon(QObject::tr(":/new/prefix1/failure.png"));
        break;
    case State_Online:
        f_state = QIcon(QObject::tr(":/new/prefix1/true.png"));
        break;
    default:
        break;
    }

    return f_state;
    // onChangeFriendState   <-Introduction
}

/*
 *  onFreshFriendList
 *  Introduction: Fresh friend's list
 *  Formal parameter: nothing
 *  ReturnValue: nothing
 */
void TalkingListScreen::onFreshFriendList()
{
    onShowAllFriendUser();
    // onFreshFriendList   <-Introduction
}

void TalkingListScreen::closeEvent()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    sendMyStateToFriend(State_Offline);

    disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(onFeedBackFromServer()));
    disconnect(ui->btn_addNewFriend, SIGNAL(clicked()), this, SLOT(onAddNewFriendClicked()));
    disconnect(ui->btn_makeMasses, SIGNAL(clicked()), this, SLOT(onMakeMassesClicked()));
    disconnect(ui->comboBox_state, SIGNAL(currentIndexChanged(int)), this, SLOT(onSetUserStateClicked(int)));
    disconnect(ui->list_friend, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTalkingWithOtherClicked(QListWidgetItem*)));
    disconnect(new_addFriend, SIGNAL(addFriendSuccess()), this, SLOT(onFreshFriendList()));
}

void TalkingListScreen::onFeedBackFromServer()
{
    Package bag = m_clientCommon->onReadPackage();
    qDebug("[%s] head is [%d]", __PRETTY_FUNCTION__, bag.head);

    QString m_name = m_clientCommon->onCharToQString(bag.otherUser);
    QString f_name = m_clientCommon->onCharToQString(bag.name);
    QString f_message = m_clientCommon->onCharToQString(bag.talkingInformation);

    switch (bag.head) {
    case USER_StateChange:
        qDebug("[%s] Add new friend [%s]", __PRETTY_FUNCTION__, m_name.toStdString().c_str());
        onFriendStateChange(m_name, bag.result);
        break;
    case USER_FindFriend:
        new_addFriend->onFindFriendIsSuccess(bag.result);
        break;
     case USER_Online_Back:
        qDebug("[%s] Already online friend is [%s], state is [%d]", __PRETTY_FUNCTION__, f_name.toStdString().c_str(), bag.result);
//        onFriendStateAlreadyOnline(f_name, bag.result);
        break;
     case USER_Talking:
        qDebug("[%s] Message from other [%s]", __PRETTY_FUNCTION__, f_message.toStdString().c_str());
        new_talking->MessageFromOther(f_message);
        break;
    default:
        break;
    }
    // onFeedBackFromServer   <-Introduction
}

/*
 *  onFriendStateChange
 *  Introduction: Fresh friend list
 *  Formal parameter: [friend's name, friend's state (online-1/offline-0)]
 *  ReturnValue: nothing
 */
void TalkingListScreen::onFriendStateChange(QString f_name, int state)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    if (m_clientCommon->selectNameFromFriendList(f_name, m_name)) {
        // change friend state in friend's table
        m_clientCommon->changeFriendState(f_name, m_name, state);
        if (State_Online == state) {
            // send myself state to my friend
            if (State_Online == m_state) {
                sendMyStateToFriend(State_Online);
            }
        }
        // fresh friend list
        onShowAllFriendUser();
    }
    // onFriendStateChange   <-Introduction
}

//void TalkingListScreen::onFriendStateAlreadyOnline(QString f_name, int state)
//{
//    qDebug("[%s]", __PRETTY_FUNCTION__);
//    if (m_clientCommon->selectNameFromFriendList(f_name, m_name)) {
//        // change friend state in friend's table
//        m_clientCommon->changeFriendState(f_name, m_name, state);
//    }
//    onShowAllFriendUser();
//    // onFriendStateAlreadyOnline   <-Introduction
//}

//void TalkingListScreen::onStateChange(int state)
//{
//    qDebug("[%s]", __PRETTY_FUNCTION__);
//    m_clientCommon->onWritePackage(USER_StateChange, m_name, "", "", "", state);
//    // onStateChange   <-Introduction
//}

void TalkingListScreen::sendMyStateToFriend(int m_state)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    m_clientCommon->onWritePackage(USER_StateChange, m_name, "", "", "", m_state);
    // sendMyStateToFriend   <-Introduction
}

void TalkingListScreen::addItemInComBox()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    ui->comboBox_state->addItem(QIcon(":/new/prefix1/failure.png"), "offline");
    ui->comboBox_state->addItem(QIcon(":/new/prefix1/true.png"), "online");
    ui->comboBox_state->addItem(QIcon(":/new/prefix1/warning.png"), "hiding");
    // addItemInComBox   <-Introduction
}

void TalkingListScreen::onError()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);

    // onError   <-Introduction
}

