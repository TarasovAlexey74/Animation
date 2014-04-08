#include "stdafx.h"
#include "glut.h"
#include "Hero.h"
#include "TextureManager.h"

TextureManager Manager;
Hero Player;
bool Keys[256];
GLubyte count = 0;

void GameLoop()
{
	if (Keys['a']) Player.ChangeSpeed(-0.5f);
	if (Keys['d']) Player.ChangeSpeed(0.5f);
	Player.MakeStep();
}

void MyInit()
{
	//glClearColor(0.7f, 0.2f, 0.35f, 1.0f);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	Player = Hero(200.0f, 200.0f);
	Manager.LoadTexture("hero.bmp");
	Manager.SplitTextureInSections(4);
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
		Player.Draw();
	glutSwapBuffers();
}

void MyReshape(int NewWidth, int NewHeight)
{
	glViewport(0, 0, NewWidth, NewHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, NewWidth, 0.0, NewHeight);
}

void MyTimer(int value)
{
	glutPostRedisplay();
	if (++count >= 2)
	{
		GameLoop();
		count = 0;
	}
	glutTimerFunc(16, MyTimer, 1);
}

void MyKeyboard(unsigned char key, int x, int y)
{
	Keys[key] = true;
}
void MyKeyboardUp(unsigned char key, int x, int y)
{
	Keys[key] = false;
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Animation");

	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutKeyboardUpFunc(MyKeyboardUp);
	glutTimerFunc(16, MyTimer, 1);

	glutMainLoop();
	return 0;
}

