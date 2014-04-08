#ifndef HERO_H
#define HERO_H

#include "glut.h"
#include "Animation.h"

class Hero
{
private:
	Animation HeroAnimation;
	GLfloat x, y;
	GLfloat Width;
	GLfloat Height;
	GLfloat SpeedX, SpeedY, MaxSpeed;
	bool Mirror;
	void Init();
public:
	Hero();
	Hero(GLfloat ax, GLfloat ay);
	~Hero();
	void SetX(GLfloat ax);
	void SetY(GLfloat ay);
	GLfloat GetX();
	GLfloat GetY();
	void Draw();
	void MoveLeft();
	void MoveRight();
	void ChangeSpeed(GLfloat AddValue);
	void MakeStep();
};

#endif HERO_H