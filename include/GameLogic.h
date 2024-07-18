#ifndef SNAKE3D_GAMELOGIC_H
#define SNAKE3D_GAMELOGIC_H
#include <vector>

class GameLogic {
    const std::pair<short,short> BOARDSIZE{10,10};
    char direction = 'r'; //default direction -> right
    std::vector<std::pair<short,short>> snake; //snake cells
    std::pair<short,short> food;
    void foodRandomization();
public:
    GameLogic(); //snake starting position
    void move();
    void changeDirection(char dir);
    std::pair<short,short> getBoard();
    std::pair<short,short> getFood();
    std::vector<std::pair<short,short>> getSnake();
};

#endif //SNAKE3D_GAMELOGIC_H
