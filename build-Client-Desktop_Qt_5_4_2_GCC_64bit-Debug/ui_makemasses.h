/********************************************************************************
** Form generated from reading UI file 'makemasses.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEMASSES_H
#define UI_MAKEMASSES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MakeMasses
{
public:

    void setupUi(QWidget *MakeMasses)
    {
        if (MakeMasses->objectName().isEmpty())
            MakeMasses->setObjectName(QStringLiteral("MakeMasses"));
        MakeMasses->resize(400, 300);

        retranslateUi(MakeMasses);

        QMetaObject::connectSlotsByName(MakeMasses);
    } // setupUi

    void retranslateUi(QWidget *MakeMasses)
    {
        MakeMasses->setWindowTitle(QApplication::translate("MakeMasses", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MakeMasses: public Ui_MakeMasses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEMASSES_H
