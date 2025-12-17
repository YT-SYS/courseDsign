//
// Created by ASUS on 2025/12/2.
//
#include "game_manager.h"

#include <QKeyEvent>


GameManager::GameManager(QWidget *parent)
    : QWidget(parent), game_staus_{},timer_engine_(nullptr),
    game_view_widget_(nullptr), game_scene_widget_(nullptr),
    game_menu_widget_(nullptr), game_pause_widget_(nullptr)
{

}

GameManager::~GameManager() = default;

void GameManager::init(){
    // 1.初始化状态为菜单
    game_staus_ = MENU;

    // 2.创建游戏循环定时器，并连接槽函数
    timer_engine_ = new QTimer(this);
    connect(timer_engine_, &QTimer::timeout, this, &GameManager::game_engine_update);
    // 3.初始化界面
    // 3.1 创建菜单
    game_menu_widget_ = new GameMenu(this->width(), this->height(), this);
    connect(game_menu_widget_, &GameMenu::game_start_signal, this, &GameManager::game_start);
    connect(game_menu_widget_, &GameMenu::global_quit_signal, this, &GameManager::quit);
    // 3.2 创建暂停界面
    game_pause_widget_ = new GamePause(this->width(), this->height(), this);
    // 3.3 创建视图
    game_view_widget_ = new GameView(this);
    // 3.4 创建场景
    game_scene_widget_ = new GameScene(game_view_widget_);
    game_view_widget_->setScene(game_scene_widget_);          // 将场景添加到视图
    // 4.4显示关系
    game_menu_widget_->show();
    game_pause_widget_->hide();
    game_view_widget_->hide();


}

void GameManager::quit(){
    QApplication::quit();
}

void GameManager::switch_display(){
    game_menu_widget_->hide();
    game_view_widget_->hide();
    game_pause_widget_->hide();

    switch (game_staus_){
    case PLAYING:{
        game_view_widget_->show();
        game_view_widget_->set_focus();
        break;
    }
    case GAME_PAUSE:{
        game_view_widget_->show();
        game_pause_widget_->show();
        break;
    }
    case MENU:{
        game_menu_widget_->show();
        break;
    }
    default:
        break;
    }
}

void GameManager::game_engine_update(){

}

void GameManager::keyPressEvent(QKeyEvent* e){
    if (!e->isAutoRepeat()){
        switch (e->key()){
        case Qt::Key_Escape:{
            if (game_staus_ == PLAYING){
                printf("press Key_Esc\n");
                game_pause();
            }
        }
        default:
            break;
        }
    }

    QWidget::keyPressEvent(e);
}




void GameManager::game_start(){
    // 改变状态
    game_staus_ = PLAYING;
    timer_engine_->start(20);
    printf("[%s] game started\n", __func__);

    switch_display();
}

void GameManager::game_pause(){
    if (game_staus_ != PLAYING){
        printf("[%s] game not started, Cannot pause\n", __func__);
        return;
    }

    game_staus_ = GAME_PAUSE;
    timer_engine_->stop();
    printf("[%s] game pause\n", __func__);

    switch_display();
}

void GameManager::game_continue(){
    if (game_staus_ != GAME_PAUSE){
        printf("[%s] game no pause, Cannot continue\n", __func__);
        return;
    }

    game_staus_ = PLAYING;
    timer_engine_->start(20);
    printf("[%s] game continue\n", __func__);

    switch_display();
}

void GameManager::game_quit(){
    if (game_staus_ != GAME_PAUSE){
        printf("[%s] game no pause, Cannot quit\n", __func__);
        return;
    }

    game_staus_ = MENU;
    timer_engine_->stop();
    printf("[%s] game quit\n", __func__);

    switch_display();
}






