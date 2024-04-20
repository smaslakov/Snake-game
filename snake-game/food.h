#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QGraphicsPixmapItem>
class Food : public QObject,public QGraphicsPixmapItem
{

public:
    Food(QGraphicsScene*);

};

#endif // FOOD_H
