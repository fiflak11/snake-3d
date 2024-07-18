#ifndef SNAKE3D_SNAKE_H
#define SNAKE3D_SNAKE_H
#include "GameLogic.h"
#include <GL/glut.h>

class Snake {
    GameLogic gameLogic;
    const short FPS = 3;
    const short WIDTH = 800, HEIGHT = 600;
    //camera setup
    std::vector<std::pair<short,short>> cameraCircle; //contains eyeX and eyeZ in each pair (the board rotates due to the movement of the camera)
    short cameraCirclePos=0; //current cameraCircle index (current camera position)
    GLdouble eyeY = 7; //camera position
    GLdouble centerX = gameLogic.getBoard().first/2, centerY = 0, centerZ = -gameLogic.getBoard().second/2;  //the direction in which the camera is looking
    GLdouble upX = 0, upY = 1, upZ = 0; //upVector - camera orientation
    //callbacks for glut
    void display();
    void reshape(int w,int h);
    void keyboard(unsigned char key, int x, int y);
    void specialKeys(int key, int x, int y);
    void timer(int x);
public:
    Snake();
    void startRendering(int argc, char * argv[]);
    //these functions set pointer declared in Snake.cpp on proper callback
    friend void displayCallback();
    friend void reshapeCallback(int w, int h);
    friend void keyboardCallback(unsigned char key, int x, int y);
    friend void specialKeysCallback(int key, int x, int y);
    friend void timerCallback(int x);
};

#endif //SNAKE3D_SNAKE_H
