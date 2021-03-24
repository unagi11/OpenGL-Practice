//
//  Teapot.cpp
//  OpenGL-Practice
//
//  Created by 장이국 on 2021/03/19.
//

#include "Header.h"

using namespace std;

GLdouble zoom = 0.5;

namespace Teapot {

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.f, 1.f, 0.f);
    glutSolidTeapot(zoom);
    glColor3f(1.f, 0.f, 0.f);
    glutWireTeapot(zoom);
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
    glutCreateWindow("Teapot Example");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(Teapot::display);
    glutKeyboardFunc(Teapot::keyboard);
    glutMainLoop();
    
    return 0;
}
*/
