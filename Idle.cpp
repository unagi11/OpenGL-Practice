//
//  Idle.cpp
//  OpenGL-Practice
//
//  Created by 장이국 on 2021/03/24.
//

#include "Header.h"

using namespace std;

namespace Idle {

GLfloat Delta = 0;

void MyDisplay()
{
    //glClear(GL_COLOR_BUFFER_BIT);

    //glPointSize(4);
    glBegin(GL_POLYGON);
//    glBegin(GL_POINTS);
    
    GLfloat temp = Delta * 3.14 * 50;
    GLfloat radius = sin(Delta * 10) * 2;
    
    cout << temp << endl;
        
    glColor3f(1, 0, 0);
    glVertex3f(radius * cos(temp), radius * sin(temp), 0);
    
    glColor3f(1, 1, 0);
    glVertex3f(radius * cos(temp + 3.14 / 3), radius * sin(temp + 3.14 / 3), 0);
    
    glColor3f(0, 1, 0);
    glVertex3f(radius * cos(temp + 3.14 / 3 * 2), radius * sin(temp + 3.14 / 3 * 2), 0);
    
    glColor3f(0, 1, 1);
    glVertex3f(radius * cos(temp + 3.14 / 3 * 3), radius * sin(temp + 3.14 / 3 * 3), 0);
    
    glColor3f(0, 0, 1);
    glVertex3f(radius * cos(temp + 3.14 / 3 * 4), radius * sin(temp + 3.14 / 3 * 4), 0);
    
    glColor3f(1, 0, 1);
    glVertex3f(radius * cos(temp + 3.14 / 3 * 5), radius * sin(temp + 3.14 / 3 * 5), 0);
    glEnd();
    
    glFlush();
}

void MyIdle()
{
    Delta += 0.0005;
    glutPostRedisplay();
}
}
/*
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Idle test");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -1, 1);
    glutDisplayFunc(Idle::MyDisplay);
    glutIdleFunc(Idle::MyIdle);
    glutMainLoop();
    
    return 0;
}
*/