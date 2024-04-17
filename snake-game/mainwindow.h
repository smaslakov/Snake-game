#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsItem>
#include <QResizeEvent>
#include "snake.h"
#include <QKeyEvent>
#include "food.h"
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
    void keyPressEvent(QKeyEvent* event);
    Snake* snake;
    Food* food;
    QGraphicsRectItem * back;
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
