#include <iostream>
#include "FreeImage.h"
#include "CScene.h"
#include "CRay.h"
#include "CCamera.h"
#include "CSphere.h"
#include "CLightSource.h"
#include <vector>

/*
int main(int argc, char** argv)
{
	int width = 640;
	int length = 480;

	RGBQUAD color;
	FIBITMAP* image = FreeImage_Allocate(width, length, 32);

	CCamera camera = CCamera(NewVector(0, 0, 0), 0.5, 0.35, 1);

	CScene myScene;
	CSphere mySphere = CSphere(NewVector(0, 0, 10), 20);

	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			CRay ray = CRay(camera.get_position(), NormalizedVector(camera.UnitVectorCalculation(i, j, width, length)));
			//std::cout << camera.UnitVectorCalculation(i, j, width, length).x;
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
}*/

int main(int argc, char** argv)
{
	// -------------------------- FREEIMAGE -------------------------------
	FIBITMAP* image;
	short xScreen = 1000, yScreen = 1000;
	image = FreeImage_Allocate(xScreen, yScreen, 32);

	// -------------------------- INIT SPHERES-----------------------------

	std::vector<CSphere> mySpheres; // tableau de spheres
	CSphere mysphere0(NewVector(2, 2, 0), 200); // creation sphere1
	mySpheres.push_back(mysphere0); // ajout dans tableau
	/*
	CSphere mysphere1(NewVector(200, 800, 0), 200); // creation sphere2
	CSphere mysphere2(NewVector(800, 200, 0), 200); // creation sphere3
	CSphere mysphere3(NewVector(800, 800, 0), 200); // creation sphere4
	mySpheres.push_back(mysphere1); // ajout dans tableau
	mySpheres.push_back(mysphere2); // ajout dans tableau
	mySpheres.push_back(mysphere3); // ajout dans tableau
	*/
	// -------------------------- INIT CAMERA AND LIGHTS------------------------------

	CCamera myCamera = CCamera(NewVector(0, 0, 0), 0.5, 0.35, 1);
	CLightSource myLightSource;

	// -------------------------- INIT PAIRS ------------------------------

	std::vector<std::pair <RGBQUAD, Vector3D>>* visibility = new std::vector<std::pair <RGBQUAD, Vector3D>>();

	// -------------------------- MAIN FUNCTIONS------------------------------
	myCamera.IradiateBrice(xScreen, yScreen, image, mySpheres, visibility, myCamera);
	//myLightSource.Illuminate(xScreen, yScreen, image, visibility);

	// -------------------------- MAIN FUNCTIONS------------------------------

	myCamera.Iradiate(xScreen, yScreen, image, mySpheres, visibility);

	return EXIT_SUCCESS;
}
