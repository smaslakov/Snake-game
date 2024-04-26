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
    int SceneWidth = 1000;
    int SceneHeight = 800;
    QTimer* SnakeMoveTimer;
    QTimer* PepperActiveTimer;
    //void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    //QRectF boundingRect() const;
    signals:
    void moveSignal();
private slots:
    void move();
    void PepperDisactive();
public:
    QPointF getHeadPos();
    void setDirection(QString);
    QString getDirection();
    void setSpeed(int);
    int getSpeed();
    Snake(QGraphicsScene*,float,float,QString);
    void destroySnake();
};

#endif // SNAKE_H
