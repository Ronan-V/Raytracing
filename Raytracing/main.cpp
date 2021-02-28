#include "FreeImage.h"
#include "CCamera.h"
#include "CSphere.h"
#include "CLightSource.h"
#include <vector>
#include <utility>
#include "CPlan.h"
#include "CScene.h"
#include "CUtils.h"

void main_brice(std::vector<CIntersectionObject*> objects, std::vector<CLightSource> light_sources) {
	FIBITMAP* image;
	short xScreen = 1000, yScreen = 1000, zScreen = 1000;
	image = FreeImage_Allocate(xScreen, yScreen, 32);

	CLightSource myLightSource = light_sources[0];

	//CPlan* myPlan0 = new CPlan(NewVector(0, -500, 0), NewVector(0, 1, 0));

	CScene myScene;
	for (CIntersectionObject* o : objects)
	{
		myScene.add_object(o);
	}

	CCamera myCamera = CCamera(NewVector(0, 2, -10), 4, 3, 1, myScene.get_objects_array()[0]->get_position());

	auto* visibility = new std::vector<std::tuple <RGBQUAD, Vector3D, int, int>>();
	myCamera.IradiateBrice(xScreen, yScreen, zScreen, image, visibility, myScene);
	myLightSource.Illuminate(xScreen, yScreen, zScreen, image, visibility);
}

int main(int argc, char** argv)
{
	CUtils utils = CUtils("config.txt");
	if (utils.get_isRelief())
	{
		main_brice(utils.get_objects(), utils.get_light_sources());
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
		CLightSource myLightSource = utils.get_light_sources()[0];

		// -------------------------- INIT PAIRS ------------------------------

		auto* visibility = new std::vector<std::tuple <RGBQUAD, Vector3D, int, int>>();

		// -------------------------- INIT PLANS -----------------------------

		std::vector<CPlan> myPlans;
		CPlan myplan0(NewVector(0, 0, 1000), NewVector(1000, 1000, 1000));

		// -------------------------- MAIN FUNCTIONS------------------------------

		myCamera.Iradiate(xScreen, yScreen, zScreen, image, utils.get_spheres(), visibility);

		myLightSource.Illuminate(xScreen, yScreen, zScreen, image, visibility);
	}
}
