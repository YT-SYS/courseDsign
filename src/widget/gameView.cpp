//
// Created by ASUS on 2025/12/16.
//
#include "gameView.h"
#include "in_manager.h"

GameView::GameView(QWidget* parent)
    : QGraphicsView(parent)
{
    // 只设置策略，不立即获取焦点
    setFocusPolicy(Qt::StrongFocus);
    setInteractive(true);
    // 视口也要接收焦点
    viewport()->setFocusPolicy(Qt::StrongFocus);

}
GameView::~GameView() = default;


void GameView::keyPressEvent(QKeyEvent* e){
    if (!e->isAutoRepeat()){    // 不捕获自动重复事件
        InputManger::handle_key_view(e, true);
    }

    QGraphicsView::keyPressEvent(e);
}

void GameView::keyReleaseEvent(QKeyEvent* e){
    if (!e->isAutoRepeat()){
        InputManger::handle_key_view(e, false);
    }

    QGraphicsView::keyReleaseEvent(e);
}

void GameView::set_focus(){
    this->activateWindow();  // 1. 激活窗口（让窗口在前台）
    this->setFocus();        // 2. 设置焦点
}







