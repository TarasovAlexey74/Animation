#include "stdafx.h"
#include "Hero.h"

void Hero::Init()
{
	Width = 360.0f;
	Height = 720.0f;
	SpeedX = 0.0f;
	SpeedY = 0.0f;
	MaxSpeed = 10.0f;
	Mirror = false;
	HeroAnimation.SetDelay(1000);
	HeroAnimation.JumpToFrame(4);
	HeroAnimation.Pause();
}

Hero::Hero()
{
	Init();
}

Hero::Hero(GLfloat ax, GLfloat ay)
{
	SetX(ax);
	SetY(ay);
	Init();
}

Hero::~Hero()
{

}

void Hero::SetX(GLfloat ax)
{
	x = ax;
}

void Hero::SetY(GLfloat ay)
{
	y = ay;
}

GLfloat Hero::GetX()
{
	return x;
}

GLfloat Hero::GetY()
{
	return y;
}

void Hero::Draw()
{
	HeroAnimation.Draw(x, y, x + Width, y + Height, Mirror);
}

void Hero::MoveLeft()
{
	SpeedX -= 0.5f;
}

void Hero::MoveRight()
{
	SpeedX += 0.5f;
}

void Hero::ChangeSpeed(GLfloat AddValue)
{
	SpeedX += AddValue;
}

void Hero::MakeStep()
{
	if (SpeedX != 0)
	{
		if (SpeedX < 0) Mirror = true;
		else Mirror = false;
		HeroAnimation.Resume();
		x += SpeedX;
	}
}