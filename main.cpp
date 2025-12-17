#include <iostream>
#include <QWidget>
#include <QApplication>
#include <vector>
#include <QPushButton>
#include "in_manager.h"
#include "ui_main_window.h"


class Widget : public QWidget{
public:
    Widget(QWidget *parent);
    ~Widget() override;

private:
    Ui_MainWindow *ui;
};
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui_MainWindow;
    ui->setupUi(this);
}
Widget::~Widget() {

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget(nullptr);
    Widget widget1(nullptr);
    widget1.show();

    return a.exec();
}