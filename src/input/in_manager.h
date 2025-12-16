//
// Created by ASUS on 2025/12/2.
//

#ifndef COURSEDESIGN_KEYBOARD_H
#define COURSEDESIGN_KEYBOARD_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>

#include "SDL2/SDL.h"

enum DEVICE_TYPE{
    KEYBOARD = 0,
    GAMEPAD
};

class InputManger : public QObject{
    Q_OBJECT
public:
    explicit InputManger(QObject *parent = nullptr);
    ~InputManger() override;

    int init();

    static void handle_key_press(QKeyEvent* event);     // 键盘按下
    static void handle_key_release(QKeyEvent* event);   // 键盘松开

    // 通过 SDL 进行处理
    void open_gamepad();
    void close_gamepad();
    void handle_gamepad_axis_motion(); // 游戏手柄遥感
    void handle_gamepad_btn_press();    // 游戏手柄按下
    void handle_gamepad_btn_release();  // 游戏手柄松开

    // 获取按键或者手柄的值
    static bool is_up();
    static bool is_down();
    static bool is_left();
    static bool is_right();
    static float gamepad_x();
    static float gamepad_y();

public slots:
    void gamepad_event_refresh();
private:
    QTimer *timer_;
    SDL_Event e;
    DEVICE_TYPE in_device_type;
    SDL_GameController* gamepad;
    // 键盘方向
    static bool is_key_up;
    static bool is_key_down;
    static bool is_key_left;
    static bool is_key_right;

    // 手柄方向遥感
    static float gamepad_x_val;
    static float gamepad_y_val;
};
#endif //COURSEDESIGN_KEYBOARD_H