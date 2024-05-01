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
    startGame();
    ui->pauseFrame->hide();
    connect(snake,&Snake::moveSignal,this,&MainWindow::moveScreen);
    connect(ui->pauseButton,&QPushButton::clicked,this,&MainWindow::pause);
    connect(ui->continueButton,&QPushButton::clicked,this,&MainWindow::continueGame);
}
void MainWindow::startGame(){
    numberOfAiSnakes = 25;
    for(int i = 0; i < numberOfAiSnakes;++i){
        float Startx = random() % 4000;
        float Starty = random() % 4000;
        snakeai1 = new SnakeAI(scene, Startx, Starty, ItemsContainer::allNames[i]);
        ItemsContainer::allSnakesAI.push_back(snakeai1);
        snakeai1->getAIHeadPos();
    }
    spawnPeppers();
    spawnFood();
    spawnStones();
}
void MainWindow::spawnFood() {
    for (int i = 0; i < 3000; ++i) {
        Food *food = new Food();
        scene->addItem(food);
        ItemsContainer::allFoods.push_back(food);
    }
}
void MainWindow::spawnStones() {
    for (int i = 0; i < 50; ++i) {
        Stone *stone = new Stone();
        scene->addItem(stone);
        ItemsContainer::allStones.push_back(stone);
    }
}
void MainWindow::spawnPeppers() {
    for (int i = 0; i < 500; ++i) {
        Pepper *pepper = new Pepper(scene);
        ItemsContainer::allPeppers.push_back(pepper);
    }
}
MainWindow::~MainWindow() {
    delete back;
    delete scene;
    delete ui;
    delete snake;
    for(int i = 0;i < ItemsContainer::allSnakesAI.size();++i){
        delete ItemsContainer::allSnakesAI[i];
    }
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
void MainWindow::pause(){
    snake->pause_snake();
    for(int i = 0;i < ItemsContainer::allSnakesAI.size();++i){
        ItemsContainer::allSnakesAI[i]->pause_snakeAI();
    }
    ui->pauseFrame->show();
    ui->pauseButton->hide();
}
void MainWindow::continueGame() {
    snake->continue_snake();
    ui->pauseFrame->hide();
    ui->pauseButton->show();
    for(int i = 0;i < ItemsContainer::allSnakesAI.size();++i){
        ItemsContainer::allSnakesAI[i]->continue_snakeAI();
    }
}