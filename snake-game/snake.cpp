#include "snake.h"

Snake::Snake(QGraphicsScene * scene){
    alive = true;
    lenght = 3;
    speed = lenght + 1;
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
}
