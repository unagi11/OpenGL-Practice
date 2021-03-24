//
//  Viewport.cpp
//  OpenGL-Practice
//
//  Created by 장이국 on 2021/03/24.
//

#include "Header.h"

namespace Viewport
{
    void myDisplay()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(50, 50, 150, 150);
        glColor3f(1, 1, 1);
        glLineWidth(2);
        glBegin(GL_LINES);
            glVertex3f(-1, -1, 0);
            glVertex3f(-1, 1, 0);
        
            glVertex3f(-0.5, -1, 0);
            glVertex3f(-0.5, 1, 0);

            glVertex3f(0, -1, 0);
            glVertex3f(0, 1, 0);

            glVertex3f(0.5, -1, 0);
            glVertex3f(0.5, 1, 0);
        
            glVertex3f(1, -1, 0);
            glVertex3f(1, 1, 0);
        
            glVertex3f(-1, -1, 0);
            glVertex3f(1, -1, 0);

            glVertex3f(-1, -0.5, 0);
            glVertex3f(1, -0.5, 0);

            glVertex3f(-1, 0, 0);
            glVertex3f(1, 0, 0);

            glVertex3f(-1, 0.5, 0);
            glVertex3f(1, 0.5, 0);
        
            glVertex3f(-1, 1, 0);
            glVertex3f(1, 1, 0);
        glEnd();

        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
            glVertex3f(0.5, -0.5, 0);
            glVertex3f(0.5, 0.5, 0);
            glVertex3f(-0.5, 0.5, 0);
            glVertex3f(-0.5, -0.5, 0);
        glEnd();
        glFlush();
    }
}
/*
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutCreateWindow("viewport test");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc(Viewport:: myDisplay);
    glutMainLoop();
    
    return 0;
}
*/
