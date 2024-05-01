#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "SnakePart.h"
//#include <QPainter>
#include <QTimer>
#include "food.h"
class Snake : public QObject
{
    Q_OBJECT
    int lenght;
    int speed;
    QString name;
    QVector<SnakePart*> body;
    QString direction;
    QPointF startpos;
    bool alive;
    QTimer* SnakeMoveTimer;
    QTimer* PepperActiveTimer;
    int pepperTimerRemainingTime;
    signals:
    void moveSignal();
private slots:
    void move();
    void PepperDisactive();
public:
    void pause_snake();
    void continue_snake();
    QPointF getHeadPos();
    void setDirection(QString);
    QString getDirection();
    void setSpeed(int);
    int getSpeed();
    Snake(QGraphicsScene*,float,float,QString);
    void destroySnake();
};

#endif // SNAKE_H
