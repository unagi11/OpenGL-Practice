//
//  MouseCallback.cpp
//  OpenGL-Practice
//
//  Created by 장이국 on 2021/03/24.
//

#include "Header.h"

using namespace std;

namespace MouseCallback {

float topLeftX, topLeftY, bottomRightX, bottomRightY;

void myDisplay(){

    cout << "(" << topLeftX << ", " << topLeftY << ")"
    << "(" << bottomRightX << ", " << bottomRightY << ")"
    << ">" << "(" << topLeftY / 400 << ", " << 1 - topLeftY / 400 << ")"
    << "(" << bottomRightX / 400 << ", " << 1 - bottomRightY / 400 << ")\n" ;

    glViewport(0, 0, 400, 400);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex3f(topLeftX / 400, 1 - topLeftY / 400, 0);
        glVertex3f(topLeftX / 400, 1 - bottomRightY / 400, 0);
        glVertex3f(bottomRightX / 400, 1 - bottomRightY / 400, 0);
        glVertex3f(bottomRightX / 400, 1 - topLeftY / 400, 0);
    glEnd();
    glFlush();
}

void myMouseClick(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        topLeftX = x;
        topLeftY = y;
    }
}

void myMouseMotion(int x, int y){
    bottomRightX = x;
    bottomRightY = y;
    glutPostRedisplay();
}

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Mouse Callback");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);

    glutDisplayFunc(MouseCallback::myDisplay);
    glutMouseFunc(MouseCallback::myMouseClick);
    glutMotionFunc(MouseCallback::myMouseMotion);
    //glutPassiveMotionFunc(MouseCallback::myMouseMotion);
    
    glutMainLoop();
    
    return 0;
    
}
