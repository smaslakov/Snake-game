#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractScrollArea>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//scroll bar
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //scroll bar
    //setWindowFlags(Qt::FramelessWindowHint);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene->setSceneRect(0, 0, 4000, 4000);
    back = new QGraphicsRectItem(0, 0, 4000, 4000);
    back->setBrush(QPixmap("/Users/sagot/Documents/Snake-game/images/back.jpg"));
    back->setZValue(-100);
    scene->addItem(back);
    float Startx = ui->graphicsView->scene()->width() / 2;
    float Starty = ui->graphicsView->scene()->height() / 2;
    snake = new Snake(scene, Startx, Starty, "hyesos");
    float Startaix1 = ui->graphicsView->scene()->width();
    float Startaiy1 = ui->graphicsView->scene()->height() / 2;
    snakeai1 = new SnakeAI(scene, Startaix1, Startaiy1, "Pedik");
    float Startaix2 = 1000;
    float Startaiy2 = 200;
    snakeai2 = new SnakeAI(scene, Startaix2, Startaiy2, "Chlen");
    float Startaix3 = 200;
    float Startaiy3 = 2000;
    snakeai3 = new SnakeAI(scene, Startaix3, Startaiy3, "Xyi");
    float Startaix4 = 3000;
    float Startaiy4 = 200;
    snakeai4 = new SnakeAI(scene, Startaix4, Startaiy4, "dqwd");
    for (int i = 0; i < 2000; ++i) {
        Food *food = new Food();
        scene->addItem(food);
        ItemsContainer::allFoods.push_back(food);
    }
    for (int i = 0; i < 500; ++i) {
        Pepper *pepper = new Pepper(scene);
        ItemsContainer::allPeppers.push_back(pepper);
    }
    connect(snake,&Snake::moveSignal,this,&MainWindow::moveScreen);
}

MainWindow::~MainWindow() {
    delete back;
    delete scene;
    delete ui;
    delete snake;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left) {
        snake->setDirection("left");
    }
    if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right) {
        snake->setDirection("right");
    }
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up) {
        snake->setDirection("up");
    }
    if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down) {
        snake->setDirection("down");
    }
}

void MainWindow::moveScreen() {
    QPointF pos = snake->getHeadPos();
    ui->graphicsView->setSceneRect(pos.x() - 256, pos.y() - 256, 512, 512);
}


