#include <iostream>
#include "FreeImage.h"
#include "CScene.h"

int main(int argc, char** argv)
{
	RGBQUAD color;
	FIBITMAP* image;
	image = FreeImage_Allocate(256, 256, 32);
	CScene myScene;
	//CSphere mySphere;


	for (size_t i = 0; i < 640; i++)
	{

		for (size_t j = 0; j < 480; j++)
		{
			if (true) // Quand la ray a une intersection avec notre objet (pour le moment sphere)
			{
				color.rgbRed = 255;
				color.rgbGreen = 255;
				color.rgbBlue = 255;
			}
			else
			{
				color.rgbRed = 0;
				color.rgbGreen = 0;
				color.rgbBlue = 0;
			}

			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}

	FreeImage_Save(FIF_BMP, image, "out.bmp");

	return EXIT_SUCCESS;
}