//
// Created by ASUS on 2025/12/16.
//
#include "gameView.h"
#include "in_manager.h"

GameView::GameView(QGraphicsView* parent)
    : QGraphicsView(parent)
{

}
GameView::~GameView() = default;


void GameView::keyPressEvent(QKeyEvent* e){
    if (!e->isAutoRepeat()){    // 不捕获自动重复事件
        InputManger::handle_key_press(e);
    }

    e->accept();                // 标记这个事件为"已处理"，阻止事件继续传播给父窗口或其他组件
}

void GameView::keyReleaseEvent(QKeyEvent* e){
    if (!e->isAutoRepeat()){
        InputManger::handle_key_release(e);
    }

    e->accept();
}

void GameView::set_focus(){     // 获取焦点
    setFocus();
}







