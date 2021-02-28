﻿#include "CCamera.h"

Vector3D CCamera::calculate_normalised_unit_vector(float x, float y, float xRes, float yRes)
{
	float xIndent = viewplaneWidth / xRes;
	float yIndent = viewplaneHeight / yRes;

	return Normalize((this->topLeftPos + (x * xIndent * rightVec) - (y * yIndent * upVec)) - position);
}

CCamera::CCamera(Vector3D position, float viewplaneWidth, float viewplaneHeight, float viewplaneDist, Vector3D lookPosition) : CObject(position)
{
	this->viewplaneWidth = viewplaneWidth;
	this->viewplaneHeight = viewplaneHeight;
	this->viewplaneDist = viewplaneDist;
	this->vecDir = Normalize(lookPosition - position);
	this->rightVec = upVec * vecDir;
	this->upVec = vecDir * rightVec;
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
void CCamera::IradiateBrice(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<CPlan> myPlans, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility, CScene& scene) //CCamera camera
{
	RGBQUAD colorSetter;
	int colorVariable = 0;
	int red = 0;
	int green = 0;
	int blue = 0;
	float intersectDist;
	float rayDist;

	for (size_t i = 0; i < xScreen; i++)
	{
		for (size_t j = 0; j < yScreen; j++)
		{
			intersectDist = zScreen + 1;
			rayDist = 0;
			CRay myRay = CRay(this->position, calculate_normalised_unit_vector(i, yScreen - j, (float)xScreen, (float)yScreen));
			colorSetter.rgbRed = 0;
			colorSetter.rgbGreen = 0;
			colorSetter.rgbBlue = 0;

			/*for (CPlan plan : myPlans)
			{
				test++;
				Vector3D intersection = plan.get_intersection_coordinates(myRay);
				rayDist = DistanceVectors(myRay.get_position(), intersection);
				if (plan.has_intersection())
				{
					/*if (rayDist < intersectDist)
					{
						intersectDist = rayDist;
						//Materiaux : Dire que l'objet intersecté est cet objet
					}
					else
					{
						break;
					}
					switch (test) {
					case 1:
						red = 178;
						green = 20;
						blue = 31;
						break;
					case 2:
						red = 27;
						green = 120;
						blue = 131;
						break;
					default:
						red = 13;
						green = 179;
						blue = 93;
						break;
					}
					colorSetter.rgbRed = red;
					colorSetter.rgbGreen = green;
					colorSetter.rgbBlue = blue;

					visibility->push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, intersection));
					FreeImage_SetPixelColor(image, i, j, &colorSetter);
					//break;
				}
			}
			test = 0;

			for (CSphere sphere : mySpheres)
			{
				Vector3D intersection = sphere.get_intersection_coordinates(myRay);
				rayDist = DistanceVectors(myRay.get_position(), intersection);
				if (sphere.has_intersection(myRay))
				{
					/*if (rayDist < intersectDist)
					{
						intersectDist = rayDist;
						//Materiaux : Dire que l'objet intersecté est cet objet
					}
					else
					{
						break;
					}
					colorSetter.rgbRed = 255;
					colorSetter.rgbGreen = 255;
					colorSetter.rgbBlue = 255;
					visibility->push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, intersection));
					FreeImage_SetPixelColor(image, i, j, &colorSetter);
					//break;
				}
			}*/

			std::vector<CIntersectionObject*> objectsArray = scene.get_objects_array();
			for (CIntersectionObject* object : objectsArray)
			{
				colorVariable++;
				Vector3D intersection = object->get_intersection_coordinates(myRay);
				rayDist = DistanceVectors(myRay.get_position(), intersection);
				if (object->has_intersection(myRay))
				{
					if (rayDist < intersectDist)
					{
						intersectDist = rayDist;
						//Materiaux : Dire que l'objet intersecté est cet objet

						switch (colorVariable) {
						case 1:
							red = 178;
							green = 20;
							blue = 31;
							break;
						case 2:
							red = 27;
							green = 120;
							blue = 131;
							break;
						case 3:
							red = 57;
							green = 50;
							blue = 31;
							break;
						case 4:
							red = 200;
							green = 120;
							blue = 11;
							break;
						case 5:
							red = 1;
							green = 200;
							blue = 90;
							break;
						default:
							red = 70;
							green = 70;
							blue = 70;
							break;
						}
						colorSetter.rgbRed = red;
						colorSetter.rgbGreen = green;
						colorSetter.rgbBlue = blue;
						visibility->push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, intersection));
						FreeImage_SetPixelColor(image, i, j, &colorSetter);
					}
				}
			}
			colorVariable = 0;
		}
	}
	std::cout << "nombre de couples pixel:vecteur : " << visibility->size() << std::endl << std::endl;
	FreeImage_Save(FIF_BMP, image, "out_brice.bmp");
}
