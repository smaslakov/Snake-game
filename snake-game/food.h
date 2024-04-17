#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QGraphicsPixmapItem>
class Food : public QObject
{
    QTimer* timer;
    QVector<QGraphicsPixmapItem*> allfood;
    void resetFood();
public:
    Food(QGraphicsScene*);
};

#endif // FOOD_H
