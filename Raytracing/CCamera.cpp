﻿#include "CCamera.h"

Vector3D CCamera::calculate_normalised_unit_vector(float x, float y, float xRes, float yRes)
{
	float xIndent = viewplaneWidth / xRes;
	float yIndent = viewplaneHeight / yRes;

	return Normalize((this->topLeftPos + (x * xIndent * rightVec) - (y * yIndent * upVec)) - position);
}

CCamera::CCamera(Vector3D position, float viewplaneWidth, float viewplaneHeight, float viewplaneDist) : CObject(position)
{
	this->viewplaneWidth = viewplaneWidth;
	this->viewplaneHeight = viewplaneHeight;
	this->viewplaneDist = viewplaneDist;
	this->topLeftPos = this->position + ((viewplaneDist * vecDir) + ((viewplaneHeight / 2) * upVec)) - ((viewplaneWidth / 2) * rightVec);
}

void CCamera::Iradiate(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility) //CCamera camera
{
	RGBQUAD colorSetter;

	for (size_t i = 0; i < xScreen; i++)
	{
		for (size_t j = 0; j < yScreen; j++)
		{
			Vector3D myOrigin = NewVector(i, j, 0);
			Vector3D myDirection = NewVector(0, 0, zScreen);
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
					colorSetter.rgbGreen = 0;
					colorSetter.rgbBlue = 255;
					visibility->push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, intersection));
					FreeImage_SetPixelColor(image, i, j, &colorSetter);
					break;
				}
			}
		}
	}
	std::cout << "nombre de couples pixel:vecteur : " << visibility->size() << std::endl << std::endl;
	FreeImage_Save(FIF_BMP, image, "2d.bmp");
}

/// <summary>
/// Méthode de brice
/// </summary>
/// <param name="xScreen"></param>
/// <param name="yScreen"></param>
/// <param name="zScreen"></param>
/// <param name="image"></param>
/// <param name="mySpheres"></param>
/// <param name="visibility"></param>
/// <param name="camera"></param>
void CCamera::IradiateBrice(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<CPlan> myPlans, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility) //CCamera camera
{
	RGBQUAD colorSetter;
	std::cout << myPlans.size();

	for (size_t i = 0; i < xScreen; i++)
	{
		for (size_t j = 0; j < yScreen; j++)
		{
			CRay myRay = CRay(this->position, calculate_normalised_unit_vector(xScreen - i, yScreen - j, (float)xScreen, (float)yScreen));
			colorSetter.rgbRed = 0;
			colorSetter.rgbGreen = 0;
			colorSetter.rgbBlue = 0;

			for (CPlan plan : myPlans)
			{
				Vector3D intersection = plan.get_intersection_coordinates(myRay);
				if (plan.has_intersection())
				{
					colorSetter.rgbRed = 13;
					colorSetter.rgbGreen = 179;
					colorSetter.rgbBlue = 93;
					visibility->push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, intersection));
					FreeImage_SetPixelColor(image, i, j, &colorSetter);
				}
			}

			for (CSphere sphere : mySpheres)
			{
				Vector3D intersection = sphere.get_intersection_coordinates(myRay);
				if (sphere.has_intersection(myRay))
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
	FreeImage_Save(FIF_BMP, image, "out_brice.bmp");
}
