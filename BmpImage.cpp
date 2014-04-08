#include "stdafx.h"
#include "BmpImage.h"

BmpImage::BmpImage()
{
	Image = NULL;
	ImageWidth = 0; 
	ImageHeight = 0;
}

BmpImage::BmpImage(const char *ImageFileName)
{
	LoadImage(ImageFileName);
}

BmpImage::~BmpImage()
{
	delete[] Image;
}

void BmpImage::LoadImage(const char *ImageFileName)
{
	ifstream Reader(ImageFileName, ios::binary);
	BITMAPFILEHEADER BmpFileHeader;
	BITMAPINFO BmpInfo;

	Reader.read((char*)&BmpFileHeader, sizeof(BITMAPFILEHEADER));
	Reader.read((char*)&BmpInfo, sizeof(BITMAPINFO));
	ImageWidth = BmpInfo.bmiHeader.biWidth;
	ImageHeight = BmpInfo.bmiHeader.biHeight;

	Image = new unsigned char[ImageWidth * ImageHeight * 4];

	Reader.seekg(BmpFileHeader.bfOffBits);
	for (int i = 0; i < ImageWidth * ImageHeight * 4; i += 4)
	{
		Reader.read((char*)Image + i, sizeof(unsigned char) * 3);
		if ((Image[i] == 195) && (Image[i + 1] == 195) && (Image[i + 2] == 195)) Image[i + 3] = 0;
		else Image[i + 3] = 255;
	}
	Reader.close();
}

const char* BmpImage::getImage()
{
	return ((const char*)Image);
}

unsigned int BmpImage::getImageWidth()
{
	return ImageWidth;
}

unsigned int BmpImage::getImageHeight()
{
	return ImageHeight;
}