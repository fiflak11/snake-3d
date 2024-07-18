#ifndef SNAKE3D_GAMELOGIC_H
#define SNAKE3D_GAMELOGIC_H
#include <vector>

class GameLogic {
    char direction = 'r'; //default direction -> right
    std::vector<std::pair<short,short>> snake; //snake cells
public:
    GameLogic(short beginX, short beginY); //snake starting position
    void move();
    void changeDirection(char dir);
    std::vector<std::pair<short,short>> getSnake();
};

#endif //SNAKE3D_GAMELOGIC_H
