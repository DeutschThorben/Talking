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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resign
{
public:
    QLineEdit *user_newName;
    QLineEdit *user_newKeyword;
    QLineEdit *user_keywordAgain;
    QPushButton *btn_ok;
    QPushButton *btn_empty;
    QLabel *label_name;

    void setupUi(QWidget *Resign)
    {
        if (Resign->objectName().isEmpty())
            Resign->setObjectName(QStringLiteral("Resign"));
        Resign->resize(564, 595);
        user_newName = new QLineEdit(Resign);
        user_newName->setObjectName(QStringLiteral("user_newName"));
        user_newName->setGeometry(QRect(160, 180, 113, 27));
        user_newKeyword = new QLineEdit(Resign);
        user_newKeyword->setObjectName(QStringLiteral("user_newKeyword"));
        user_newKeyword->setGeometry(QRect(160, 220, 113, 27));
        user_keywordAgain = new QLineEdit(Resign);
        user_keywordAgain->setObjectName(QStringLiteral("user_keywordAgain"));
        user_keywordAgain->setGeometry(QRect(160, 270, 113, 27));
        btn_ok = new QPushButton(Resign);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(100, 330, 99, 27));
        btn_empty = new QPushButton(Resign);
        btn_empty->setObjectName(QStringLiteral("btn_empty"));
        btn_empty->setGeometry(QRect(240, 330, 99, 27));
        label_name = new QLabel(Resign);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(300, 180, 67, 17));

        retranslateUi(Resign);

        QMetaObject::connectSlotsByName(Resign);
    } // setupUi

    void retranslateUi(QWidget *Resign)
    {
        Resign->setWindowTitle(QApplication::translate("Resign", "Form", 0));
        btn_ok->setText(QApplication::translate("Resign", "OK", 0));
        btn_empty->setText(QApplication::translate("Resign", "Empty", 0));
        label_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Resign: public Ui_Resign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIGN_H
