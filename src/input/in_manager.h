//
// Created by ASUS on 2025/12/2.
//

#ifndef COURSEDESIGN_KEYBOARD_H
#define COURSEDESIGN_KEYBOARD_H

#include <QObject>
#include <QKeyEvent>

enum DEVICE_TYPE{
    KEYBOARD = 0,
    GAMEPAD
};

class InputManger : QObject{
Q_OBJECT
    public:
    InputManger(QObject *parent = NULL);
    ~InputManger();

    static void handle_key_press(QKeyEvent *event);     // 键盘按下
    static void handle_key_release(QKeyEvent *event);   // 键盘松开

    static InputManger *get_instance();                 // 获取一个实例

    static bool is_up();
    static bool is_down();
    static bool is_left();
    static bool is_right();
    static float gamepad_x();
    static float gamepad_y();

public slots:
    void handle_gamepad_connected();    // 游戏手柄连接
    void handle_gamepad_axis_changed(); // 游戏手柄遥感
    void handle_gamepad_btn_press();    // 游戏手柄按下
    void handle_gamepad_btn_release();  // 游戏手柄松开

public:
    static InputManger *instance;

private:
    static DEVICE_TYPE in_device_type;
    // 键盘方向
    static bool is_kye_up;
    static bool is_key_down;
    static bool is_key_left;
    static bool is_key_right;

    // 手柄方向遥感
    static float gamepad_x_val;
    static float gamepad_y_val;
};





#endif //COURSEDESIGN_KEYBOARD_H