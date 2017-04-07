/********************************************************************************
** Form generated from reading UI file 'talking.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALKING_H
#define UI_TALKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Talking
{
public:
    QListWidget *list_friend;
    QPushButton *btn_send;
    QTextEdit *textEdit_talkScreen;
    QTextEdit *textEdit_inputScreen;
    QPushButton *btn_B;
    QPushButton *btn_I;

    void setupUi(QWidget *Talking)
    {
        if (Talking->objectName().isEmpty())
            Talking->setObjectName(QStringLiteral("Talking"));
        Talking->resize(615, 570);
        list_friend = new QListWidget(Talking);
        list_friend->setObjectName(QStringLiteral("list_friend"));
        list_friend->setGeometry(QRect(460, 0, 141, 481));
        btn_send = new QPushButton(Talking);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        btn_send->setGeometry(QRect(240, 520, 99, 27));
        textEdit_talkScreen = new QTextEdit(Talking);
        textEdit_talkScreen->setObjectName(QStringLiteral("textEdit_talkScreen"));
        textEdit_talkScreen->setGeometry(QRect(10, 50, 441, 351));
        textEdit_inputScreen = new QTextEdit(Talking);
        textEdit_inputScreen->setObjectName(QStringLiteral("textEdit_inputScreen"));
        textEdit_inputScreen->setGeometry(QRect(10, 440, 441, 71));
        btn_B = new QPushButton(Talking);
        btn_B->setObjectName(QStringLiteral("btn_B"));
        btn_B->setGeometry(QRect(10, 410, 31, 27));
        btn_I = new QPushButton(Talking);
        btn_I->setObjectName(QStringLiteral("btn_I"));
        btn_I->setGeometry(QRect(50, 410, 31, 27));

        retranslateUi(Talking);

        QMetaObject::connectSlotsByName(Talking);
    } // setupUi

    void retranslateUi(QWidget *Talking)
    {
        Talking->setWindowTitle(QApplication::translate("Talking", "Form", 0));
        btn_send->setText(QApplication::translate("Talking", "Send", 0));
        btn_B->setText(QApplication::translate("Talking", "B", 0));
        btn_I->setText(QApplication::translate("Talking", "I", 0));
    } // retranslateUi

};

namespace Ui {
    class Talking: public Ui_Talking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKING_H
