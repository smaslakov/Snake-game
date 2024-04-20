#include "food.h"



Food::Food(QGraphicsScene * scene)
{
    QString imagePath = "/Users/sagot/Documents/Snake-game/snake-game/images/f" + QString::number((rand() % 7) + 1) + ".png";
    setPixmap(QPixmap(imagePath));
    setPos(rand() % 1000, rand() % 800);
    scene->addItem(this);
}
