#include "../include/GlutHandling.h"
#include <GL/glut.h>
#include <memory>


void GlutHandling::startRendering(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("SNAKE 3D");
    glutDisplayFunc(&GlutHandling::display);
    glutReshapeFunc(&GlutHandling::reshape);
    glutKeyboardFunc(&GlutHandling::keyboard);
    glutSpecialFunc(&GlutHandling::specialKeys);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
void GlutHandling::display(){

}
void GlutHandling::reshape(int w,int h){

}
void GlutHandling::keyboard(unsigned char key, int x, int y){

}
void GlutHandling::specialKeys(int key, int x, int y){

}