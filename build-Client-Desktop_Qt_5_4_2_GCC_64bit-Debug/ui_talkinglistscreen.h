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
#include <QtWidgets/QComboBox>
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_icon;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_name;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QComboBox *comboBox_state;

    void setupUi(QWidget *TalkingListScreen)
    {
        if (TalkingListScreen->objectName().isEmpty())
            TalkingListScreen->setObjectName(QStringLiteral("TalkingListScreen"));
        TalkingListScreen->resize(284, 584);
        layoutWidget = new QWidget(TalkingListScreen);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 60, 221, 501));
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

        widget = new QWidget(TalkingListScreen);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 221, 41));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_icon = new QLabel(widget);
        label_icon->setObjectName(QStringLiteral("label_icon"));

        horizontalLayout_3->addWidget(label_icon);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label_name = new QLabel(widget);
        label_name->setObjectName(QStringLiteral("label_name"));

        verticalLayout_3->addWidget(label_name);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        comboBox_state = new QComboBox(widget);
        comboBox_state->setObjectName(QStringLiteral("comboBox_state"));

        verticalLayout_4->addWidget(comboBox_state);


        horizontalLayout_3->addLayout(verticalLayout_4);


        retranslateUi(TalkingListScreen);

        QMetaObject::connectSlotsByName(TalkingListScreen);
    } // setupUi

    void retranslateUi(QWidget *TalkingListScreen)
    {
        TalkingListScreen->setWindowTitle(QApplication::translate("TalkingListScreen", "Form", 0));
        btn_addNewFriend->setText(QApplication::translate("TalkingListScreen", "Add new friend", 0));
        btn_makeMasses->setText(QApplication::translate("TalkingListScreen", "Make new masses", 0));
        label_icon->setText(QString());
        label_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TalkingListScreen: public Ui_TalkingListScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKINGLISTSCREEN_H
