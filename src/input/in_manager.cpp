//
// Created by ASUS on 2025/12/2.
//
#include "in_manager.h"
#include "SDL2/SDL_hints.h"



InputManger::InputManger(QObject *parent)
    : QObject(parent)
{
    // QObject::connect(get_instance(),);

}

InputManger::~InputManger(){

}

void InputManger::handle_key_press(QKeyEvent* event){
    switch (event->key()){
    case Qt::Key_W:{    // 上
        is_key_up = true;
        qDebug() << "press Key_W";
        break;
    }
    case Qt::Key_S:{    // 下
        is_key_down = true;
        qDebug() << "press Key_S";
        break;
    }
    case Qt::Key_A:{    // 左
        is_key_left = true;
        qDebug() << "press Key_A";
        break;
    }
    case Qt::Key_D:{    // 右
        is_key_right = true;
        qDebug() << "press Key_D";
        break;
    }
    case Qt::Key_J:{    // 攻击
        qDebug() << "press Key_J";
        break;
    }
    default:
        qDebug() << "Unsupported event";
        break;
    }
}

void InputManger::handle_key_release(QKeyEvent* event){
    switch (event->key()){
    case Qt::Key_W:{    // 上
        is_key_up = false;
        qDebug() << "release Key_W";
        break;
    }
    case Qt::Key_S:{    // 下
        is_key_down = false;
        qDebug() << "release Key_S";
        break;
    }
    case Qt::Key_A:{    // 左
        is_key_left = false;
        qDebug() << "release Key_A";
        break;
    }
    case Qt::Key_D:{    // 右
        is_key_right = false;
        qDebug() << "release Key_D";
        break;
    }
    default:
        qDebug() << "Unsupported event";
        break;
    }
}

InputManger* InputManger::get_instance(){
    if (!instance_){
        instance_ = new InputManger();
    }
    return instance_;
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






