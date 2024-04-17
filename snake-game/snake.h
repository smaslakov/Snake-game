#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
//#include <QPainter>
#include <QTimer>
class Snake : public QObject
{
    int lenght;
    int speed;
    QVector<QGraphicsPixmapItem*> body;
    QString direction;
    QPointF startpos;
    bool alive;
    int SceneWidth = 1000;
    int SceneHeight = 800;
    void move();
    QTimer* timer;
    //void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    //QRectF boundingRect() const;
public:
    void setDirection(QString);
    QString getDirection();
    Snake(QGraphicsScene*);
};

#endif // SNAKE_H
