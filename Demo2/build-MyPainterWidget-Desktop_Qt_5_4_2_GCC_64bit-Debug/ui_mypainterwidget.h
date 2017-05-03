/********************************************************************************
** Form generated from reading UI file 'mypainterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPAINTERWIDGET_H
#define UI_MYPAINTERWIDGET_H

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

class Ui_MyPainterWidget
{
public:
    QLineEdit *lineEdit_word;
    QPushButton *btn_ok;
    QPushButton *btn_clear;
    QLabel *label_image;
    QLabel *label_image_2;

    void setupUi(QWidget *MyPainterWidget)
    {
        if (MyPainterWidget->objectName().isEmpty())
            MyPainterWidget->setObjectName(QStringLiteral("MyPainterWidget"));
        MyPainterWidget->resize(400, 300);
        lineEdit_word = new QLineEdit(MyPainterWidget);
        lineEdit_word->setObjectName(QStringLiteral("lineEdit_word"));
        lineEdit_word->setGeometry(QRect(80, 50, 113, 27));
        btn_ok = new QPushButton(MyPainterWidget);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(220, 50, 99, 27));
        btn_clear = new QPushButton(MyPainterWidget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        btn_clear->setGeometry(QRect(220, 80, 99, 27));
        label_image = new QLabel(MyPainterWidget);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(50, 150, 101, 71));
        label_image_2 = new QLabel(MyPainterWidget);
        label_image_2->setObjectName(QStringLiteral("label_image_2"));
        label_image_2->setGeometry(QRect(220, 150, 101, 71));

        retranslateUi(MyPainterWidget);

        QMetaObject::connectSlotsByName(MyPainterWidget);
    } // setupUi

    void retranslateUi(QWidget *MyPainterWidget)
    {
        MyPainterWidget->setWindowTitle(QApplication::translate("MyPainterWidget", "MyPainterWidget", 0));
        btn_ok->setText(QApplication::translate("MyPainterWidget", "OK", 0));
        btn_clear->setText(QApplication::translate("MyPainterWidget", "clear", 0));
        label_image->setText(QApplication::translate("MyPainterWidget", "ddd", 0));
        label_image_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyPainterWidget: public Ui_MyPainterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPAINTERWIDGET_H
