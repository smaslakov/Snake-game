#include "snake.h"

// void Snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
// {
//     float StartXpos = SceneWidth / 2;
//     float StartYpos = SceneHeight - 50;
//     for (int i = 0; i < lenght; ++i) {
//         QGraphicsPixmapItem* snakepart = new QGraphicsPixmapItem();
//         if (i == 0) {
//             snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/snakeUnit9Head.png"));
//             snakepart->setTransformOriginPoint(snakepart->pixmap().width() / 2, snakepart->pixmap().height() / 2);
//         }
//         else {
//             snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/snakeUnit9.png"));
//             snakepart->setZValue(-1 - (i % 100));
//         }
//         snakepart->setPos(StartXpos, StartYpos - 8 * (lenght - i));
//         snakepart->paint(painter, option, widget); // Draw the pixmap item
//         body.push_back(snakepart);
//     }
// }

// QRectF Snake::boundingRect() const
// {
//     return QRectF();
// }

Snake::Snake(QGraphicsScene * scene){
    alive = true;
    lenght = 8;
    speed = 6;
    direction = "up";
    float StartXpos = SceneWidth / 2;
    float StartYpos = SceneHeight - 50;
    for(int i = 0;i < lenght;++i){
        QGraphicsPixmapItem* snakepart = new QGraphicsPixmapItem();
        if(i == 0){
            snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/snakeUnit9Head.png"));
            snakepart->setTransformOriginPoint(snakepart->pixmap().width()/2, snakepart->pixmap().height()/2);
        }else{
            snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/snakeUnit9.png"));
            snakepart->setZValue(-1 - (i % 100));
        }
        snakepart->setPos(StartXpos,StartYpos - 8 *(lenght - i));
        scene->addItem(snakepart);
        body.push_back(snakepart);
    }
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&Snake::move);
    timer->start(100);
}

void Snake::move()
{
    for(int i = body.length() - 1;i >= 0;--i){
        if(i != 0){
            body[i]->setY(body[i - 1]->y());
            body[i]->setX(body[i - 1]->x());
            continue;
        }
        if(direction == "up"){
            body[i]->setY(body[i]->y() - speed);
        }
        if(direction == "down"){
            body[i]->setY(body[i]->y() + speed);
        }
        if(direction == "right"){
            body[i]->setX(body[i]->x() + speed);
        }
        if(direction == "left"){
            body[i]->setX(body[i]->x() - speed);
        }
    }
}

void Snake::setDirection(QString dir)
{
    if(dir == "right"){
        direction = "right";
        body[0]->setRotation(0);
        body[0]->setRotation(90);
    }
    else if(dir=="left"){
        direction = "left";
        body[0]->setRotation(0);
        body[0]->setRotation(-90);
    }
    else if(dir=="up"){
        direction = "up";
        body[0]->setRotation(0);
    }
    else if(dir=="down"){
        direction = "down";
        body[0]->setRotation(0);
        body[0]->setRotation(180);
    }
}

QString Snake::getDirection()
{
    return direction;
}
