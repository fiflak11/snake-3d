#ifndef SNAKE3D_SNAKE_H
#define SNAKE3D_SNAKE_H
#include "GameLogic.h"
#include <GL/glut.h>
#include <memory>

class Snake {
    GameLogic gameLogic;
    const short FPS = 3;
    const short WIDTH = 800, HEIGHT = 600;
    //camera setup
    GLdouble eyeX = 5.7, eyeY = 9.4, eyeZ = 0.6;           //camera position
    GLdouble centerX = 6, centerY = -55, centerZ = - 100;  //the direction in which the camera is looking
    GLdouble upX = 0, upY = 1, upZ = 0;                    //upVector - camera orientation
    //callbacks for glut
    void display();
    void reshape(int w,int h);
    void keyboard(unsigned char key, int x, int y);
    void specialKeys(int key, int x, int y);
    void timer(int x);
public:
    void startRendering(int argc, char * argv[]);
    //these functions set pointer declared in Snake.cpp on proper callback
    friend void displayCallback();
    friend void reshapeCallback(int w, int h);
    friend void keyboardCallback(unsigned char key, int x, int y);
    friend void specialKeysCallback(int key, int x, int y);
    friend void timerCallback(int x);
};

#endif //SNAKE3D_SNAKE_H
