/********************************************************************************
** Form generated from reading UI file 'friendlist.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_H
#define UI_FRIENDLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendList
{
public:
    QLabel *label_name;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *list_friend;
    QGridLayout *gridLayout;
    QPushButton *btn_addFriend;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_makeMasses;
    QPushButton *btn_exit;

    void setupUi(QWidget *FriendList)
    {
        if (FriendList->objectName().isEmpty())
            FriendList->setObjectName(QStringLiteral("FriendList"));
        FriendList->resize(245, 690);
        label_name = new QLabel(FriendList);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(12, 12, 121, 21));
        comboBox = new QComboBox(FriendList);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 10, 85, 27));
        layoutWidget = new QWidget(FriendList);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 46, 211, 621));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        list_friend = new QListWidget(layoutWidget);
        list_friend->setObjectName(QStringLiteral("list_friend"));

        verticalLayout->addWidget(list_friend);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_addFriend = new QPushButton(layoutWidget);
        btn_addFriend->setObjectName(QStringLiteral("btn_addFriend"));

        gridLayout->addWidget(btn_addFriend, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        btn_makeMasses = new QPushButton(layoutWidget);
        btn_makeMasses->setObjectName(QStringLiteral("btn_makeMasses"));

        gridLayout->addWidget(btn_makeMasses, 1, 0, 1, 1);

        btn_exit = new QPushButton(layoutWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        gridLayout->addWidget(btn_exit, 1, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(FriendList);

        QMetaObject::connectSlotsByName(FriendList);
    } // setupUi

    void retranslateUi(QWidget *FriendList)
    {
        FriendList->setWindowTitle(QApplication::translate("FriendList", "Form", 0));
        label_name->setText(QString());
        btn_addFriend->setText(QApplication::translate("FriendList", "Add new friend", 0));
        btn_makeMasses->setText(QApplication::translate("FriendList", "Make Masses", 0));
        btn_exit->setText(QApplication::translate("FriendList", "exit", 0));
    } // retranslateUi

};

namespace Ui {
    class FriendList: public Ui_FriendList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_H
