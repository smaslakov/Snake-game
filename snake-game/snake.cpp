#include "snake.h"
#include <QDebug>
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

// void Snake::move()
// {
//     for(int i = body.length() - 1;i >= 0;--i){
//         if(i != 0){
//             body[i]->setY(body[i - 1]->y());
//             body[i]->setX(body[i - 1]->x());
//             continue;
//         }
//         if(direction == "up"){
//             body[i]->setY(body[i]->y() - speed);
//         }
//         if(direction == "down"){
//             body[i]->setY(body[i]->y() + speed);
//         }
//         if(direction == "right"){
//             body[i]->setX(body[i]->x() + speed);
//         }
//         if(direction == "left"){
//             body[i]->setX(body[i]->x() - speed);
//         }
//     }
//     // QList<QGraphicsItem*> food= body[0]->collidingItems();
//     // for(int i = 0;i < food.length();++i){
//     //     if(typeid(*(food[i])) == typeid(Food)){

//     //         body[0]->scene()->removeItem(food[i]);
//     //         delete food[i];
//     //         QGraphicsPixmapItem* snakepart = new QGraphicsPixmapItem();
//     //         snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/snakeUnit9.png"));
//     //         snakepart->setZValue(-1 - (i % 100));
//     //         if(direction == "right" || direction == "left"){
//     //            snakepart->setPos(body[0]->pos().rx() - 8 * lenght,body[0]->pos().ry());
//     //         }
//     //         snakepart->setPos(body[0]->pos().rx(),body[0]->pos().ry() - 8 * lenght);
//     //         body[0]->scene()->addItem(snakepart);
//     //         body.push_back(snakepart);
//     //     }
//     // }
//     // QList<QGraphicsItem *> colliding_items = body[0]->collidingItems();
//     // for(int i = 0; i < colliding_items.size(); i++){
//     //     //food
//     //     qDebug() << colliding_items[i]->pos();
//     //     Food *food = dynamic_cast<Food*>(colliding_items[i]);
//     //     qDebug() << colliding_items[i]->pos();
//     //         //qDebug() << "Eat pidor";
//     //         body[0]->scene()->removeItem(colliding_items[i]);
//     //         //delete colliding_items[i];
//     //         QGraphicsPixmapItem*e = new QGraphicsPixmapItem();
//     //         e->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/snakeUnit9.png"));
//     //         if(direction == "right" || direction == "left"){
//     //         e->setPos(body[0]->pos().rx() - 8 * lenght,body[0]->pos().ry());
//     //         }
//     //         e->setPos(body[0]->pos().rx(),body[0]->pos().ry() - 8 * lenght);
//     //         body[0]->scene()->addItem(e);
//     //         body.append(e);
//     //     }
//     // }
//     QList<QGraphicsItem *> colliding_items = body[0]->collidingItems();
//     for(int i = 0; i < colliding_items.size(); i++){
//         //food
//         if (colliding_items[i]->collidesWithItem(body[0])){
//             body[0]->scene()->removeItem(colliding_items[i]);
//             QGraphicsPixmapItem*e = new QGraphicsPixmapItem();
//             e->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/snakeUnit9.png"));
//             if(direction == "right" || direction == "left"){
//                 e->setPos(body[0]->pos().rx() - 8 * lenght, body[0]->pos().ry());
//             }
//             e->setPos(body[0]->pos().rx(), body[0]->pos().ry() - 8 * lenght);
//             body[0]->scene()->addItem(e);
//             body.append(e);
//         }
//     }
// }
void Snake::move()
{
    for(int i = body.length() - 1; i >= 0; --i){
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

    QList<QGraphicsItem *> colliding_items = body[0]->collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        qDebug() << colliding_items[i]->pos();
        // Check collision with food
        Food *food = dynamic_cast<Food*>(colliding_items[i]);
        if(food != nullptr){
            body[0]->scene()->removeItem(food);
            delete food;

            QGraphicsPixmapItem* newBodyPart = new QGraphicsPixmapItem();
            newBodyPart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/snake-game/images/snakeUnit9.png"));
            if(direction == "right" || direction == "left"){
                newBodyPart->setPos(body[body.length() - 1]->pos().rx() - 8, body[body.length() - 1]->pos().ry());
            }
            newBodyPart->setPos(body[body.length() - 1]->pos().rx(), body[body.length() - 1]->pos().ry() - 8);
            body[0]->scene()->addItem(newBodyPart);
            body.append(newBodyPart);

            // Increase the length of the snake by one unit
            lenght++;

            // Additional actions after eating the food can be added here,
            // such as increasing the player's score or checking win/lose conditions.
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

void Snake::setSpeed(int s)
{
    speed = s;
}
int Snake::getSpeed()
{
    return speed;
}
