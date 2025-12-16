#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include "in_manager.h"
#include "gameView.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    InputManger input_manger_(nullptr);

    // 创建视图
    GameView view;
    view.setWindowTitle("Keyboard Test");
    view.resize(800, 600);
    view.show();

    // 关键修复：虚拟显示环境需要的焦点设置
    QTimer::singleShot(1000, [&]() {
        view.activateWindow();  // 先激活窗口
        view.setFocus();        // 再设置焦点
        qDebug() << "Focus set! Current focus:" << view.hasFocus();
    });

    return app.exec();
}