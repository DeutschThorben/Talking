/********************************************************************************
** Form generated from reading UI file 'talkingclient.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALKINGCLIENT_H
#define UI_TALKINGCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TalkingClient
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLineEdit *lineEdit_KWD;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_login;
    QPushButton *btn_regist;
    QPushButton *btn_exit;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TalkingClient)
    {
        if (TalkingClient->objectName().isEmpty())
            TalkingClient->setObjectName(QStringLiteral("TalkingClient"));
        TalkingClient->resize(422, 287);
        centralWidget = new QWidget(TalkingClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 41, 363, 134));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_KWD = new QLineEdit(widget);
        lineEdit_KWD->setObjectName(QStringLiteral("lineEdit_KWD"));

        gridLayout->addWidget(lineEdit_KWD, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_3 = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_login = new QPushButton(widget);
        btn_login->setObjectName(QStringLiteral("btn_login"));

        horizontalLayout->addWidget(btn_login);

        btn_regist = new QPushButton(widget);
        btn_regist->setObjectName(QStringLiteral("btn_regist"));

        horizontalLayout->addWidget(btn_regist);

        btn_exit = new QPushButton(widget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        horizontalLayout->addWidget(btn_exit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        TalkingClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TalkingClient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 422, 28));
        TalkingClient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TalkingClient);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TalkingClient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TalkingClient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TalkingClient->setStatusBar(statusBar);

        retranslateUi(TalkingClient);

        QMetaObject::connectSlotsByName(TalkingClient);
    } // setupUi

    void retranslateUi(QMainWindow *TalkingClient)
    {
        TalkingClient->setWindowTitle(QApplication::translate("TalkingClient", "TalkingClient", 0));
        label_2->setText(QApplication::translate("TalkingClient", "Keyword:", 0));
        label->setText(QApplication::translate("TalkingClient", "Name:", 0));
        btn_login->setText(QApplication::translate("TalkingClient", "Login", 0));
        btn_regist->setText(QApplication::translate("TalkingClient", "Regist", 0));
        btn_exit->setText(QApplication::translate("TalkingClient", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class TalkingClient: public Ui_TalkingClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKINGCLIENT_H
