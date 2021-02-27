#include "CLightSource.h"

CLightSource::CLightSource() : CObject(NULL_VECTOR) {
}

CLightSource::CLightSource(short x, short y, short z) : CObject(NewVector(x, y, z))
{
}

void CLightSource::Illuminate(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility)
{
	RGBQUAD colorGetter;
	RGBQUAD colorSetter;
	float factor = sqrt(zScreen * zScreen + xScreen * xScreen);
	factor /= 255;
	for (long eachTuple = 0; eachTuple < visibility->size(); eachTuple++)
	{

		int luminosity = DistanceVectors(this->position, visibility->at(eachTuple).second);

		int newFactor;
		newFactor = luminosity / factor;

		if (newFactor > 255) { newFactor = 255; }
		else if (newFactor < 0) { newFactor = 0; }

		colorGetter.rgbRed = visibility->at(eachTuple).first.rgbRed;
		colorGetter.rgbGreen = visibility->at(eachTuple).first.rgbGreen;
		colorGetter.rgbBlue = visibility->at(eachTuple).first.rgbBlue;

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


		FreeImage_SetPixelColor(image, visibility->at(eachTuple).second.x, visibility->at(eachTuple).second.y, &colorSetter);
	}
	FreeImage_Save(FIF_BMP, image, "3d.bmp");
}

void CLightSource::ReflectedLight(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility)
{
	RGBQUAD colorSetter;

	for (long eachTuple = 0; eachTuple < visibility->size(); eachTuple++)
	{
		Vector3D lightVector = visibility->at(eachTuple).second - this->position;
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
