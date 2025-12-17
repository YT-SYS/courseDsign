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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PauseWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *PauseWindow)
    {
        if (PauseWindow->objectName().isEmpty())
            PauseWindow->setObjectName(QString::fromUtf8("PauseWindow"));
        PauseWindow->resize(400, 300);
        pushButton = new QPushButton(PauseWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 110, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/button2.1.png);"));
        pushButton_2 = new QPushButton(PauseWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 110, 91, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/button2.2.png);"));

        retranslateUi(PauseWindow);

        QMetaObject::connectSlotsByName(PauseWindow);
    } // setupUi

    void retranslateUi(QWidget *PauseWindow)
    {
        PauseWindow->setWindowTitle(QCoreApplication::translate("PauseWindow", "Form", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PauseWindow: public Ui_PauseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSE_WINDOW_H
