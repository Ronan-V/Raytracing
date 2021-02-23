#include "CCamera.h"
#include <FreeImage.h>
#include <vector>
#include "CSphere.h"

CCamera::CCamera() {
}

Vector3D CCamera::get_top_left_point()
{
	return position + ((viewplaneDist * vecDir) + (viewplaneHeight / 2) * upVec) - ((viewplaneWidth / 2) * rightVec);
}

Vector3D CCamera::UnitVectorCalculation(float x, float y, float xRes = 640, float yRes = 480)
{
	float xIndent = viewplaneWidth / xRes;
	float yIndent = viewplaneHeight / yRes;

	return (get_top_left_point() + x * xIndent * rightVec - y * yIndent * upVec) - position;
}

CCamera::CCamera(Vector3D position, float viewplaneWidth, float viewplaneHeight, float viewplaneDist) : CObject(position)
{
	this->viewplaneWidth = viewplaneWidth;
	this->viewplaneHeight = viewplaneHeight;
	this->viewplaneDist = viewplaneDist;
	this->topLeftPos = get_top_left_point();
}

CCamera::~CCamera()
{
}

void CCamera::Iradiate(short xScreen, short yScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility)
{
	RGBQUAD colorSetter;
	RGBQUAD colorGetter;

	for (size_t i = 0; i < xScreen; i++)
	{

		for (size_t j = 0; j < yScreen; j++)
		{
			Vector3D myOrigin = NewVector(i, j, 0);
			Vector3D myDirection = NewVector(i, j, 0);
			CRay myRayon(myOrigin, myDirection);
			colorSetter.rgbRed = 0;
			colorSetter.rgbGreen = 0;
			colorSetter.rgbBlue = 0;

			for (CSphere sphere : mySpheres)
			{
				Vector3D intersection = sphere.get_intersection_coordinates(myRayon);
				if (sphere.has_intersection(myRayon))
				{
					colorSetter.rgbRed = 255;
					colorSetter.rgbGreen = 255;
					colorSetter.rgbBlue = 255;
					visibility->push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, intersection));
					FreeImage_SetPixelColor(image, i, j, &colorSetter);
					break;
				}
			}
		}
	}
	std::cout << "nombre de couples pixel:vecteur : " << visibility->size() << std::endl << std::endl;
	//std::cout << "valeur du pixel rouge du couple 40 000 : " << visibility[40000].first.rgbRed << std::endl << std::endl;
	FreeImage_Save(FIF_BMP, image, "out.bmp");
}

void CCamera::IradiateBrice(short xScreen, short yScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility, CCamera camera)
{
	RGBQUAD colorSetter;

	for (size_t i = 0; i < xScreen; i++)
	{
		for (size_t j = 0; j < yScreen; j++)
		{
			CRay myRayon = CRay(camera.get_position(), NormalizedVector(camera.UnitVectorCalculation(i, j, xScreen, yScreen)));
			colorSetter.rgbRed = 0;
			colorSetter.rgbGreen = 0;
			colorSetter.rgbBlue = 0;

			for (CSphere sphere : mySpheres)
			{
				Vector3D intersection = sphere.get_intersection_coordinates(myRayon);
				if (sphere.has_intersection(myRayon))
				{
					colorSetter.rgbRed = 255;
					colorSetter.rgbGreen = 255;
					colorSetter.rgbBlue = 255;
					visibility->push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, intersection));
					FreeImage_SetPixelColor(image, i, j, &colorSetter);
					break;
				}
			}
		}
	}
	std::cout << "nombre de couples pixel:vecteur : " << visibility->size() << std::endl << std::endl;
	std::cout << "valeur du pixel rouge du couple 40 000(200;200) : " << visibility->at(40000).first.rgbRed << std::endl << std::endl;
	std::cout << "valeur du pixel rouge du couple 250 000 (500;500): " << visibility->at(250000).first.rgbRed << std::endl << std::endl;
	FreeImage_Save(FIF_BMP, image, "out.bmp");
}
