//
// Created by 嘿嘿嘿 on 2025/12/17.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window_sus.h" resolved

#include "main_window_sus.h"
#include "ui_main_window_sus.h"


main_window_sus::main_window_sus(QWidget *parent) :
        QWidget(parent), ui(new Ui::main_window_sus) {
    ui->setupUi(this);
}

main_window_sus::~main_window_sus() {
    delete ui;
}
