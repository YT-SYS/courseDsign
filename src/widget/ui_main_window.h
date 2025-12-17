/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *label;
    QPushButton *game_start;
    QPushButton *Exit_game;
    QPushButton *Group_name;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -10, 401, 311));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/1.png);"));
        game_start = new QPushButton(MainWindow);
        game_start->setObjectName(QString::fromUtf8("game_start"));
        game_start->setGeometry(QRect(140, 110, 121, 41));
        QPalette palette;
        QBrush brush(QColor(113, 113, 113, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        game_start->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("AcadEref"));
        font.setPointSize(12);
        game_start->setFont(font);
        game_start->setCursor(QCursor(Qt::CrossCursor));
        game_start->setStyleSheet(QString::fromUtf8("border-image: url(:/images/button1.1.png);"));
        Exit_game = new QPushButton(MainWindow);
        Exit_game->setObjectName(QString::fromUtf8("Exit_game"));
        Exit_game->setGeometry(QRect(140, 160, 121, 41));
        Exit_game->setFont(font);
        Exit_game->setCursor(QCursor(Qt::CrossCursor));
        Exit_game->setStyleSheet(QString::fromUtf8("border-image: url(:/images/button1.2.png);"));
        Group_name = new QPushButton(MainWindow);
        Group_name->setObjectName(QString::fromUtf8("Group_name"));
        Group_name->setGeometry(QRect(140, 210, 121, 41));
        Group_name->setFont(font);
        Group_name->setCursor(QCursor(Qt::CrossCursor));
        Group_name->setStyleSheet(QString::fromUtf8("border-image: url(:/images/button1.3.png);"));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        game_start->setText(QString());
        Exit_game->setText(QString());
        Group_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
