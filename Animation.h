#ifndef ANIMATION_H
#define ANIMATION_H

#include "glut.h"
#include <ctime>
#include <vector>
#include "TextureManager.h"
using namespace std;

class Animation
{
private:
	vector<int> Frames;
	GLubyte CurrentFrame;
	GLubyte FramesCount;
	bool Paused;
	GLuint Delay;
	clock_t LastTime;
public:
	Animation();
	~Animation();
	void Pause();
	void Resume();
	void Update();
	void SetDelay(GLuint aDelay);
	void JumpToFrame(GLubyte Frame);
	void Draw(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, bool Mirror = false);
};

#endif ANIMATION_H