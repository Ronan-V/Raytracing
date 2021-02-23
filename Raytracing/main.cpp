#include <iostream>
#include "FreeImage.h"
#include "CScene.h"
#include "CSphere.h"
#include "CCamera.h"
#include "CLightSource.h"
#include <vector>
#include <utility>


int main(int argc, char** argv)
{
	// -------------------------- FREEIMAGE -------------------------------
	FIBITMAP* image;
	short xScreen =  1000, yScreen = 1000;
	image = FreeImage_Allocate(xScreen, yScreen, 32);

	// -------------------------- INIT SPHERES-----------------------------

	std::vector<CSphere> mySpheres; // tableau de spheres
	CSphere mysphere0(NewVector(200, 200, 0) , 200); // creation sphere1
	//CSphere mysphere1(NewVector(200, 800, 0), 200); // creation sphere2
	//CSphere mysphere2(NewVector(800, 200, 0), 200); // creation sphere3
	//CSphere mysphere3(NewVector(800, 800, 0), 200); // creation sphere4
	mySpheres.push_back(mysphere0); // ajout dans tableau
	//mySpheres.push_back(mysphere1); // ajout dans tableau
	//mySpheres.push_back(mysphere2); // ajout dans tableau
	//mySpheres.push_back(mysphere3); // ajout dans tableau

	// -------------------------- INIT CAMERA AND LIGHTS------------------------------

	CCamera myCamera;
	CLightSource myLightSource;

	// -------------------------- INIT PAIRS ------------------------------

	std::vector<std::pair <RGBQUAD, Vector3D>> *visibility = new std::vector<std::pair <RGBQUAD, Vector3D>>();

	// -------------------------- MAIN FUNCTIONS------------------------------

	myCamera.Iradiate(xScreen, yScreen, image, mySpheres, visibility);
	myLightSource.Illuminate(xScreen, yScreen, image, visibility);
	

	return EXIT_SUCCESS;
}