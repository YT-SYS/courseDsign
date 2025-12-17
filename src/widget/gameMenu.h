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

    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;

private:
    Ui::MainWindow *ui;
};


#endif //COURSEDESIGN_GAMEMENU_H