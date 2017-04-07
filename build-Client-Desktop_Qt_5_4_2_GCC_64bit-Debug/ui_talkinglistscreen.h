/********************************************************************************
** Form generated from reading UI file 'talkinglistscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALKINGLISTSCREEN_H
#define UI_TALKINGLISTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TalkingListScreen
{
public:
    QLabel *label_name;
    QLabel *label_icon;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *list_friend;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_addNewFriend;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_makeMasses;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *TalkingListScreen)
    {
        if (TalkingListScreen->objectName().isEmpty())
            TalkingListScreen->setObjectName(QStringLiteral("TalkingListScreen"));
        TalkingListScreen->resize(235, 555);
        label_name = new QLabel(TalkingListScreen);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(90, 10, 81, 21));
        label_icon = new QLabel(TalkingListScreen);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        label_icon->setGeometry(QRect(20, 0, 41, 31));
        layoutWidget = new QWidget(TalkingListScreen);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 191, 501));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        list_friend = new QListWidget(layoutWidget);
        list_friend->setObjectName(QStringLiteral("list_friend"));

        verticalLayout_2->addWidget(list_friend);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_addNewFriend = new QPushButton(layoutWidget);
        btn_addNewFriend->setObjectName(QStringLiteral("btn_addNewFriend"));

        horizontalLayout->addWidget(btn_addNewFriend);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_makeMasses = new QPushButton(layoutWidget);
        btn_makeMasses->setObjectName(QStringLiteral("btn_makeMasses"));

        horizontalLayout_2->addWidget(btn_makeMasses);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(TalkingListScreen);

        QMetaObject::connectSlotsByName(TalkingListScreen);
    } // setupUi

    void retranslateUi(QWidget *TalkingListScreen)
    {
        TalkingListScreen->setWindowTitle(QApplication::translate("TalkingListScreen", "Form", 0));
        label_name->setText(QString());
        label_icon->setText(QString());
        btn_addNewFriend->setText(QApplication::translate("TalkingListScreen", "Add new friend", 0));
        btn_makeMasses->setText(QApplication::translate("TalkingListScreen", "Make new masses", 0));
    } // retranslateUi

};

namespace Ui {
    class TalkingListScreen: public Ui_TalkingListScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKINGLISTSCREEN_H
