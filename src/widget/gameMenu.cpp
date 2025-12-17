//
// Created by ASUS on 2025/12/17.
//

#include "gameMenu.h"

GameMenu::GameMenu(int w, int h, QWidget* parent)
    : QWidget(parent)
{
    ui = new Ui::MainWindow;        // 创建Ui对象，
    ui->setupUi(this);  // 将Ui管理的所有控件设置到当前窗口，ui 管理的所有 UI 组件（按钮、标签等）会作为 this 的子对象
    this->resize(w, h);

    connect(ui->game_start, &QPushButton::clicked, [this](){
        emit game_start_signal();
    });
    connect(ui->Exit_game, &QPushButton::clicked, [this](){
        emit global_quit_signal();
    });

}

GameMenu::~GameMenu(){
    delete ui;
}
