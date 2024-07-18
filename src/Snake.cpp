#include "../include/Snake.h"
#include <GL/glut.h>
#include <iostream>

void Snake::startRendering(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("SNAKE 3D");
    glutDisplayFunc(&Snake::display);
    glutReshapeFunc(&Snake::reshape);
    glutKeyboardFunc(&Snake::keyboard);
    glutSpecialFunc(&Snake::specialKeys);
    glutTimerFunc(0,&Snake::timer,0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
void Snake::display(){
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
    glColor3f( 1.0, 1.0, 1.0 );
    //start rendering blocks
    const int N=10,K=10;
    for(int i{0}; i<N; i++){
        for(int j{0}; j<K; j++){
            glTranslatef( 1, 0.0, 0.0 );
            glutWireCube( 1.0 );
        }
        glTranslatef( -K, 0.0, -1.0 );
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
void Snake::timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}

GLdouble Snake::eyeX = 5.7;
GLdouble Snake::eyeY = 9.4;
GLdouble Snake::eyeZ = 0.6;

GLdouble Snake::centerX = 6;
GLdouble Snake::centerY = -55;
GLdouble Snake::centerZ = - 100;

GLdouble Snake::upX = 0;
GLdouble Snake::upY = 1;
GLdouble Snake::upZ = 0;