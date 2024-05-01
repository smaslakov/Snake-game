#include "Pepper.h"
#include "SnakeAI.h"
#include "ItemsContainer.h"
#include <QDebug>

QGraphicsScene *s;

SnakeAI::SnakeAI(QGraphicsScene *scene, float StartPosX, float StartPosY, QString n) {
    PepperEffectActive = false;
    name = n;
    alive = true;
    lenght = 8;
    speed = 3;
    color = random() % 10 + 1;
    direction = "up";
    boundary = new QGraphicsEllipseItem(0, 0, 70, 70);
    boundary->setPen(QPen(Qt::transparent));
    boundary->setZValue(-1);
    scene->addItem(boundary);
    for (int i = 0; i < lenght; ++i) {
        SnakePart *snakepart = new SnakePart(name);
        if (i == 0) {
            snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/images/snakeUnit" + QString::number(color) + "Head.png"));
            snakepart->setTransformOriginPoint(snakepart->pixmap().width() / 2, snakepart->pixmap().height() / 2);
        } else {
            snakepart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/images/snakeUnit" + QString::number(color) + ".png"));
            snakepart->setZValue(-1 - (i % 100));
        }
        snakepart->setPos(StartPosX, StartPosY - 8 * (lenght - i));
        scene->addItem(snakepart);
        body.push_back(snakepart);
    }
    boundary = new QGraphicsEllipseItem(0, 0, 70, 70);
    boundary->setPen(QPen(Qt::transparent));
    boundary->setZValue(-1);
    scene->addItem(boundary);
    boundary->setX(body[0]->x() - boundary->rect().width() / 2);
    boundary->setY(body[0]->y() - boundary->rect().height() / 2);
    PepperAIActiveTimer = new QTimer();
    connect(PepperAIActiveTimer, &QTimer::timeout, this, &SnakeAI::PepperDisactive);
    SnakeAIMoveTimer = new QTimer();
    connect(SnakeAIMoveTimer, &QTimer::timeout, this, &SnakeAI::move);
    if (alive) SnakeAIMoveTimer->start(20);
}

