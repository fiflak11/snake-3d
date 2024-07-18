#include "../include/Snake.h"
#include <GL/glut.h>
#include <memory>
#include <iostream>
Snake::Snake() {
    float resolution=1;
    for(float i{5},j{5}; i<15; i+=resolution,j-=resolution)
        cameraCircle.push_back({i,j});
    for(float i{15},j{-5}; i>5; i-=resolution,j-=resolution)
        cameraCircle.push_back({i,j});
    for(float i{5},j{-15}; i>-5; i-=resolution,j+=resolution)
        cameraCircle.push_back({i,j});
    for(float i{-5},j{-5}; i<5; i+=resolution,j+=resolution)
        cameraCircle.push_back({i,j});
}

std::shared_ptr<Snake> currentInstance=nullptr; //glut functions require callbacks
//so I create a pointer instead of making every function static
void displayCallback(); //functions setting currentInstance
void reshapeCallback(int w, int h); //implementation at the very bottom
void keyboardCallback(unsigned char key, int x, int y);
void specialKeysCallback(int key, int x, int y);
void timerCallback(int x);

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
    static auto currentCameraPos = cameraCircle.begin();
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(cameraCircle[cameraCirclePos].first, eyeY, cameraCircle[cameraCirclePos].second, centerX, centerY, centerZ, upX, upY, upZ);
    for(int i{gameLogic.getBoard().first}; i>0; i--){ //drawing board
        for(int j{gameLogic.getBoard().second}; j>0; j--){
            glTranslatef( j, -1, -i );
            if((i+j)%2)
                glColor3f(0.0, 1, 0.0);
            else
                glColor3f(0.0, 0.5, 0.0);
            glutSolidCube(1); //createColoredWireCube(0.0,0.5,0.0,1);
            glTranslatef( -j, 1, i );
        }
    }
    auto snake = gameLogic.getSnake(); //drawing snake
    for(short i{0}; i<snake.size(); i++) {
        glTranslatef(snake[i].first, 0, -snake[i].second);
        if (!i)
            glColor3f(0.3, 0.3, 1.0);
        else if (i % 2)
            glColor3f(0.0, 0.0, 0.9);
        else
            glColor3f(0.0, 0.0, 0.8);
        glutSolidCube(1);
        glTranslatef(-snake[i].first, 0, snake[i].second);
    }
    std::pair<short,short> food = gameLogic.getFood(); //drawing food
    glTranslatef(food.first, 0, -food.second);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(1);
    glTranslatef(-food.first, 0, food.second);
    if(gameLogic.checkCollisions())
        gameLogic.restart();
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
    if( key == 'w' )
        gameLogic.changeDirection('u');
    if( key == 's' )
        gameLogic.changeDirection('d');
    if( key == 'a' )
        gameLogic.changeDirection('l');
    if( key == 'd' )
        gameLogic.changeDirection('r');
    if( key == 'y' )
        centerX+=1;
    if( key == 'h' )
        centerX-=1;
    if( key == 'u' )
        centerY+=1;
    if( key == 'j' )
        centerY-=1;
    if( key == 'i' )
        centerZ+=1;
    if( key == 'k' )
        centerZ-=1;
    std::cout<<centerX<<" "<<centerY<<" "<<centerZ<<" "<<std::endl;
}
void Snake::specialKeys(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            if(cameraCirclePos==cameraCircle.size()-1)
                cameraCirclePos=0;
            else
                cameraCirclePos++;
            break;
        case GLUT_KEY_LEFT:
            if(cameraCirclePos==0)
                cameraCirclePos=cameraCircle.size()-1;
            else
                cameraCirclePos--;
            break;
    }
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
