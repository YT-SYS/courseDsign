//
// Created by ASUS on 2025/12/2.
//

#ifndef COURSEDESIGN_CHARACTER_H
#define COURSEDESIGN_CHARACTER_H

#include<cstdint>
#include <vector>
#include <QTimer>
#include <QGraphicsItem>

#include "game_manager.h"
// 人物状态
enum CharacterState {
    IDLE = 0,       // 闲置
    WALKING,        // 行走
    ATTACKING,      // 攻击
    HURT,           // 受伤
    DEAD            // 死亡
};

// 人物朝向
enum Direction {
    RIGHT = 0 ,
    LEFT
};

class Character:QGraphicsItem{

public:
    Character(QGraphicsItem *parent = NULL);
    ~Character();

    virtual void change_location();     // 改变位置
    virtual void change_state();        // 改变状态
    virtual void attack();              // 攻击
    virtual void take_damage();         // 受伤
    virtual void die();                 // 死亡

private slots:
    void update_animation_frames();

protected:
    // 基础属性
    uint8_t max_health_;        // 最大生命值
    uint8_t current_health_;    // 当前生命值
    uint8_t move_speed_;        // 移动速度
    uint8_t attack_val_;        // 伤害

    // 人物状态
    int dx_;                        // x方向的速度
    int dy_;                        // y方向的速度
    CharacterState current_state_;  // 人物当前状态
    Direction   facing_direction_;  // 人物当前朝向

    // 动图相关
    QTimer *timer_sprite_;      // 精灵图刷新
    std::vector<QPixmap> sprite_frame_; // 存放精灵图的每一帧
    int current_frame_index_;
};




#endif //COURSEDESIGN_CHARACTER_H