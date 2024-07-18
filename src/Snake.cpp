#include "../include/Snake.h"

#include <GL/glut.h>
#include <memory>


void Snake::startRendering(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("SNAKE 3D");
    glutDisplayFunc(&Snake::display);
    glutReshapeFunc(&Snake::reshape);
    glutKeyboardFunc(&Snake::keyboard);
    glutSpecialFunc(&Snake::specialKeys);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
void Snake::display(){

}
void Snake::reshape(int w,int h){

}
void Snake::keyboard(unsigned char key, int x, int y){

}
void Snake::specialKeys(int key, int x, int y){

}