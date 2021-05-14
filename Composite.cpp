//
//  main2.cpp
//  OpenGL-Practice
//
//  Created by 장이국 on 2021/03/19.
//

#include "Header.h"

namespace Composite {

using namespace std;

float zoom = 45;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glMatrixMode(GL_MODELVIEW);
    
    // 빨강 사각형
    glColor3f(1, 0, 0);
    glLoadIdentity();
    glutSolidCube(0.3);
    
    // 초록 사각형 : 이동후 원점회전
    glColor3f(0, 1, 0);
    glLoadIdentity();
    glRotatef(zoom , 1, 1, 1);
    glTranslatef(0.6, 0, 0);
    glutSolidCube(0.3);

    // 파랑 사각형 : 원점회전후 이동
    glColor3f(0, 0, 1);
    glLoadIdentity();
    glTranslatef(0.6, 0, 0);
    glRotatef(zoom, 1, 1, 1);
    glutSolidCube(0.3);
    
    glFlush();
    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'a') // zoom in
        zoom += 5;
    else if (key == 'z') // zoom out
        zoom -= 5;
    
    cout << "zoom: " << zoom << endl;
    glutPostRedisplay();
}


}

/*
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Composite");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc(Composite:: MyDisplay);
    glutKeyboardFunc(Composite:: keyboard);
    glutMainLoop();
    
    return 0;
}
*/