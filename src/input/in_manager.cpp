//
// Created by ASUS on 2025/12/2.
//
#include "in_manager.h"

bool InputManger::is_key_up = false;
bool InputManger::is_key_down = false;
bool InputManger::is_key_left = false;
bool InputManger::is_key_right = false;

// 手柄方向遥感
float InputManger::gamepad_x_val = 0.0;
float InputManger::gamepad_y_val  = 0.0;

InputManger::InputManger(QObject *parent)
    : QObject(parent), in_device_type(KEYBOARD), gamepad(nullptr)
{
    init();

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &InputManger::gamepad_event_refresh);    // 问
    timer_->start(10);  // 10ms间隔
}

InputManger::~InputManger(){
    SDL_Quit();
}


 int InputManger::init(){
    const int ret = SDL_Init(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER);
    if (ret < 0 ){
        printf("SDL_Init failed: %s\n !!!!!!!!!!!!!", SDL_GetError());
        return -1;
    }

    return 0;
}

void InputManger::handle_key_view(QKeyEvent* event, bool is_press){
    switch (event->key()){
    case Qt::Key_W:{    // 上
        is_key_up = is_press;
        printf("[view] press Key_W: %s\n", is_press ? "true" : "false");
        break;
    }
    case Qt::Key_S:{    // 下
        is_key_down = is_press;
        printf("[view] press Key_S: %s\n", is_press ? "true" : "false");
        break;
    }
    case Qt::Key_A:{    // 左
        is_key_left = is_press;
        printf("[view] press Key_A: %s\n", is_press ? "true" : "false");
        break;
    }
    case Qt::Key_D:{    // 右
        is_key_right = is_press;
        printf("[view] press Key_D: %s\n", is_press ? "true" : "false");
        break;
    }
    case Qt::Key_J:{    // 攻击
        printf("[view] press Key_J: %s\n", is_press ? "true" : "false");
        break;
    }
    default:
        printf("[view] Unsupported event\n");
        break;
    }
}



void InputManger::open_gamepad(){
    in_device_type = GAMEPAD;

    if (gamepad == nullptr){
        gamepad = SDL_GameControllerOpen(e.cdevice.which);
        if (gamepad) {
            printf("Gamepad opened successfully\n");
        } else {
            printf("Failed to open gamepad: %s\n", SDL_GetError());
        }
    }
}

void InputManger::close_gamepad(){
    in_device_type = KEYBOARD;
    if (gamepad) {
        SDL_GameControllerClose(gamepad);
        printf("Gamepad close\n");
        gamepad = nullptr;
    }
}



void InputManger::handle_gamepad_axis_motion(){


    if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX){ // 左遥感x值
        float raw = e.caxis.value / 32767.0f;
        if ((raw>0 && raw<0.25f) || (raw<0 && raw>-0.25f)){
            gamepad_x_val = 0.0;
        }else{
            gamepad_x_val = raw;
        }
        printf("x_val:%f\n", gamepad_x_val);
    }
    if (e.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY){ // 左遥感x值
        float raw = e.caxis.value / 32767.0f;
        if ((raw>0 && raw<0.25f) || (raw<0 && raw>-0.25f)){
            gamepad_y_val = 0.0;
        }else{
            gamepad_y_val = raw;
        }
        printf("y_val:%f\n", gamepad_y_val);
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


void InputManger::gamepad_event_refresh(){
    // printf("timer 10 ms\n");
    while (SDL_PollEvent(&e)){    //从事件队列中取出事件

        // 1.判断是否为手柄的接入和拔出事件
        if (e.type == SDL_CONTROLLERDEVICEADDED){   // 手柄打开
            open_gamepad();
        }else if (e.type == SDL_CONTROLLERDEVICEREMOVED){   // 手柄移除
            close_gamepad();
        }

        // 2.判断是否为手柄的动作事件
        if (in_device_type == GAMEPAD){  // 手柄事件
            if (e.type == SDL_CONTROLLERAXISMOTION) handle_gamepad_axis_motion();   // 遥感运动事件
            else if (e.type == SDL_CONTROLLERBUTTONDOWN) handle_gamepad_btn_press();     // 按钮按下事件
            else if (e.type == SDL_CONTROLLERBUTTONUP)   handle_gamepad_btn_release();   // 按钮松开事件
        }

    }
}







