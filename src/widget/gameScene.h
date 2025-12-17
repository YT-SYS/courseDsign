#ifndef COURSEDESIGN_GAMESCENE_H
#define COURSEDESIGN_GAMESCENE_H

#include <QObject>
#include <QGraphicsScene>

class GameScene : public QGraphicsScene{
Q_OBJECT
public:
    explicit GameScene(QObject *parent);
    ~GameScene() override;

    void set_background();      // 设置背景
    void add_player();          // 添加主角
    void add_enemy();           // 添加敌人

    void remove_enemy();        // 移除指定敌人
    void remove_all_enemy();    // 移除全部敌人

private:
    // std::vector<Character *>player_;
    // std::vector<Character *>enemy_;
};






#endif
