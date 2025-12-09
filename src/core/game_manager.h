//
// Created by ASUS on 2025/12/2.
//

#ifndef COURSEDESIGN_CORE_H
#define COURSEDESIGN_CORE_H


#include <QTimer>
#include <QWidget>
#include <QStackedWidget>
#include  <QGraphicsView>

#include "gameScene.h"
#include "ui_main_window.h"
#include "ui_pause_window.h"

enum GameState{
    MENU = 0,
    PLAYING,
    GAME_PAUSE,
    GAME_OVER
};

namespace Ui{
    class MainWindow;
    class PauseWindow;
}


class GameManager: public QWidget{
    Q_OBJECT
public:
    GameManager(QWidget *parent = NULL);
    ~GameManager();

    void init();
    void destroy();

    void game_start();      // 游戏开始
    void game_pause();      // 游戏暂停
    void game_continue();   // 游戏继续
    void game_quit();       // 游戏退出

    void  update_display(); // 界面切换

    //void keyPressEvent(QKeyEvent* event) override;
    //void keyReleaseEvent(QKeyEvent* event) override;

public slots:
    //void game_engine_update();

private:
    GameState game_staus_;
    QTimer *timer_engine_;

    GameScene *game_scene_;
    QGraphicsView *game_view_;
    Ui::MainWindow *ui;
    Ui::PauseWindow *pause_window_;
};
#endif //COURSEDESIGN_CORE_H