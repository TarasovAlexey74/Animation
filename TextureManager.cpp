#include "stdafx.h"
#include "TextureManager.h"

GLuint TextureManager::Texture;
Section* TextureManager::TextureSection;

TextureManager::TextureManager()
{
	TextureSection = NULL;
}

TextureManager::TextureManager(const char *FileName)
{
	LoadTexture(FileName);
	TextureSection = NULL;
}

TextureManager::~TextureManager()
{
	if (TextureSection != NULL)
		delete[] TextureSection;
}

void TextureManager::LoadTexture(const char *FileName)
{
	BmpImage Image(FileName);
	TextureWidth = Image.getImageWidth();
	TextureHeight = Image.getImageHeight();

	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, TextureWidth, TextureHeight, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, (const GLvoid*)Image.getImage());
}

void TextureManager::SplitTextureInSections(unsigned int NumberOfSections)
{
	TextureSection = new Section[NumberOfSections];
	for (int i = 0; i < NumberOfSections; i++)
	{
		TextureSection[i].uMin = (1.0f / NumberOfSections) * i;
		TextureSection[i].uMax = (1.0f / NumberOfSections) * (i + 1);
		TextureSection[i].vMin = 0.0f;
		TextureSection[i].vMax = 1.0f;
	}
}

void TextureManager::DrawTextureSection(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, unsigned int SectionNumber, bool Mirror)
{
	Section *SelectedSection = &TextureSection[SectionNumber];
	glBindTexture(GL_TEXTURE_2D, Texture);
	glBegin(GL_QUADS);
		if (Mirror)
		{
			glTexCoord2f(SelectedSection->uMax, SelectedSection->vMin); glVertex2f(x0, y0);
			glTexCoord2f(SelectedSection->uMin, SelectedSection->vMin); glVertex2f(x1, y0);
			glTexCoord2f(SelectedSection->uMin, SelectedSection->vMax); glVertex2f(x1, y1);
			glTexCoord2f(SelectedSection->uMax, SelectedSection->vMax); glVertex2f(x0, y1);
		}
		else
		{

			glTexCoord2f(SelectedSection->uMin, SelectedSection->vMin); glVertex2f(x0, y0);
			glTexCoord2f(SelectedSection->uMax, SelectedSection->vMin); glVertex2f(x1, y0);
			glTexCoord2f(SelectedSection->uMax, SelectedSection->vMax); glVertex2f(x1, y1);
			glTexCoord2f(SelectedSection->uMin, SelectedSection->vMax); glVertex2f(x0, y1);
		}
	glEnd();
}