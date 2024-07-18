#include "../include/GameLogic.h"

GameLogic::GameLogic(short beginX, short beginY) {
    snake.push_back({beginX,beginY});
    snake.push_back({beginX-1,beginY});
    snake.push_back({beginX-2,beginY});
}
void GameLogic::move(){
    for(short i=snake.size()-1; i>0; i--)
        snake[i]=snake[i-1];
    switch (direction) {
        case 'r':
            snake[0].first++;
            break;
        case 'l':
            snake[0].first--;
            break;
        case 'u':
            snake[0].second++;
            break;
        case 'd':
            snake[0].second--;
            break;
    }

}
std::vector<std::pair<short,short>> GameLogic::getSnake() {
    return snake;
}
void GameLogic::changeDirection(char dir) {
    switch (dir) {
        case 'r':
            if(direction!='l')
                direction='r';
            break;
        case 'l':
            if(direction!='r')
                direction='l';
            break;
        case 'u':
            if(direction!='d')
                direction='u';
            break;
        case 'd':
            if(direction!='u')
                direction='d';
            break;
    }
}