void SnakeAI::move() {
    long double dx;
    long double dy;
    long double food_min_distance = std::numeric_limits<long double>::max();  // Initialize min_distance with a large value
    long double pepper_min_distance = std::numeric_limits<long double>::max();  // Initialize min_distance with a large value
    QPointF snakesHeadPosition = body[0]->pos();
    QPointF closestFoodPosition = QPointF(0, 0);
    QPointF closestPepperPosition = QPointF(0, 0);

    for (int i = 0; i < ItemsContainer::allFoods.size(); ++i) {
        long long x = abs(snakesHeadPosition.rx() - ItemsContainer::allFoods[i]->x());
        long double y = abs(snakesHeadPosition.ry() - ItemsContainer::allFoods[i]->y());
        long double distance = std::sqrt(x * x + y * y);

        if (distance < food_min_distance) {
            food_min_distance = distance;
            //qDebug() << i << ItemsContainer::allFoods[i]->pos();
            closestFoodPosition = ItemsContainer::allFoods[i]->pos();
        }
    }
    for (int i = 0; i < ItemsContainer::allPeppers.size(); ++i) {
        long long x = abs(snakesHeadPosition.rx() - ItemsContainer::allPeppers[i]->x());
        long double y = abs(snakesHeadPosition.ry() - ItemsContainer::allPeppers[i]->y());
        long double distance = std::sqrt(x * x + y * y);
        if (distance < pepper_min_distance) {
            pepper_min_distance = distance;
            closestPepperPosition = ItemsContainer::allPeppers[i]->pos();
        }
    }
   /* if ((PepperEffectActive || ItemsContainer::allPeppers.empty()) && ItemsContainer::allFoods.empty()) {
        if ((rand() % 100) % 3 == 0) {
            int r = rand() % 4;
            if (r == 0 && direction != "left") {
                direction = "right";
            } else if (r == 1 && direction != "right") {
                direction = "left";
            } else if (r == 2 && direction != "down") {
                direction = "up";
            } else if (r == 3 && direction != "up") {
                direction = "down";
            }
        }
    }*/
    if (pepper_min_distance < food_min_distance) {
        dx = closestPepperPosition.rx() - snakesHeadPosition.rx();
        dy = closestPepperPosition.ry() - snakesHeadPosition.ry();
    } else {
        dx = closestFoodPosition.rx() - snakesHeadPosition.rx();
        dy = closestFoodPosition.ry() - snakesHeadPosition.ry();
    }
    if (dx == 0 && dy != 0) {
        if (dy < 0) {
            setDirection("up");
        } else {
            setDirection("down");
        }
    } else if (dy == 0 && dx != 0) {
        if (dx < 0) {
            setDirection("left");
        } else {
            setDirection("right");
        }
    } else {
        if (std::abs(dx) >= std::abs(dy)) {
            if (dx > 0) {
                setDirection("right");
            } else {
                setDirection("left");
            }
        } else {
            if (dy > 0) {
                setDirection("down");
            } else {
                setDirection("up");
            }
        }
    }
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
            newBodyPart->setPixmap(QPixmap("/Users/sagot/Documents/Snake-game/images/snakeUnit" + QString::number(color) + ".png"));
            if (direction == "right" || direction == "left") {
                newBodyPart->setPos(body[body.length() - 1]->pos().rx() - 8, body[body.length() - 1]->pos().ry());
            }
            newBodyPart->setPos(body[body.length() - 1]->pos().rx(), body[body.length() - 1]->pos().ry() - 8);
            body[0]->scene()->addItem(newBodyPart);
            body.append(newBodyPart);
            lenght++;
        } else if (typeid(*(colliding_items[i])) == typeid(Pepper)) {
            body[0]->scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            ItemsContainer::allPeppers.removeOne(colliding_items[i]);
            //PepperEffectActive = true;
            SnakeAIMoveTimer->start(5);
            PepperAIActiveTimer->start(4000);
        } else if (typeid(*(colliding_items[i])) == typeid(SnakePart) &&
                   ((SnakePart *) colliding_items[i])->snakeName != name) {
            destroySnake();
            break;
        }else if (typeid(*(colliding_items[i])) == typeid(Stone)) {
            body[0]->scene()->removeItem(colliding_items[i]);
            ItemsContainer::allStones.removeOne(colliding_items[i]);
            delete colliding_items[i];
            destroySnake();
            break;
        }
    }
}

    void SnakeAI::PepperDisactive() {
        /*for(QGraphicsPixmapItem* part : body){
        }*/
        SnakeAIMoveTimer->start(20);
        //PepperEffectActive = false;
    }

    void SnakeAI::setDirection(QString dir) {
        if (dir == "right") {
            direction = "right";
            body[0]->setRotation(0);
            body[0]->setRotation(90);
        } else if (dir == "left") {
            direction = "left";
            body[0]->setRotation(0);
            body[0]->setRotation(-90);
        } else if (dir == "up") {
            direction = "up";
            body[0]->setRotation(0);
        } else if (dir == "down") {
            direction = "down";
            body[0]->setRotation(0);
            body[0]->setRotation(180);
        }
    }

    void SnakeAI::destroySnake() {
        alive = false;
        for (int i = 0; i < body.size(); ++i) {
            Food *food = new Food(body[i]->x(), body[i]->y());
            body[i]->scene()->addItem(food);
            ItemsContainer::allFoods.push_back(food);
            body[i]->scene()->removeItem(body[i]);
        }
        ItemsContainer::allSnakesAI.removeOne(this);
    }

    QString SnakeAI::getDirection() {
        return direction;

    }

    void SnakeAI::setSpeed(int s) {
        speed = s;
    }

    int SnakeAI::getSpeed() {
        return speed;
    }

    void SnakeAI::CheckCollision() {
        bool threat = false;
        int threatPointX, threatPointY;
        QList<QGraphicsItem *> boundary_items = boundary->collidingItems();
        for (int i = 0; i < boundary_items.size(); i++) {
            //if its other's boundary or body
            if (typeid(*(boundary_items[i])) == typeid(QGraphicsEllipseItem)) {
                threat = true;
                threatPointX = (boundary_items[i])->x();
                threatPointY = (boundary_items[i])->y();
            }
        }
        if (threat == true) {

        }
    }
QPointF SnakeAI::getAIHeadPos(){
    return body[0]->pos();
}
void SnakeAI::pause_snakeAI() {
    SnakeAIMoveTimer->stop();
    PepperAIActiveTimer->stop();
    pepperAITimerRemainingTime = PepperAIActiveTimer->remainingTime();
}

void SnakeAI::continue_snakeAI() {
    SnakeAIMoveTimer->start(20);
    PepperAIActiveTimer->start(pepperAITimerRemainingTime);
}