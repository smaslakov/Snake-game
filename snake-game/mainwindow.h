#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsItem>
#include <QResizeEvent>
#include "snake.h"
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
    Snake* snake;
    void resizeEvent(QResizeEvent *event) override;
    QGraphicsRectItem * back;
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
