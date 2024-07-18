#ifndef SNAKE3D_SNAKE_H
#define SNAKE3D_SNAKE_H
#include <GL/glut.h>

class Snake {
    const static short FPS = 10;
    const static short WIDTH = 800, HEIGHT = 600;
    //camera setup
    static GLdouble eyeX, eyeY, eyeZ;           //camera position
    static GLdouble centerX, centerY, centerZ;  //the direction in which the camera is looking
    static GLdouble upX, upY, upZ;              //upVector - camera orientation
    //callbacks for glut
    static void display();
    static void reshape(int w,int h);
    static void keyboard(unsigned char key, int x, int y);
    static void specialKeys(int key, int x, int y);
    static void timer(int);
public:
    //Snake();
    void startRendering(int argc, char * argv[]);
};

#endif //SNAKE3D_SNAKE_H
