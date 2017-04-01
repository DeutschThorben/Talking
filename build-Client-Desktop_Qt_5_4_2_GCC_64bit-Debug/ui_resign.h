/********************************************************************************
** Form generated from reading UI file 'resign.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIGN_H
#define UI_RESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resign
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_ok;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_empty;
    QSpacerItem *horizontalSpacer_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *user_newName;
    QLineEdit *user_newKeyword;
    QLineEdit *user_keywordAgain;
    QSpacerItem *verticalSpacer;
    QLabel *label_keyword;
    QLabel *label_name;
    QLabel *label_keywordAgain;
    QLabel *label_iconKW;
    QLabel *label_iconName;
    QLabel *label_iconKWA;

    void setupUi(QWidget *Resign)
    {
        if (Resign->objectName().isEmpty())
            Resign->setObjectName(QStringLiteral("Resign"));
        Resign->resize(543, 225);
        layoutWidget = new QWidget(Resign);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 174, 380, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_ok = new QPushButton(layoutWidget);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));

        horizontalLayout_2->addWidget(btn_ok);

        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_empty = new QPushButton(layoutWidget);
        btn_empty->setObjectName(QStringLiteral("btn_empty"));

        horizontalLayout_2->addWidget(btn_empty);

        horizontalSpacer_3 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        layoutWidget1 = new QWidget(Resign);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 23, 266, 145));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        user_newName = new QLineEdit(layoutWidget1);
        user_newName->setObjectName(QStringLiteral("user_newName"));

        verticalLayout_2->addWidget(user_newName);

        user_newKeyword = new QLineEdit(layoutWidget1);
        user_newKeyword->setObjectName(QStringLiteral("user_newKeyword"));

        verticalLayout_2->addWidget(user_newKeyword);

        user_keywordAgain = new QLineEdit(layoutWidget1);
        user_keywordAgain->setObjectName(QStringLiteral("user_keywordAgain"));

        verticalLayout_2->addWidget(user_keywordAgain);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        label_keyword = new QLabel(Resign);
        label_keyword->setObjectName(QStringLiteral("label_keyword"));
        label_keyword->setGeometry(QRect(311, 56, 211, 31));
        label_name = new QLabel(Resign);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(311, 21, 171, 31));
        label_keywordAgain = new QLabel(Resign);
        label_keywordAgain->setObjectName(QStringLiteral("label_keywordAgain"));
        label_keywordAgain->setGeometry(QRect(311, 91, 181, 31));
        label_iconKW = new QLabel(Resign);
        label_iconKW->setObjectName(QStringLiteral("label_iconKW"));
        label_iconKW->setGeometry(QRect(281, 56, 31, 31));
        label_iconName = new QLabel(Resign);
        label_iconName->setObjectName(QStringLiteral("label_iconName"));
        label_iconName->setGeometry(QRect(281, 21, 31, 31));
        label_iconKWA = new QLabel(Resign);
        label_iconKWA->setObjectName(QStringLiteral("label_iconKWA"));
        label_iconKWA->setGeometry(QRect(281, 91, 31, 31));
        label_keyword->raise();
        label_name->raise();
        label_keywordAgain->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();

        retranslateUi(Resign);

        QMetaObject::connectSlotsByName(Resign);
    } // setupUi

    void retranslateUi(QWidget *Resign)
    {
        Resign->setWindowTitle(QApplication::translate("Resign", "Form", 0));
        btn_ok->setText(QApplication::translate("Resign", "OK", 0));
        btn_empty->setText(QApplication::translate("Resign", "Empty", 0));
        label->setText(QApplication::translate("Resign", "Name:", 0));
        label_2->setText(QApplication::translate("Resign", "Keyword:", 0));
        label_3->setText(QApplication::translate("Resign", "Keyword Again:", 0));
        label_keyword->setText(QString());
        label_name->setText(QString());
        label_keywordAgain->setText(QString());
        label_iconKW->setText(QString());
        label_iconName->setText(QString());
        label_iconKWA->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Resign: public Ui_Resign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIGN_H
