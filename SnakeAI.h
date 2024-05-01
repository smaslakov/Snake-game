
#ifndef SNAKE_GAME_SNAKEAI_H
#define SNAKE_GAME_SNAKEAI_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "food.h"
#include "Pepper.h"
#include "SnakePart.h"
class SnakeAI : public QObject{
    QString name;
    int lenght;
    int speed;
    bool PepperEffectActive;
    QVector<SnakePart*> body;
    QString direction;
    QPointF startpos;
    bool alive;
    QTimer* SnakeAIMoveTimer;
    QTimer* PepperAIActiveTimer;
    void CheckCollision();
    int color;
    QGraphicsEllipseItem* boundary;
    //void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    //QRectF boundingRect() const;
    int pepperAITimerRemainingTime;
private slots:
    void move();
    void PepperDisactive();
public:
    void pause_snakeAI();
    void continue_snakeAI();
    QPointF getAIHeadPos();
    void setDirection(QString);
    QString getDirection();
    void setSpeed(int);
    int getSpeed();
    SnakeAI(QGraphicsScene*,float,float,QString);
    void destroySnake();
};


#endif //SNAKE_GAME_SNAKEAI_H
