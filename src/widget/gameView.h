//
// Created by ASUS on 2025/12/16.
//

#ifndef COURSEDESIGN_GAMEVIEW_H
#define COURSEDESIGN_GAMEVIEW_H

#include <QGraphicsView>

class GameView : public QGraphicsView{
    Q_OBJECT
public:
    explicit GameView(QWidget *parent = nullptr);
    ~GameView() override;

    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;


    void set_focus();
};


#endif //COURSEDESIGN_GAMEVIEW_H