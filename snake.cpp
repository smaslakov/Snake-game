#include "snake.h"
#include "Pepper.h"
#include "ItemsContainer.h"
#include <QDebug>
QGraphicsScene* sc;
Snake::Snake(QGraphicsScene *scene,float StartPosX,float StartPosY,QString n) {
    name = n;
    alive = true;
    lenght = 8;
    speed = 2;
    direction = "up";
    ItemsContainer::allSnakes.push_back(this);
    for (int i = 0; i < lenght; ++i) {
        SnakePart *snakepart = new SnakePart(name);
        if (i == 0) {
            snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/images/snakeUnit9Head.png"));
            snakepart->setTransformOriginPoint(snakepart->pixmap().width() / 2, snakepart->pixmap().height() / 2);
        } else {
            snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/images/snakeUnit9.png"));
            snakepart->setZValue(-1 - (i % 100));
        }
        snakepart->setPos(StartPosX, StartPosY - 8 * (lenght - i));
        scene->addItem(snakepart);
        body.push_back(snakepart);
    }
    PepperActiveTimer = new QTimer();
    connect(PepperActiveTimer, &QTimer::timeout, this, &Snake::PepperDisactive);
    SnakeMoveTimer = new QTimer();
    connect(SnakeMoveTimer, &QTimer::timeout, this, &Snake::move);
    SnakeMoveTimer->start(20);
}

void Snake::move() {
    for (int i = body.length() - 1; i >= 0; --i) {
        if (i != 0) {
            body[i]->setY(body[i - 1]->y());
            body[i]->setX(body[i - 1]->x());
            continue;
        }
        if (direction == "up") {
            body[i]->setY(body[i]->y() - speed);
        }
        if (direction == "down") {
            body[i]->setY(body[i]->y() + speed);
        }
        if (direction == "right") {
            body[i]->setX(body[i]->x() + speed);
        }
        if (direction == "left") {
            body[i]->setX(body[i]->x() - speed);
        }
    }

    QList<QGraphicsItem *> colliding_items = body[0]->collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*(colliding_items[i])) == typeid(Food)) {
            body[0]->scene()->removeItem(colliding_items[i]);
            ItemsContainer::allFoods.removeOne(colliding_items[i]);
            delete colliding_items[i];
            SnakePart *newBodyPart = new SnakePart(name);
            newBodyPart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/images/snakeUnit9.png"));
            newBodyPart->setPos(-1212121, -100121);
            body[0]->scene()->addItem(newBodyPart);
            body.append(newBodyPart);
            lenght++;
        }else if (typeid(*(colliding_items[i])) == typeid(Pepper)) {
            body[i]->scene()->removeItem(colliding_items[i]);
            ItemsContainer::allPeppers.removeOne(colliding_items[i]);
            delete colliding_items[i];
            //speed = 3;
            SnakeMoveTimer->start(5);
            PepperActiveTimer->start(4000);
        }else if (typeid(*(colliding_items[i])) == typeid(SnakePart) && ((SnakePart*)colliding_items[i])->snakeName != name) {
            destroySnake();
            break;
        }
    }
    emit moveSignal();
}
void Snake::PepperDisactive(){
    SnakeMoveTimer->start(20);
    //speed = 2;
}
void Snake::setDirection(QString dir) {
    if(dir=="right" && direction != "left"){
        direction = "right";
        body[0]->setRotation(0);
        body[0]->setRotation(90);
    }
    else if(dir=="left" && direction != "right"){
        direction = "left";
        body[0]->setRotation(0);
        body[0]->setRotation(-90);
    }
    else if(dir=="up" && direction != "down"){
        direction = "up";
        body[0]->setRotation(0);
    }
    else if(dir=="down" && direction != "up"){
        direction = "down";
        body[0]->setRotation(0);
        body[0]->setRotation(180);
    }
}

void Snake::destroySnake() {
    alive = false;
    qDebug() << "----------------------------------";
    for(int i = 0;i < body.size();++i) {
        Food* food = new Food( body[i]->x(), body[i]->y());
        body[i]->scene()->addItem(food);
        qDebug() <<  "P" <<food->x() << food->y() << food->boundingRect();
        ItemsContainer::allFoods.push_back(food);
        ItemsContainer::allSnakes.removeOne(this);
        body[i]->scene()->removeItem(body[i]);
    }
    qDebug() << "----------------------------------";
}
QString Snake::getDirection() {
    return direction;

}

void Snake::setSpeed(int s) {
    speed = s;
}

int Snake::getSpeed() {
    return speed;
}
QPointF Snake::getHeadPos(){
    return body[0]->pos();
}