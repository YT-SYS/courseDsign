/********************************************************************************
** Form generated from reading UI file 'pause_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSE_WINDOW_H
#define UI_PAUSE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PauseWindow
{
public:

    void setupUi(QWidget *PauseWindow)
    {
        if (PauseWindow->objectName().isEmpty())
            PauseWindow->setObjectName(QString::fromUtf8("PauseWindow"));
        PauseWindow->resize(400, 300);

        retranslateUi(PauseWindow);

        QMetaObject::connectSlotsByName(PauseWindow);
    } // setupUi

    void retranslateUi(QWidget *PauseWindow)
    {
        PauseWindow->setWindowTitle(QCoreApplication::translate("PauseWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PauseWindow: public Ui_PauseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_WINDOW_H
