//
// Created by 嘿嘿嘿 on 2025/12/17.
//

#ifndef COURSEDESIGN_MAIN_WINDOW_SUS_H
#define COURSEDESIGN_MAIN_WINDOW_SUS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class main_window_sus; }
QT_END_NAMESPACE

class main_window_sus : public QWidget {
Q_OBJECT

public:
    explicit main_window_sus(QWidget *parent = nullptr);

    ~main_window_sus() override;

private:
    Ui::main_window_sus *ui;
};


#endif //COURSEDESIGN_MAIN_WINDOW_SUS_H
