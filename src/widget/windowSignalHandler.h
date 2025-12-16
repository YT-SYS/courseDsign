//
// Created by ASUS on 2025/12/16.
//

#ifndef COURSEDESIGN_WINDOWSIGNALHANDLER_H
#define COURSEDESIGN_WINDOWSIGNALHANDLER_H
#include "game_manager.h"
#include <QObject>

class WindowSignalHandler : public QObject{
    Q_OBJECT
public:
    WindowSignalHandler(Ui::MainWindow *main_window, Ui::PauseWindow *pause_window,
                         GameManager *game_manager, QObject *parent = nullptr);
    ~WindowSignalHandler() override;

private:
    GameManager *game_manager_;
    Ui::MainWindow *main_window_;
    Ui::PauseWindow *pause_window_;

};



#endif //COURSEDESIGN_WINDOWSIGNALHANDLER_H