#ifndef TEXTURE_H
#define TEXTURE_H

#include "glut.h"
#include "BmpImage.h"

struct Section
{
	GLfloat uMin;
	GLfloat uMax;
	GLfloat vMin;
	GLfloat vMax;
};

class TextureManager
{
private:
	static GLuint Texture;
	static Section *TextureSection;
	GLuint TextureWidth, TextureHeight;
public:
	TextureManager();
	TextureManager(const char *FileName);
	~TextureManager();
	void LoadTexture(const char *FileName);
	void SplitTextureInSections(unsigned int NumberOfSections);
	static void DrawTextureSection(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, unsigned int SectionNumber, bool Mirror = false);
};


#endif TEXTURE_H