#include "CCamera.h"
#include <FreeImage.h>
#include <FreeImage.h>
#include <vector>
#include "CSphere.h"

Vector3D CCamera::FindTopLeftPoint()
{
	return position + ((viewplaneDist * vecDir) + (viewplaneHeight / 2) * upVec) - ((viewplaneWidth / 2) * rightVec);
}

Vector3D CCamera::UnitVectorCalculation(float x, float y, float xRes = 640, float yRes = 480)
{
	float xIndent = viewplaneWidth / xRes;
	float yIndent = viewplaneHeight / yRes;

	return (FindTopLeftPoint() + x * xIndent * rightVec - y * yIndent * upVec) - position;
}

CCamera::CCamera(Vector3D position, float viewplaneWidth, float viewplaneHeight, float viewplaneDist)
{
	this->position = position;
	this->viewplaneWidth = viewplaneWidth;
	this->viewplaneHeight = viewplaneHeight;
	this->viewplaneDist = viewplaneDist;
	this->topLeftPos = FindTopLeftPoint();
}

CCamera::~CCamera()
{
}

void CCamera::Iradiate(short xScreen, short yScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<std::pair <RGBQUAD, Vector3D>> visibility)
{
	RGBQUAD colorSetter;
	RGBQUAD colorGetter;
	bool interOK; // bool intersection
	/*for (int nbSph = 0; nbSph < mySpheres.size(); nbSph++)
	{
		for (size_t i = 0; i < xScreen; i++)
		{
			for (size_t j = 0; j < yScreen; j++)
			{
				Vector3D myOrigin = NewVector(i, j, 0);
				Vector3D myDirection = NewVector(i, j, 0);
				CRay myRayon(myOrigin, myDirection);
				Vector3D Intersec = mySpheres[nbSph].SphereIntersection(myRayon);
				Vector3D zero = NewVector(0, 0, 0);
				interOK = IsEgual(Intersec, zero);
				if (interOK == true)
				{
					colorSetter.rgbRed = 0;
					colorSetter.rgbGreen = 0;
					colorSetter.rgbBlue = 0;
				}
				else
				{
					if (nbSph == 0)
					{
						colorSetter.rgbRed = 255;
						colorSetter.rgbGreen = 0;
						colorSetter.rgbBlue = 0;
					}
					else if (nbSph == 1)
					{
						colorSetter.rgbRed = 255;
						colorSetter.rgbGreen = 255;
						colorSetter.rgbBlue = 255;
					}
					else if (nbSph == 2)
					{
						colorSetter.rgbRed = 255;
						colorSetter.rgbGreen = 0;
						colorSetter.rgbBlue = 0;
					}
					else if (nbSph == 3)
					{
						colorSetter.rgbRed = 255;
						colorSetter.rgbGreen = 255;
						colorSetter.rgbBlue = 255;
					}
				}
				FreeImage_GetPixelColor(image, i, j, &colorGetter);
				visibility.push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, Intersec));
				if (colorSetter.rgbRed == 0 and colorSetter.rgbGreen == 0 and colorSetter.rgbBlue == 0)
				{
				}
				if (colorGetter.rgbRed == 0 and colorGetter.rgbGreen == 0 and colorGetter.rgbBlue == 0)
				{
					FreeImage_SetPixelColor(image, i, j, &colorSetter);
				}
			}
		}
	}*/


	for (size_t i = 0; i < xScreen; i++)
	{

		for (size_t j = 0; j < yScreen; j++)
		{
			Vector3D myOrigin = NewVector(i, j, 0);
			Vector3D myDirection = NewVector(i, j, 0);
			Vector3D zero = NewVector(0, 0, 0);
			CRay myRayon(myOrigin, myDirection);
			colorSetter.rgbRed = 0;
			colorSetter.rgbGreen = 0;
			colorSetter.rgbBlue = 0;
			for (size_t k = 0; k < mySpheres.size(); k++)
			{
				Vector3D Intersec = mySpheres[k].SphereIntersection(myRayon);
				if (IsEgual(Intersec, zero) == false)
				{
					colorSetter.rgbRed = 255;
					colorSetter.rgbGreen = 255;
					colorSetter.rgbBlue = 255;
					visibility.push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, Intersec));
					FreeImage_SetPixelColor(image, i, j, &colorSetter);
					break;
				}
			}
		}
	}
	std::cout << "nombre de couples pixel:vecteur : " << visibility.size() << std::endl << std::endl;
	//std::cout << "valeur du pixel rouge du couple 40 000 : " << visibility[40000].first.rgbRed << std::endl << std::endl;
	FreeImage_Save(FIF_BMP, image, "out.bmp");
}
