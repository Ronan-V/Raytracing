#include <iostream>
#include "FreeImage.h"
#include "CScene.h"
#include "CRay.h"
#include "CCamera.h"
#include "CSphere.h"
#include "CLightSource.h"
#include <vector>
#include <utility>

void main_brice() {
	FIBITMAP* image;
	short xScreen = 1000, yScreen = 1000, zScreen = 1000;
	image = FreeImage_Allocate(xScreen, yScreen, 32);

	std::vector<CSphere> mySpheres; // tableau de spheres
	CSphere mysphere0(NewVector(200, 200, 150), 100); // creation sphere1
	mySpheres.push_back(mysphere0); // ajout dans tableau

	CCamera myCamera = CCamera(NewVector(200, 200, 0), 10, 10, 100);

	std::vector<std::pair <RGBQUAD, Vector3D>>* visibility = new std::vector<std::pair <RGBQUAD, Vector3D>>();
	myCamera.IradiateBrice(xScreen, yScreen, zScreen, image, mySpheres, visibility);
}

int main(int argc, char** argv)
{

	if (false)
	{
		main_brice();
	}
	else
	{
		// -------------------------- FREEIMAGE -------------------------------
		FIBITMAP* image;
		short xScreen = 1000, yScreen = 1000, zScreen = 1000;
		image = FreeImage_Allocate(xScreen, yScreen, 32);

		// -------------------------- INIT SPHERES-----------------------------

		std::vector<CSphere> mySpheres; // tableau de spheres
		CSphere mysphere0(NewVector(500, 500, 500), 100); // creation sphere1
		//CSphere mysphere1(NewVector(250, 500, 500), 100); // creation sphere2
		//CSphere mysphere2(NewVector(750, 500, 500), 100); // creation sphere3
		//CSphere mysphere3(NewVector(800, 800, 0), 200); // creation sphere4
		mySpheres.push_back(mysphere0); // ajout dans tableau
		//mySpheres.push_back(mysphere1); // ajout dans tableau
		//mySpheres.push_back(mysphere2); // ajout dans tableau
		//mySpheres.push_back(mysphere3); // ajout dans tableau
		// -------------------------- INIT CAMERA AND LIGHTS------------------------------

		CCamera myCamera = CCamera(NewVector(0, 0, 0), 0.5, 0.35, 1);
		CLightSource myLightSource(0, 1000, 0);

		// -------------------------- INIT PAIRS ------------------------------

		std::vector<std::pair <RGBQUAD, Vector3D>>* visibility = new std::vector<std::pair <RGBQUAD, Vector3D>>();


		// -------------------------- MAIN FUNCTIONS------------------------------

		myCamera.Iradiate(xScreen, yScreen, zScreen, image, mySpheres, visibility);
		myLightSource.Illuminate(xScreen, yScreen, zScreen, image, visibility);
	}
}
