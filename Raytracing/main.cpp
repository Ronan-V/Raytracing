#include <iostream>
#include "FreeImage.h"
#include "maths.h"

int main(int argc, char** argv)
{
	RGBQUAD color;
	FIBITMAP* image;
	image = FreeImage_Allocate(256, 256, 32);

	for (size_t i = 0; i < 640; i++)
	{

		for (size_t j = 0; j < 480; j++)
		{
			//if ()
			color.rgbRed = 255;
			color.rgbGreen = 255;
			color.rgbBlue = 255;

			FreeImage_SetPixelColor(image, i, j, &color);
		}
	}

	FreeImage_Save(FIF_BMP, image, "out.bmp");

	return EXIT_SUCCESS;
}