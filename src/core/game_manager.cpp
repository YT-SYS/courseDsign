//
// Created by ASUS on 2025/12/2.
//
#include "game_manager.h"


GameManager::GameManager(QWidget *parent)
    : QWidget(parent), game_staus_{},timer_engine_(nullptr),
    game_view_(nullptr), game_scene_(nullptr),
    main_window_(nullptr), pause_window_(nullptr)
{

}

GameManager::~GameManager() = default;

void GameManager::init(){
    // 1.初始化状态为菜单
    game_staus_ = MENU;

    // 2.创建游戏循环定时器，并连接槽函数
    timer_engine_ = new QTimer(this);
    connect(timer_engine_, &QTimer::timeout, this, &GameManager::game_engine_update);
}

void GameManager::quit(){

}

void GameManager::game_start(){
    // 改变状态
    game_staus_ = PLAYING;
    timer_engine_->start(20);
}

void GameManager::game_pause(){
    game_staus_ = GAME_PAUSE;
    timer_engine_->stop();
}

void GameManager::game_continue(){
    game_staus_ = PLAYING;
}

void GameManager::game_quit(){
    game_staus_ = PLAYING;
}






