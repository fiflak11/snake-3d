#include "../include/GameLogic.h"
#include<cstdlib>
#include <time.h>
#include <algorithm>
#include <iostream>

GameLogic::GameLogic() {
    srand(time(NULL));
    restart();
}
void GameLogic::restart() {
    snake.clear();
    direction='r';
    food={rand()%BOARDSIZE.first+1,rand()%BOARDSIZE.second+1};
    snake.push_back({BOARDSIZE.first/2,BOARDSIZE.second/2});
    snake.push_back({BOARDSIZE.first/2-1,BOARDSIZE.second/2});
    snake.push_back({BOARDSIZE.first/2-2,BOARDSIZE.second/2});
}
void GameLogic::move(){
    foodRandomization();
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
std::pair<short,short> GameLogic::getBoard(){
    return BOARDSIZE;
}
std::pair<short,short> GameLogic::getFood(){
    return food;
}
void GameLogic::foodRandomization() {
    bool f=true;
    while(std::find(snake.begin(),snake.end(),food)!=snake.end()){
        food={rand()%BOARDSIZE.first+1,rand()%BOARDSIZE.second+1};
        if(f){
            f=false;
            snake.push_back(snake.back());
        }
    }
}
bool GameLogic::checkCollisions() {
    if(std::find(snake.begin()+1,snake.end(),snake.front())!=snake.end())
        return true;
    else if(snake.front().first>BOARDSIZE.first || snake.front().first<=0)
        return true;
    else if(snake.front().second>BOARDSIZE.second || snake.front().second<=0)
        return true;
    return false;
}