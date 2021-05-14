 //������ ���� ������ �̿��Ͽ� ����ü�� �������� �յ� ���迡 ���� ũ�Ⱑ �ٸ��� ���̵��� �׸��� ���ε� �������� ����ü�� �ʹ� �۰� �����ڰ� ũ�� ���ͼ� ���� ������ �ƴѰ� �����ϴ�,,,
 //unagi11 ���� > ���� ������ ���� Ȯ���ϰ� ��Ÿ���� �ֵ��� �����ڸ� 3���� �÷��� ���غý��ϴ�.
 //�ָ� �ִ� �����ڿ� ������ �ִ� �������� ũ�Ⱑ ���� ��Ÿ���� ������(orthoview)�̰�
 //���ٿ� ���� �������� ũ�Ⱑ �޶����ٸ� ���� ���� (perspective view) �Դϴ�.

#include "Header.h"

int Width, Height;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); //������� ����

	glLoadIdentity(); // �� ��ȯ����� �׵����(I)�� �ʱ�ȭ
	
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); // �������� ����(�¿���ϱٿ�) ���� < ���ʾƷ�, ������ �Ʒ� viewport�� �����

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Draw_Scene() {

	// Quad�׸���
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

	// ���� ������ �׸��� (0,0,0)
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glutWireTeapot(1.0);
	glPopMatrix();

	// �ʷ� ������ �׸��� (2,0,2)
	glColor3f(0, 1, 0);
	glPushMatrix();
	glTranslatef(2, 0, 2);
	glutWireTeapot(1.0);
	glPopMatrix();

	// �Ķ� ������ �׸��� (-2, 0, -2)
	glColor3f(0, 0, 1);
	glPushMatrix();
	glTranslatef(-2, 0, -2);
	glutWireTeapot(1.0);
	glPopMatrix();

	// ť��
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(-2.5, -2.5, -0.5);
	glutSolidCube(1.0);
	glPopMatrix();

}

void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT); // �������� ȭ���� �����.
	glColor3f(1.0, 1.0, 1.0);

	// ���� �Ʒ� ����Ʈ (orthoview�� 0,0,1 ���� 0,0,0�� �ٶ󺻴�.)
	glViewport(0, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	Draw_Scene();
	glPopMatrix();

	// ������ �Ʒ� ����Ʈ (orthoview�� 1,0,0 ���� 0,0,0�� �ٶ󺻴�.)
	glViewport(Width / 2, 0, Width / 2, Height / 2);
	glPushMatrix();
	gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	Draw_Scene();
	glPopMatrix();

	// ���� ��� ����Ʈ (���� �������� 0,0,10���� 0,0,0 �� �ٶ󺻴�.)
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

	// ������ ��� (���� �������� 5,5,5���� 0,0,0�� �ٶ󺻴�.)
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


