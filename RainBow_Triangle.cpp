//
//  RainBow_Triangle.cpp
//  OpenGL-Practice
//
//  Created by 장이국 on 2021/03/10.
//

#include "Header.h"

#define PI 3.14

namespace RainBow_Triangle {

    void reshape(int w, int h)
    {
        glLoadIdentity();
        glViewport(0, 0, w, h);
        gluOrtho2D(0.0, 200, 0.0, 200.0);
    }

    void display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0, 1, 0);
        glRectf(30, 30.0, 50.0, 50.0);
        
        glColor3f(1, 0, 0);
        glBegin(GL_LINE_LOOP);
            glVertex2f(10, 10);
            glVertex2f(10, 50);
            glVertex2f(50, 50);
            glVertex2f(50, 10);
        glEnd();
        
        glutSwapBuffers();
    }

    void teapot(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 1, 0);
        glutSolidTeapot(0.5);
        glColor3f(1, 0, 0);
        glutWireTeapot(0.5);
        glFlush();
    }

    void dot_circle()
    {
        GLfloat size[2];
        GLfloat angle;
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 1, 1);
        glGetFloatv(GL_POINT_SIZE_RANGE, size);
        // glPointSize(size[0]);
        // glPointSize(size[1]);
        glPointSize(10);
        glBegin(GL_POINTS);
        for (angle = 0; angle <= 2 * PI; angle += PI / 10) {
            glVertex3f(0.5 * cos(angle), 0.5 * sin(angle), 0);
        }
        glEnd();
        glFlush();
    }

    void rainbow_line()
    {
        gluOrtho2D(-1, 6, -3, 3);
        
        glClear(GL_COLOR_BUFFER_BIT);
        glLineWidth(10);
        glBegin(GL_LINE_STRIP);

        glColor3f(1, 0, 0); // 빨
        glVertex3f(0, 0, 0);

        glColor3f(1, 1, 0); // 노
        glVertex3f(1, 0, 0);

        glColor3f(0, 1, 0); // 초
        glVertex3f(2, 0, 0);

        glColor3f(0, 1, 1); // 초
        glVertex3f(3, 0, 0);

        glColor3f(0, 0, 1); // 파
        glVertex3f(4, 0, 0);

        glColor3f(1, 0, 1); // 보
        glVertex3f(5, 0, 0);
        glEnd();
        
        glFlush();
    }

    void rainbow_triangle(){

        float angle = PI / 2;

        gluOrtho2D(-1.1, 1.1, -1.1, 1.1);
        glClear(GL_COLOR_BUFFER_BIT);
        glShadeModel(GL_SMOOTH);
        glBegin(GL_TRIANGLES);

        glColor3f(1, 0, 0);
        glVertex3f(cos(angle), sin(angle), 0);
        angle += PI * 4 / 3;

        glColor3f(0, 1, 0);
        glVertex3f(cos(angle), sin(angle), 0);
        angle += PI * 4 / 3;

        glColor3f(0, 0, 1);
        glVertex3f(cos(angle), sin(angle), 0);

        glEnd();
        
        glFlush();
    }

}

/*int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("OpenGL-Practice");
    //glutReshapeFunc(reshape);
    glClearColor(0, 0, 0, 1);
    glutDisplayFunc(RainBow_Triangle:: rainbow_triangle);
    glutMainLoop();
    
    return 0;
}*/
