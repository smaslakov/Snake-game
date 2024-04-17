#include "food.h"


void Food::resetFood()
{
    for(QGraphicsPixmapItem* a : allfood){
        QString imagePath = "/Users/sagot/Documents/Snake-game/snake-game/images/f" + QString::number((rand() % 7) + 1) + ".png";
        a->setPixmap(QPixmap(imagePath));
        a->setPos(rand() % 1000, rand() % 800);
    }
}

Food::Food(QGraphicsScene * scene)
{
    for (int i = 0; i < 50; ++i) {
        QGraphicsPixmapItem* vkysnyaxa = new QGraphicsPixmapItem();
        QString imagePath = "/Users/sagot/Documents/Snake-game/snake-game/images/f" + QString::number((rand() % 7) + 1) + ".png";
        vkysnyaxa->setPixmap(QPixmap(imagePath));
        vkysnyaxa->setPos(rand() % 1000, rand() % 800);
        scene->addItem(vkysnyaxa);
        allfood.push_back(vkysnyaxa);
    }
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&Food::resetFood);
    timer->start(30000);
}
