#include "stdafx.h"
#include "Animation.h"

Animation::Animation()
{
	CurrentFrame = 0;
	FramesCount = 5;
	Paused = true;
	Delay = 1;
	LastTime = 0;

	Frames.push_back(0);
	Frames.push_back(1);
	Frames.push_back(0);
	Frames.push_back(2);
	Frames.push_back(3);
}

Animation::~Animation()
{

}

void Animation::Pause()
{
	Paused = true;
}

void Animation::Resume()
{
	Paused = false;
}

void Animation::Update()
{
	if ((clock() - LastTime) > Delay)
	{
		CurrentFrame = (CurrentFrame + 1) % (FramesCount - 1);
		LastTime = clock();
	}
}

void Animation::SetDelay(unsigned int aDelay)
{
	Delay = aDelay;
}

void Animation::JumpToFrame(unsigned char Frame)
{
	CurrentFrame = Frame;
}

void Animation::Draw(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, bool Mirror)
{
	if (!Paused) Update();
	TextureManager::DrawTextureSection(x0, y0, x1, y1, Frames[CurrentFrame], Mirror);
}