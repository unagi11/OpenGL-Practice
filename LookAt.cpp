//
//  LookAt.cpp
//  OpenGL-Practice
//
//  Created by 장이국 on 2021/03/19.
//

#include "Header.h"

using namespace std;

namespace LookAt {

GLdouble zoom = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    gluLookAt(0.5 * cos(zoom), 0.1, 0.5 * sin(zoom), 0, 0, 0, 0, 1, 0);

    glLineWidth(1);

    glColor3f(0.3, 0.3, 0.3 );
    glutWireTeapot(0.5);
    
    glLineWidth(10);

    glBegin(GL_LINES);
    
    glColor3f(1, 0, 0); // 빨
    glVertex3f(0, 0, 0);
    glVertex3f(.5, 0, 0);

    glColor3f(0, 1, 0); // 초
    glVertex3f(0, 0, 0);
    glVertex3f(0, .5, 0);

    glColor3f(0, 0, 1); // 파
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, .5);
    glEnd();

    
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'a') // zoom in
        zoom += 0.1;
    else if (key == 'z') // zoom out
        zoom -= 0.1;
    
    cout << "zoom: " << zoom << endl;
    glutPostRedisplay();
}

}

/*
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("LookAt Example");
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(LookAt::display);
    glutKeyboardFunc(LookAt::keyboard);
    glutMainLoop();
    
    return 0;
}
 */
