#include "../include/Snake.h"
#include "../include/GameLogic.h"
#include <iostream>

int main(int argc, char * argv[]) {
    Snake snake;
    snake.startRendering(argc,argv);
    /*GameLogic gl(5,5);
    for(auto x : gl.getSnake())
        std::cout<<x.first<<" "<<x.second<<std::endl;
    gl.move();
    for(auto x : gl.getSnake())
        std::cout<<x.first<<" "<<x.second<<std::endl;
    gl.move();
    for(auto x : gl.getSnake())
        std::cout<<x.first<<" "<<x.second<<std::endl;
    gl.move();
    for(auto x : gl.getSnake())
        std::cout<<x.first<<" "<<x.second<<std::endl;*/
    return 0;
}
