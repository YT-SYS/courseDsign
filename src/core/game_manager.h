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
#include "gameView.h"
#include "ui_main_window.h"
#include "ui_pause_window.h"

enum GameState{
    MENU = 0,
    PLAYING,
    GAME_PAUSE,
    GAME_OVER
};



class GameManager: public QWidget{
    Q_OBJECT
public:
    explicit GameManager(QWidget *parent = nullptr);
    ~GameManager() override;

    void init();

    void game_start();      // 游戏开始
    void game_pause();      // 游戏暂停
    void game_continue();   // 游戏继续
    void game_quit();       // 游戏退出
    void quit();            // 退出

    void  update_display(); // 界面切换

public slots:
    void game_engine_update();

private:
    GameState game_staus_;
    QTimer *timer_engine_;

    GameView *game_view_;
    GameScene *game_scene_;
    Ui::MainWindow *main_window_;
    Ui::PauseWindow *pause_window_;
};
#endif //COURSEDESIGN_CORE_H