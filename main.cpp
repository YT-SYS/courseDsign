#include <iostream>
#include <QApplication>
#include <vector>
#include "game_manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameManager game_manager_(nullptr);
    game_manager_.show();

    return a.exec();
}