#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene->setSceneRect(0,0,1000,800);
    back = new QGraphicsRectItem(0,0,1000,800);
    back->setBrush(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/back.jpg"));
    back->setZValue(-100);
    scene->addItem(back);
    snake = new Snake(scene);
    food = new Food(scene);
    //scene->addItem(snake);
}
MainWindow::~MainWindow()
{
    delete back;
    delete scene;
    delete ui;
    delete snake;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A || event->key() == Qt::Key_Left){
        snake->setDirection("left");
    }
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_Right){
        snake->setDirection("right");
    }
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_Up){
        snake->setDirection("up");
    }
    if(event->key() == Qt::Key_S || event->key() == Qt::Key_Down){
        snake->setDirection("down");
    }
}
