
#ifndef SNAKE_GAME_ITEMSCONTAINER_H
#define SNAKE_GAME_ITEMSCONTAINER_H
#include "food.h"
#include "snake.h"
#include "Pepper.h"
#include "SnakeAI.h"
#include "Stone.h"
class ItemsContainer {
public:
    static QVector<SnakeAI*> allSnakesAI;
    static QVector<Pepper*> allPeppers;
    static QVector<Food*> allFoods;
    static QVector<QString> allNames;
    static QVector<Stone*> allStones;
};


#endif //SNAKE_GAME_ITEMSCONTAINER_H
