//
// Created by ASUS on 2025/12/2.
//

#ifndef COURSEDESIGN_CORE_H
#define COURSEDESIGN_CORE_H


#include <QTimer>
#include <QWidget>
#include <QStackedWidget>
#include  <QGraphicsView>

#include "gameView.h"
#include "gameMenu.h"
#include "gamePause.h"
#include "gameScene.h"

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

    void  switch_display(); // 界面切换

public slots:
    void game_engine_update();

private:
    GameState game_staus_;
    QTimer *timer_engine_;

    GameView    *game_view_widget_;
    GameScene   *game_scene_widget_;
    GameMenu    *game_menu_widget_;
    GamePause   *game_pause_widget_;
};
#endif //COURSEDESIGN_CORE_H