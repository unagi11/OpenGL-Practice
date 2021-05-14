 //문제는 원근 투영을 이용하여 육면체와 주전자의 앞뒤 관계에 의해 크기가 다르게 보이도록 그리는 것인데 돌려보면 육면체가 너무 작고 주전자가 크게 나와서 원근 투영이 아닌거 같습니다,,,
 //unagi11 수정 > 원근 투영을 좀더 확실하게 나타낼수 있도록 주전자를 3개로 늘려서 비교해봤습니다.
 //멀리 있는 주전자와 가까이 있는 주전자의 크기가 같게 나타나면 직교뷰(orthoview)이고
 //원근에 따라 주전자의 크기가 달라진다면 원근 투영 (perspective view) 입니다.

#include "Header.h"

int Width, Height;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); //투상행렬 생성

	glLoadIdentity(); // 현 변환행렬을 항등행렬(I)로 초기화
	
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); // 직교뷰의 범위(좌우상하근원) 설정 < 왼쪽아래, 오른쪽 아래 viewport에 적용됨

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Draw_Scene() {

	// Quad그리기
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(2.0, 0.0, 2.0);
		glVertex3f(2.0, 0.0, -2.0);
		glVertex3f(-2.0, 0.0, -2.0);
		glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();

	// 빨간 주전자 그리기 (0,0,0)
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glutWireTeapot(1.0);
	glPopMatrix();

	// 초록 주전자 그리기 (2,0,2)
	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslatef(2, 0, 2);
	glutWireTeapot(1.0);
	glPopMatrix();

	// 파랑 주전자 그리기 (-2, 0, -2)
	glColor3f(0, 0, 1);
	glPushMatrix();
	glTranslatef(-2, 0, -2);
	glutWireTeapot(1.0);
	glPopMatrix();

	// 큐브
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(-2.5, -2.5, -0.5);
	glutSolidCube(1.0);
	glPopMatrix();

}

void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT); // 배경색으로 화면을 지운다.
	glColor3f(1.0, 1.0, 1.0);

	// 왼쪽 아래 뷰포트 (orthoview로 0,0,1 에서 0,0,0을 바라본다.)
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	Draw_Scene();
	glPopMatrix();

	// 오른쪽 아래 뷰포트 (orthoview로 1,0,0 에서 0,0,0을 바라본다.)
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	Draw_Scene();
	glPopMatrix();

	// 왼쪽 상단 뷰포트 (원근 투영으로 0,0,10에서 0,0,0 을 바라본다.)
	glViewport(0, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	if (Width < Height)
		gluPerspective(60, Height / Width, 1.0, 2000);
	else
		gluPerspective(60, Width / Height, 1.0, 2000);

	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	Draw_Scene();
	glPopMatrix();

	// 오른쪽 상단 (원근 투영으로 5,5,5에서 0,0,0을 바라본다.)
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	if (Width < Height)
		gluPerspective(60, Height / Width, 1.0, 2000);
	else
		gluPerspective(60, Width / Height, 1.0, 2000);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	Draw_Scene();
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

void MyReshape(int w, int h) {
	Width = w; Height = h;
}

int main(int argc, char** argv) {
	Width = 500; Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OPEN GL");
	Init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}



