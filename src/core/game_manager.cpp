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
}

