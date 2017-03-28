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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Talking
{
public:

    void setupUi(QWidget *Talking)
    {
        if (Talking->objectName().isEmpty())
            Talking->setObjectName(QStringLiteral("Talking"));
        Talking->resize(400, 300);

        retranslateUi(Talking);

        QMetaObject::connectSlotsByName(Talking);
    } // setupUi

    void retranslateUi(QWidget *Talking)
    {
        Talking->setWindowTitle(QApplication::translate("Talking", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Talking: public Ui_Talking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKING_H
