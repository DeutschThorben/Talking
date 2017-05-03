/********************************************************************************
** Form generated from reading UI file 'registuser.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTUSER_H
#define UI_REGISTUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistUser
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *icon_name;
    QLabel *icon_KW;
    QLabel *icon_KWA;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_name;
    QLabel *label_KW;
    QLabel *label_KWA;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_ok;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_empty;
    QSpacerItem *horizontalSpacer_3;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_KW;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_KWA;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *RegistUser)
    {
        if (RegistUser->objectName().isEmpty())
            RegistUser->setObjectName(QStringLiteral("RegistUser"));
        RegistUser->resize(545, 186);
        layoutWidget = new QWidget(RegistUser);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 20, 31, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        icon_name = new QLabel(layoutWidget);
        icon_name->setObjectName(QStringLiteral("icon_name"));

        verticalLayout->addWidget(icon_name);

        icon_KW = new QLabel(layoutWidget);
        icon_KW->setObjectName(QStringLiteral("icon_KW"));

        verticalLayout->addWidget(icon_KW);

        icon_KWA = new QLabel(layoutWidget);
        icon_KWA->setObjectName(QStringLiteral("icon_KWA"));

        verticalLayout->addWidget(icon_KWA);

        layoutWidget1 = new QWidget(RegistUser);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(300, 20, 231, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(layoutWidget1);
        label_name->setObjectName(QStringLiteral("label_name"));

        verticalLayout_2->addWidget(label_name);

        label_KW = new QLabel(layoutWidget1);
        label_KW->setObjectName(QStringLiteral("label_KW"));

        verticalLayout_2->addWidget(label_KW);

        label_KWA = new QLabel(layoutWidget1);
        label_KWA->setObjectName(QStringLiteral("label_KWA"));

        verticalLayout_2->addWidget(label_KWA);

        layoutWidget2 = new QWidget(RegistUser);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 120, 316, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_ok = new QPushButton(layoutWidget2);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));

        horizontalLayout->addWidget(btn_ok);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_empty = new QPushButton(layoutWidget2);
        btn_empty->setObjectName(QStringLiteral("btn_empty"));

        horizontalLayout->addWidget(btn_empty);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        layoutWidget3 = new QWidget(RegistUser);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 260, 95));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_KW = new QLineEdit(layoutWidget3);
        lineEdit_KW->setObjectName(QStringLiteral("lineEdit_KW"));

        gridLayout->addWidget(lineEdit_KW, 1, 1, 1, 1);

        lineEdit_name = new QLineEdit(layoutWidget3);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        lineEdit_KWA = new QLineEdit(layoutWidget3);
        lineEdit_KWA->setObjectName(QStringLiteral("lineEdit_KWA"));

        gridLayout->addWidget(lineEdit_KWA, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        label->raise();

        retranslateUi(RegistUser);

        QMetaObject::connectSlotsByName(RegistUser);
    } // setupUi

    void retranslateUi(QWidget *RegistUser)
    {
        RegistUser->setWindowTitle(QApplication::translate("RegistUser", "Form", 0));
        icon_name->setText(QString());
        icon_KW->setText(QString());
        icon_KWA->setText(QString());
        label_name->setText(QString());
        label_KW->setText(QString());
        label_KWA->setText(QString());
        btn_ok->setText(QApplication::translate("RegistUser", "OK", 0));
        btn_empty->setText(QApplication::translate("RegistUser", "Empty", 0));
        label_3->setText(QApplication::translate("RegistUser", "Keyword Again:", 0));
        label_2->setText(QApplication::translate("RegistUser", "Keyword:", 0));
        label->setText(QApplication::translate("RegistUser", "Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class RegistUser: public Ui_RegistUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTUSER_H
