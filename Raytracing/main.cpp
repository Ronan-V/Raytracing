#include "FreeImage.h"
#include "CCamera.h"
#include "CSphere.h"
#include "CLightSource.h"
#include <vector>
#include <utility>
#include "CPlan.h"
#include "CScene.h"

void main_brice() {
	FIBITMAP* image;
	short xScreen = 1000, yScreen = 1000, zScreen = 1000;
	image = FreeImage_Allocate(xScreen, yScreen, 32);

	std::vector<CSphere> mySpheres; // tableau de spheres
	//CSphere mysphere0(NewVector(0, 0, 10), 3); // creation sphere1
	CSphere* mySphere0 = new CSphere(NewVector(0, 0, 10), 3);
	//mySpheres.push_back(mysphere0); // ajout dans tableau

	CCamera myCamera = CCamera(NewVector(0, 2, -10), 4, 3, 1, mySphere0->get_position());
	CLightSource myLightSource(0, 1, 10);

	std::vector<CPlan> myPlans;
	//CPlan myplan0(NewVector(0, 0, 1000), NewVector(1000, 1000, 1000));
	//CPlan myPlan0(NewVector(0, -2, 0), NewVector(0, 1, 0)); //Un point sur le plan et la normal au plan
	CPlan* myPlan0 = new CPlan(NewVector(0, -5, 0), NewVector(0, 1, 0));
	CPlan* myPlan1 = new CPlan(NewVector(-5, 0, 0), NewVector(1, 0, 0));
	CPlan* myPlan2 = new CPlan(NewVector(5, 0, 0), NewVector(1, 0, 0));
	CPlan* myPlan3 = new CPlan(NewVector(0, 0, 20), NewVector(0, 0, 1));
	CPlan* myPlan4 = new CPlan(NewVector(0, 5, 0), NewVector(0, 1, 0));
	//myPlans.push_back(myPlan0);
	//myPlans.push_back(myPlan1);
	//myPlans.push_back(myPlan2);
	CScene myScene;
	myScene.add_object(mySphere0);
	/*myScene.add_object(myPlan0);
	myScene.add_object(myPlan1);
	myScene.add_object(myPlan2);
	myScene.add_object(myPlan3);
	myScene.add_object(myPlan4);*/

	auto* visibility = new std::vector<std::pair <RGBQUAD, Vector3D>>();
	myCamera.IradiateBrice(xScreen, yScreen, zScreen, image, mySpheres, myPlans, visibility, myScene);
	myLightSource.Illuminate(xScreen, yScreen, zScreen, image, visibility);
	myLightSource.ReflectedLight(xScreen, yScreen, zScreen, image, visibility);
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

		CCamera myCamera = CCamera(NewVector(0, 0, 0), 0.5, 0.35, 1, mysphere0.get_position());
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
