//
// Created by ASUS on 2025/12/2.
//
#include "in_manager.h"



InputManger::InputManger(QObject *parent)
    : QObject(parent)
{
    init();

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &InputManger::input_refresh);    // 问
    timer_->start(10);  // 10ms间隔
}

InputManger::~InputManger(){
    SDL_Quit();
}


 int InputManger::init(){
    const int ret = SDL_Init(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER);
    if (ret < 0 ){
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}


void InputManger::handle_key_press() {
    switch (e.key.keysym.sym){
    case SDLK_w:{    // 上
        is_key_up = true;
        qDebug() << "press Key_W";
        break;
    }
    case SDLK_s:{    // 下
        is_key_down = true;
        qDebug() << "press Key_S";
        break;
    }
    case SDLK_a:{    // 左
        is_key_left = true;
        qDebug() << "press Key_A";
        break;
    }
    case SDLK_d:{    // 右
        is_key_right = true;
        qDebug() << "press Key_D";
        break;
    }
    case SDLK_j:{    // 攻击
        qDebug() << "press Key_J";
        break;
    }
    default:
        qDebug() << "Unsupported event";
        break;
    }
}

void InputManger::handle_key_release(){
    switch (e.key.keysym.sym){
    case SDLK_w:{    // 上
        is_key_up = false;
        qDebug() << "press Key_W";
        break;
    }
    case SDLK_s:{    // 下
        is_key_down = false;
        qDebug() << "press Key_S";
        break;
    }
    case SDLK_a:{    // 左
        is_key_left = false;
        qDebug() << "press Key_A";
        break;
    }
    case SDLK_d:{    // 右
        is_key_right = false;
        qDebug() << "press Key_D";
        break;
    }
    case SDLK_j:{    // 攻击
        qDebug() << "press Key_J";
        break;
    }
    default:
        qDebug() << "Unsupported event";
        break;
    }
}

void InputManger::handle_gamepad_axis_motion(){
    if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX){ // 左遥感x值
        gamepad_x_val = e.caxis.value / 32767;
    }
    if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY){ // 左遥感x值
        gamepad_y_val = e.caxis.value / 32767;
    }
}

void InputManger::handle_gamepad_btn_press(){
    switch (e.cbutton.button){
    case SDL_CONTROLLER_BUTTON_A:{
        printf("gamepad key_a press\n");
        break;
    }
    case SDL_CONTROLLER_BUTTON_X:{
        printf("gamepad key_x press\n");
        break;
    }
    case SDL_CONTROLLER_BUTTON_B:{
        printf("gamepad key_b press\n");
        break;
    }
    case SDL_CONTROLLER_BUTTON_Y:{
        printf("gamepad key_y press\n");
        break;
    }
    default:
        printf("Unsupported gamepad btn\n");
        break;
    }
}

void InputManger::handle_gamepad_btn_release(){
    switch (e.cbutton.button){
    case SDL_CONTROLLER_BUTTON_A:{
        printf("gamepad key_a release\n");
        break;
    }
    case SDL_CONTROLLER_BUTTON_X:{
        printf("gamepad key_x release\n");
        break;
    }
    case SDL_CONTROLLER_BUTTON_B:{
        printf("gamepad key_b release\n");
        break;
    }
    case SDL_CONTROLLER_BUTTON_Y:{
        printf("gamepad key_y release\n");
        break;
    }
    default:
        printf("Unsupported gamepad btn\n");
        break;
    }
}



bool InputManger::is_up(){
    return is_key_up;
}
bool InputManger::is_down(){
    return is_key_down;
}
bool InputManger::is_left(){
    return is_key_left;
}
bool InputManger::is_right(){
    return is_key_right;
}

float InputManger::gamepad_x(){
    return gamepad_x_val;
}
float InputManger::gamepad_y(){
    return gamepad_y_val;
}


void InputManger::input_refresh(){
    while (SDL_PollEvent(&e)){    //从事件队列中取出事件

        if (e.type == SDL_CONTROLLERDEVICEADDED){   // 手柄添加
            in_device_type = GAMEPAD;
        }else if (e.type == SDL_CONTROLLERDEVICEREMOVED){   // 手柄移除
            in_device_type = KEYBOARD;
        }

        if (in_device_type == KEYBOARD){    // 键盘事件
            if (e.type == SDL_KEYDOWN)  handle_key_press(); // 键盘按下事件
            else if (e.type == SDL_KEYUP) handle_key_release();  // 键盘松开事件
        }else{  // 手柄事件
            if (e.type == SDL_CONTROLLERAXISMOTION) handle_gamepad_axis_motion();   // 遥感运动事件
            else if (e.type == SDL_CONTROLLERBUTTONDOWN) handle_gamepad_btn_press();     // 按钮按下事件
            else if (e.type == SDL_CONTROLLERBUTTONUP)   handle_gamepad_btn_release();   // 按钮松开事件
        }
    }
}







