/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *centralWidget;
    QListWidget *list_work;
    QPushButton *btn_delete;
    QPushButton *btn_exit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *m_labelUser;
    QListWidget *list_user;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(518, 619);
        centralWidget = new QWidget(Server);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        list_work = new QListWidget(centralWidget);
        new QListWidgetItem(list_work);
        list_work->setObjectName(QStringLiteral("list_work"));
        list_work->setGeometry(QRect(230, 30, 191, 351));
        btn_delete = new QPushButton(centralWidget);
        btn_delete->setObjectName(QStringLiteral("btn_delete"));
        btn_delete->setGeometry(QRect(210, 510, 99, 27));
        btn_exit = new QPushButton(centralWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setGeometry(QRect(330, 510, 99, 27));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 1, 151, 541));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        m_labelUser = new QLabel(layoutWidget);
        m_labelUser->setObjectName(QStringLiteral("m_labelUser"));

        verticalLayout->addWidget(m_labelUser);

        list_user = new QListWidget(layoutWidget);
        list_user->setObjectName(QStringLiteral("list_user"));

        verticalLayout->addWidget(list_user);

        Server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Server);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 518, 28));
        Server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Server);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Server);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Server->setStatusBar(statusBar);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", 0));

        const bool __sortingEnabled = list_work->isSortingEnabled();
        list_work->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = list_work->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Server", "Server is working start", 0));
        list_work->setSortingEnabled(__sortingEnabled);

        btn_delete->setText(QApplication::translate("Server", "Delete", 0));
        btn_exit->setText(QApplication::translate("Server", "Exit", 0));
        m_labelUser->setText(QApplication::translate("Server", "\347\224\250\346\210\267\345\210\227\350\241\250", 0));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
