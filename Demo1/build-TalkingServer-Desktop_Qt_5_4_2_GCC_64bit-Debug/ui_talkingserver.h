/********************************************************************************
** Form generated from reading UI file 'talkingserver.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALKINGSERVER_H
#define UI_TALKINGSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TalkingServer
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QListWidget *list_user;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QListWidget *list_message;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_delete;
    QPushButton *btn_empty;
    QPushButton *btn_exit;
    QMenuBar *menuBar;
    QMenu *menuServer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TalkingServer)
    {
        if (TalkingServer->objectName().isEmpty())
            TalkingServer->setObjectName(QStringLiteral("TalkingServer"));
        TalkingServer->resize(494, 678);
        centralWidget = new QWidget(TalkingServer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 141, 581));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        list_user = new QListWidget(layoutWidget);
        list_user->setObjectName(QStringLiteral("list_user"));

        verticalLayout->addWidget(list_user);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(180, 40, 271, 551));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        list_message = new QListWidget(layoutWidget1);
        new QListWidgetItem(list_message);
        list_message->setObjectName(QStringLiteral("list_message"));

        verticalLayout_2->addWidget(list_message);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_delete = new QPushButton(layoutWidget1);
        btn_delete->setObjectName(QStringLiteral("btn_delete"));

        horizontalLayout_2->addWidget(btn_delete);

        btn_empty = new QPushButton(layoutWidget1);
        btn_empty->setObjectName(QStringLiteral("btn_empty"));

        horizontalLayout_2->addWidget(btn_empty);

        btn_exit = new QPushButton(layoutWidget1);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        horizontalLayout_2->addWidget(btn_exit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        TalkingServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TalkingServer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 494, 28));
        menuServer = new QMenu(menuBar);
        menuServer->setObjectName(QStringLiteral("menuServer"));
        TalkingServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TalkingServer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TalkingServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TalkingServer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TalkingServer->setStatusBar(statusBar);

        menuBar->addAction(menuServer->menuAction());

        retranslateUi(TalkingServer);

        QMetaObject::connectSlotsByName(TalkingServer);
    } // setupUi

    void retranslateUi(QMainWindow *TalkingServer)
    {
        TalkingServer->setWindowTitle(QApplication::translate("TalkingServer", "TalkingServer", 0));
        label->setText(QApplication::translate("TalkingServer", "\347\224\250\346\210\267\345\210\227\350\241\250", 0));

        const bool __sortingEnabled = list_message->isSortingEnabled();
        list_message->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = list_message->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("TalkingServer", "Server is working start", 0));
        list_message->setSortingEnabled(__sortingEnabled);

        btn_delete->setText(QApplication::translate("TalkingServer", "Delete", 0));
        btn_empty->setText(QApplication::translate("TalkingServer", "Empty", 0));
        btn_exit->setText(QApplication::translate("TalkingServer", "Exit", 0));
        menuServer->setTitle(QApplication::translate("TalkingServer", "Server", 0));
    } // retranslateUi

};

namespace Ui {
    class TalkingServer: public Ui_TalkingServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKINGSERVER_H
