#include "mainwindow.h"
#include <QPixmap>
#include <QTimer>
#include <QApplication>
#include <QDebug>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      spriteItem(nullptr),
      currentFrame(0),
      timer(new QTimer(this))
{
    // 1. 创建QGraphicsView
    auto view = new QGraphicsView(scene);
    setCentralWidget(view);
    view->setMinimumSize(800, 600);
    view->setRenderHint(QPainter::Antialiasing);

    // 2. 从单张大图切分帧 (3072x128 -> 24帧×128x128)
    QPixmap fullPixmap(":/images/251202_01.png");
    if (fullPixmap.isNull()) {
        qWarning() << "Failed to load sprite sheet!";
        // 生成一个默认红色矩形（避免崩溃）
        fullPixmap = QPixmap(128, 128);
        fullPixmap.fill(Qt::red);
    }

    // 计算每帧尺寸 (3072/24=128)
    int frameWidth = 128;
    int frameHeight = 128;
    int frameCount = 24;

    // 切分帧
    for (int i = 0; i < frameCount; ++i) {
        QRect rect(i * frameWidth, 0, frameWidth, frameHeight);
        spriteFrames.append(fullPixmap.copy(rect));
    }

    // 3. 创建精灵并添加到场景
    if (!spriteFrames.isEmpty()) {
        spriteItem = scene->addPixmap(spriteFrames[0]);
        spriteItem->setPos(200, 200); // 初始位置
    }

    // 4. 设置动画
    timer->setInterval(500); // 100ms/帧
    connect(timer, &QTimer::timeout, this, &MainWindow::animateSprite);
    timer->start();
}

MainWindow::~MainWindow() {
    delete scene;
}

void MainWindow::animateSprite() {
    if (spriteFrames.isEmpty()) return;

    currentFrame = (currentFrame + 1) % spriteFrames.size();
    spriteItem->setPixmap(spriteFrames[currentFrame]);
}