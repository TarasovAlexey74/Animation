#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <fstream>
#include <Windows.h>
using namespace std;

class BmpImage
{
private:
	unsigned char *Image;
	unsigned int ImageWidth, ImageHeight;
public:
	BmpImage();
	BmpImage(const char *ImageFileName);
	~BmpImage();
	void LoadImage(const char *ImageFileName);
	const char* getImage();
	unsigned int getImageWidth();
	unsigned int getImageHeight();
};

#endif IMAGELOADER_H