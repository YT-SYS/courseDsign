#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>
#include <QList>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void animateSprite();

private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *spriteItem;
    int currentFrame;
    QList<QPixmap> spriteFrames;
    QTimer *timer;
};

#endif // MAINWINDOW_H