/********************************************************************************
** Form generated from reading UI file 'addnewfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWFRIEND_H
#define UI_ADDNEWFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewFriend
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_find;
    QPushButton *btn_exit;

    void setupUi(QWidget *AddNewFriend)
    {
        if (AddNewFriend->objectName().isEmpty())
            AddNewFriend->setObjectName(QStringLiteral("AddNewFriend"));
        AddNewFriend->resize(244, 118);
        widget = new QWidget(AddNewFriend);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 200, 66));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_find = new QPushButton(widget);
        btn_find->setObjectName(QStringLiteral("btn_find"));

        horizontalLayout_2->addWidget(btn_find);

        btn_exit = new QPushButton(widget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        horizontalLayout_2->addWidget(btn_exit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddNewFriend);

        QMetaObject::connectSlotsByName(AddNewFriend);
    } // setupUi

    void retranslateUi(QWidget *AddNewFriend)
    {
        AddNewFriend->setWindowTitle(QApplication::translate("AddNewFriend", "Form", 0));
        label->setText(QApplication::translate("AddNewFriend", "Name:", 0));
        btn_find->setText(QApplication::translate("AddNewFriend", "Find", 0));
        btn_exit->setText(QApplication::translate("AddNewFriend", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class AddNewFriend: public Ui_AddNewFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWFRIEND_H
