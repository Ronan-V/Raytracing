﻿#include "FreeImage.h"
#include "CCamera.h"
#include "CSphere.h"
#include "CLightSource.h"
#include <vector>
#include <utility>
#include "CPlan.h"

void main_brice() {
	FIBITMAP* image;
	short xScreen = 1000, yScreen = 1000, zScreen = 1000;
	image = FreeImage_Allocate(xScreen, yScreen, 32);

	std::vector<CSphere> mySpheres; // tableau de spheres
	CSphere mysphere0(NewVector(500, 500, 300), 50); // creation sphere1
	mySpheres.push_back(mysphere0); // ajout dans tableau

	CCamera myCamera = CCamera(NewVector(500, 500, 500), 300, 300, 50);
	//CLightSource myLightSource(0, 1000, 0);

	std::vector<CPlan> myPlans;
	//CPlan myplan0(NewVector(0, 0, 1000), NewVector(1000, 1000, 1000));
	CPlan myPlan0(NewVector(500, 300, 500), NewVector(1, 1, 0)); //Un point sur le plan et la normal au plan
	myPlans.push_back(myPlan0);

	auto* visibility = new std::vector<std::pair <RGBQUAD, Vector3D>>();
	myCamera.IradiateBrice(xScreen, yScreen, zScreen, image, mySpheres, myPlans, visibility);
}

int main(int argc, char** argv)
{

	if (true)
	{
		main_brice();
	}
	else
	{
		// -------------------------- FREEIMAGE -------------------------------

		FIBITMAP* image;


		// -------------------------- INIT SPHERES-----------------------------

		/* 4K
		short xScreen = 3840, yScreen = 2160, zScreen = 3000;
		image = FreeImage_Allocate(xScreen, yScreen, 32);
		std::vector<CSphere> mySpheres; // tableau de spheres
		CSphere mysphere0(NewVector(950, 1575, 500), 600); // creation sphere0
		CSphere mysphere1(NewVector(1900, 1050, 1500), 600); // creation sphere1
		CSphere mysphere2(NewVector(2850, 525, 2500), 600); // creation sphere2
		CSphere mysphere3(NewVector(2400, 1400, 2800), 600); // creation sphere3
		CSphere mysphere4(NewVector(800, 800, 2800), 600); // creation sphere4
		mySpheres.push_back(mysphere0); // ajout dans tableau
		mySpheres.push_back(mysphere1); // ajout dans tableau
		mySpheres.push_back(mysphere2); // ajout dans tableau
		mySpheres.push_back(mysphere3); // ajout dans tableau
		mySpheres.push_back(mysphere4); // ajout dans tableau
		*/

		//Reflected Light
		short xScreen = 1000, yScreen = 1000, zScreen = 1000;
		image = FreeImage_Allocate(xScreen, yScreen, 32);
		std::vector<CSphere> mySpheres; // tableau de spheres
		CSphere mysphere0(NewVector(500, 500, 500), 250); // creation sphere0
		mySpheres.push_back(mysphere0); // ajout dans tableau

		// -------------------------- INIT CAMERA AND LIGHTS------------------------------

		CCamera myCamera = CCamera(NewVector(0, 0, 0), 0.5, 0.35, 1);
		CLightSource myLightSource(0, 1000, 0);

		// -------------------------- INIT PAIRS ------------------------------

		auto* visibility = new std::vector<std::pair <RGBQUAD, Vector3D>>();

		// -------------------------- INIT PLANS -----------------------------

		std::vector<CPlan> myPlans;
		CPlan myplan0(NewVector(0, 0, 1000), NewVector(1000, 1000, 1000));

		// -------------------------- MAIN FUNCTIONS------------------------------

		myCamera.Iradiate(xScreen, yScreen, zScreen, image, mySpheres, visibility);
		myLightSource.Illuminate(xScreen, yScreen, zScreen, image, visibility);
		myLightSource.ReflectedLight(xScreen, yScreen, zScreen, image, visibility);
	}
}
