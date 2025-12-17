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
}


GamePause::~GamePause(){
    delete ui;
}
