//
// Created by ASUS on 2025/12/17.
//
#include "gamePause.h"

GamePause::GamePause(int w, int h, QWidget* parent)
    : QWidget(parent)
{
    ui = new Ui::PauseWindow;
    ui->setupUi(this);
    this->resize(w, h);

    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        emit game_continue_signal();
    });
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        emit game_quit_signal();
    });
}


GamePause::~GamePause(){
    delete ui;
}
