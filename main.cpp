#include <iostream>
#include <QApplication>
#include <vector>
#include <QPushButton>
#include "game_manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget(nullptr);
    widget.resize(800,600);
    QPushButton button(&widget);
    button.setText("hello world");
    widget.show();

    return a.exec();
}