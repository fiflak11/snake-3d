#include "../include/Snake.h"
#include <GL/glut.h>
#include <memory>
#include <iostream>

std::shared_ptr<Snake> currentInstance=nullptr; //glut functions require callbacks
//so I create a pointer instead of making every function static
void displayCallback(); //functions setting currentInstance
void reshapeCallback(int w, int h); //implementation at the very bottom
void keyboardCallback(unsigned char key, int x, int y);
void specialKeysCallback(int key, int x, int y);
void timerCallback(int x);

Snake::Snake() : gameLogic(BOARDSIZE.first/2,BOARDSIZE.second/2){}

void Snake::startRendering(int argc, char **argv){
    currentInstance = std::make_shared<Snake>(*this); //set the pointer to an object
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("SNAKE 3D");
    glutDisplayFunc(displayCallback);
    glutReshapeFunc(reshapeCallback);
    glutKeyboardFunc(keyboardCallback);
    glutSpecialFunc(specialKeysCallback);
    glutTimerFunc(0,timerCallback,0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
void Snake::display(){
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
    glColor3f( 0.0, 1.0, 0.0 );
    for(int i{0}; i<BOARDSIZE.first; i++){
        for(int j{0}; j<BOARDSIZE.second; j++){
            glTranslatef( j, 0, -i );
            glutWireCube( 1.0 );
            glTranslatef( -j, -0, i );
        }
    }
    glColor3f( 1.0, 1.0, 1.0 );
    for(auto cell : gameLogic.getSnake()){
        glTranslatef( cell.first, 0, -cell.second );
        glutWireCube( 1.0 );
        glTranslatef( -cell.first, 0, cell.second );
    }

    glFlush();
    glutSwapBuffers();
}
void Snake::reshape(int w,int h){
    glViewport( 0, 0, WIDTH, HEIGHT );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum( - 2.0, 2.0, - 2.0, 2.0, 1.0, 100.0 );
}
void Snake::keyboard(unsigned char key, int x, int y){

}
void Snake::specialKeys(int key, int x, int y){

}
void Snake::timer(int x){
    gameLogic.move();
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timerCallback,0);
}

void displayCallback() {
    if (currentInstance){
        currentInstance->display();
    }
}
void reshapeCallback(int w, int h) {
    if (currentInstance){
        currentInstance->reshape(w, h);
    }
}
void keyboardCallback(unsigned char key, int x, int y) {
    if (currentInstance){
        currentInstance->keyboard(key, x, y);
    }
}
void specialKeysCallback(int key, int x, int y) {
    if (currentInstance){
        currentInstance->specialKeys(key, x, y);
    }
}
void timerCallback(int x) {
    if (currentInstance){
        currentInstance->timer(x);
    }
}