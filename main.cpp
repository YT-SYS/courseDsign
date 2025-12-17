#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include "in_manager.h"
#include "gameView.h"
#include "game_manager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    InputManger input_manger_(nullptr);

    GameManager game_manager(nullptr);
    game_manager.init();

    game_manager.show();

    return app.exec();
}