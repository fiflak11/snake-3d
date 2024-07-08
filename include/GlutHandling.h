#ifndef SNAKE3D_GLUTHANDLING_H
#define SNAKE3D_GLUTHANDLING_H

class GlutHandling {
    static void display();
    static void reshape(int w,int h);
    static void keyboard(unsigned char key, int x, int y);
    static void specialKeys(int key, int x, int y);
public:
    void startRendering(int argc, char * argv[]);
};

#endif //SNAKE3D_GLUTHANDLING_H
