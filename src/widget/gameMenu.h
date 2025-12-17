//
// Created by ASUS on 2025/12/17.
//

#ifndef COURSEDESIGN_GAMEMENU_H
#define COURSEDESIGN_GAMEMENU_H
#include "ui_main_window.h"

class GameMenu : public QWidget{
    Q_OBJECT
public:
    explicit GameMenu(int w, int h, QWidget *parent);
    ~GameMenu() override;

signals:
    void game_start_signal();
    void global_quit_signal();

private:
    Ui::MainWindow *ui;
};


#endif //COURSEDESIGN_GAMEMENU_H