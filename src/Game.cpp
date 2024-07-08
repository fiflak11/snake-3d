#include "../include/Game.h"
#include "../include/GameLogic.h"
#include "../include/GlutHandling.h"

void Game::start(int argc, char * argv[]) {
    GlutHandling glutHandling;
    GameLogic gameLogic;
    glutHandling.startRendering(argc,argv);
}