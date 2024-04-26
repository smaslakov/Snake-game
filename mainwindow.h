#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsItem>
#include <QResizeEvent>
#include "snake.h"
#include <QKeyEvent>
#include <QTimer>
#include "food.h"
#include "Pepper.h"
#include "ItemsContainer.h"
#include "SnakeAI.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QTimer* ScreenMoveTimer;
    void keyPressEvent(QKeyEvent* event);
    Snake* snake;
    SnakeAI* snakeai1;
    SnakeAI* snakeai2;
    SnakeAI* snakeai3;
    SnakeAI* snakeai4;
    QGraphicsRectItem * back;
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

private slots:
    void moveScreen();
};
#endif // MAINWINDOW_H
