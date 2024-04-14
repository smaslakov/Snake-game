#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
class Snake
{
    int lenght;
    int speed;
    QVector<QGraphicsPixmapItem*> body;
    QString Direction;
    QPointF startpos;
    bool alive;
    int SceneWidth = 800;
    int SceneHeight = 600;
public:
    Snake(QGraphicsScene*);
};

#endif // SNAKE_H
