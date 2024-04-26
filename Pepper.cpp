
#include "Pepper.h"
Pepper::Pepper(QGraphicsScene* scene){
    QString imagePath = "/Users/sagot/Documents/Snake-game/images/7.png";
    setPixmap(QPixmap(imagePath).scaled(20,20));
    setPos(rand() % 4000, rand() % 4000);
    scene->addItem(this);
}
