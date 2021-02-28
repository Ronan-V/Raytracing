#include "CLightSource.h"

CLightSource::CLightSource() : CObject(NULL_VECTOR) {
}

CLightSource::CLightSource(short x, short y, short z) : CObject(NewVector(x, y, z))
{
}

CLightSource::CLightSource(Vector3D position) : CObject(position)
{
}

void CLightSource::Illuminate(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::tuple <RGBQUAD, Vector3D, int, int>>* visibility)
{
	RGBQUAD colorGetter;
	RGBQUAD colorSetter;
	float factor = sqrt(zScreen * zScreen + xScreen * xScreen);
	factor /= 255;
	for (std::tuple <RGBQUAD, Vector3D, int, int> eachTuple : *visibility)
	{

		//std::cout << eachTuple.second.x << " " << eachTuple.second.y << " " << eachTuple.second.z << " " << (int)eachTuple.first.rgbRed << " " << (int)eachTuple.first.rgbGreen << " " << (int)eachTuple.first.rgbBlue << std::endl;
		int luminosity = DistanceVectors(this->position, std::get<1>(eachTuple));
		//std::cout << luminosity << std::endl;
		//std::cout << position.x << " " << position.y << " " << position.z << " " << std::endl;

		int newFactor;
		newFactor = luminosity / factor;

		if (newFactor > 255) { newFactor = 255; }
		else if (newFactor < 0) { newFactor = 0; }

		//std::cout << newFactor << std::endl;
		if (luminosity > 255) { luminosity = 255; }
		else if (luminosity < 0) { luminosity = 0; }

		colorGetter.rgbRed = std::get<0>(eachTuple).rgbRed;
		colorGetter.rgbGreen = std::get<0>(eachTuple).rgbGreen;
		colorGetter.rgbBlue = std::get<0>(eachTuple).rgbBlue;

		int newRed, newGreen, newBlue;
		newRed = colorGetter.rgbRed - newFactor;
		newGreen = colorGetter.rgbGreen - newFactor;
		newBlue = colorGetter.rgbBlue - newFactor;

		if (newRed < 0) { newRed = 0; };
		if (newGreen < 0) { newGreen = 0; };
		if (newBlue < 0) { newBlue = 0; };

		colorSetter.rgbRed = newRed;
		colorSetter.rgbGreen = newGreen;
		colorSetter.rgbBlue = newBlue;


		FreeImage_SetPixelColor(image, std::get<2>(eachTuple), std::get<3>(eachTuple), &colorSetter);
	}
	FreeImage_Save(FIF_BMP, image, "3d.bmp");
}

void CLightSource::ReflectedLight(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::tuple <RGBQUAD, Vector3D, int, int>>* visibility)
{
	RGBQUAD colorSetter;

	for (long eachTuple = 0; eachTuple < visibility->size(); eachTuple++)
	{
		Vector3D lightVector = std::get<1>(visibility->at(eachTuple)) - this->position;
		Vector3D NormalVector = lightVector * NewVector(0, lightVector.y, 0);
		Vector3D ReflectedLight = ReflectedRay(lightVector, NormalVector);
		//std::cout << " Coordonnees : ( " << visibility->at(eachTuple).second.x<< " ; " << visibility->at(eachTuple).second.y << " ; " << (int)visibility->at(eachTuple).second.z << " )                        Reflected Ray : ( " << ReflectedLight.x << " ; " << ReflectedLight.y << " ; " << (int)ReflectedLight.z << ")" << std::endl;

		 // BLOC A REMPLACER PAR "SI INTERSECTION AU PLAN ECRAN (xScreen, yScreen) par rayon ReflectedLight" alors --les lignes dans le if--

		/*while (visibility->at(eachTuple).second.z + ReflectedLight.z > 0)
		{
			ReflectedLight.x = ReflectedLight.x - 1;
			ReflectedLight.y = ReflectedLight.y - 1;
			ReflectedLight.z = ReflectedLight.z - 1;
		}
		if ((0 < visibility->at(eachTuple).second.x + ReflectedLight.x < xScreen) and ( 0 < visibility->at(eachTuple).second.y + ReflectedLight.y < yScreen))
		{
			colorSetter.rgbRed = 255;
			colorSetter.rgbGreen = 255;
			colorSetter.rgbBlue = 255;
			FreeImage_SetPixelColor(image, ReflectedLight.x, ReflectedLight.y, &colorSetter);
		}*/
	}
	FreeImage_Save(FIF_BMP, image, "3dRef.bmp");
}
