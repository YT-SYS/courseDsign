//
// Created by ASUS on 2025/12/17.
//

#ifndef COURSEDESIGN_GAMEPAUSE_H
#define COURSEDESIGN_GAMEPAUSE_H
#include "ui_pause_window.h"

class GamePause : public QWidget{
    Q_OBJECT
public:
    GamePause(int w, int h, QWidget *parent = nullptr);
    ~GamePause() override;

signals:
    void game_continue_signal();
    void game_quit_signal();
    // void keyPressEvent(QKeyEvent *e) override;
    // void keyReleaseEvent(QKeyEvent *e) override;

private:
    Ui::PauseWindow *ui;
};


#endif //COURSEDESIGN_GAMEPAUSE_H