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
    scene->setSceneRect(0,0,800,600);
    back = new QGraphicsRectItem(0,0,800,600);
    back->setBrush(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/back.jpg"));
    back->setZValue(-100);
    scene->addItem(back);
    snake = new Snake(scene);
}
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    const QSize newSize = event->size();
    //ui->graphicsView->fitInView(back, Qt::KeepAspectRatio);
    scene->setSceneRect(0, 0, newSize.width(), newSize.height());
    back->setRect(0, 0, newSize.width(), newSize.height());
    //update();
}
MainWindow::~MainWindow()
{
    delete back;
    delete scene;
    delete ui;
    delete snake;
}
