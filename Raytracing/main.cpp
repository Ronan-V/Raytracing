#include <iostream>
#include "FreeImage.h"
#include "CScene.h"
#include "CRay.h"
#include "CCamera.h"
#include "CSphere.h"

int main(int argc, char** argv)
{
	int width = 640;
	int length = 480;

	RGBQUAD color;
	FIBITMAP* image = FreeImage_Allocate(width, length, 32);

	CCamera camera = CCamera(4, 3, 1);

	CScene myScene;
	CSphere mySphere = CSphere(NewVector(0, 0, 3), 0.5);

	for (size_t i = 0; i < 640; i++)
	{
		for (size_t j = 0; j < 480; j++)
		{
			CRay ray = CRay(camera.get_position(), camera.UnitVectorCalculation(i, j, width, length));

			// Quand la ray a une intersection avec notre objet (pour le moment sphere)
			if (mySphere.SphereIntersectionBool(ray))
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
