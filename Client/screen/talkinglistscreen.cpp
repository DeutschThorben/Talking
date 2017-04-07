#include "talkinglistscreen.h"
#include "ui_talkinglistscreen.h"

TalkingListScreen::TalkingListScreen(QTcpSocket *sockfd, QString name, QWidget *parent) :
    QWidget(parent),
    m_socket(sockfd),
    m_name(name),
    ui(new Ui::TalkingListScreen)
{
    ui->setupUi(this);
    m_clientCommon = ClientCommon::getInstance();
    m_clientCommon->setSocket(sockfd);
    new_addFriend = new AddNewFriend(m_socket, m_name);

    qDebug("[%s]111111", __PRETTY_FUNCTION__);
    setAttribute(Qt::WA_DeleteOnClose);
qDebug("[%s]222222222", __PRETTY_FUNCTION__);

    onShowAllFriendUser();

    connect(ui->btn_addNewFriend, SIGNAL(clicked()), this, SLOT(onAddNewFriendClicked()));
    connect(ui->btn_makeMasses, SIGNAL(clicked()), this, SLOT(onMakeMassesClicked()));
    connect(ui->list_friend, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTalkingWithOtherClicked(QListWidgetItem*)));

}

TalkingListScreen::~TalkingListScreen()
{

    disconnect(ui->btn_addNewFriend, SIGNAL(clicked()), this, SLOT(onAddNewFriendClicked()));
    disconnect(ui->btn_makeMasses, SIGNAL(clicked()), this, SLOT(onMakeMassesClicked()));
    disconnect(ui->list_friend, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onTalkingWithOtherClicked(QListWidgetItem*)));
    disconnect(new_addFriend, SIGNAL(addFriendSuccess()), this, SLOT(onFreshFriendList()));

    delete m_clientCommon;
    delete ui;
}

void TalkingListScreen::onAddNewFriendClicked()
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
//    AddNewFriend *new_addFriend = new AddNewFriend(m_socket, m_name);
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

    Talking *new_talking = new Talking(m_socket, m_name, m_otherName);
    new_talking->show();
    // onTalkingWithOtherClicked   <-Introduction
}

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

QIcon TalkingListScreen::onChangeFriendState(int state)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    QIcon f_state;

    switch (state) {
    case 0:
        f_state = QIcon(QObject::tr(":/new/prefix1/failure.png"));
        break;
    case 1:
        f_state = QIcon(QObject::tr(":/new/prefix1/true.png"));
        break;
    default:
        break;
    }

    return f_state;
    // onChangeFriendState   <-Introduction
}

void TalkingListScreen::onFreshFriendList()
{
    onShowAllFriendUser();
}

void TalkingListScreen::closeEvent(QCloseEvent *event)
{
    qDebug("[%s]", __PRETTY_FUNCTION__);
    m_clientCommon->onWritePackage(USER_Exit, m_name);
}
