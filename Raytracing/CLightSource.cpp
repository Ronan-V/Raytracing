#include "CLightSource.h"

CLightSource::CLightSource() : CObject(NewVector(0, 0, 0)) {
}

CLightSource::CLightSource(short x, short y, short z) : CObject(NewVector(x, y, z))
{
}

void CLightSource::Illuminate(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility)
{
	RGBQUAD colorGetter;
	RGBQUAD colorSetter;
	bool interOK; // bool intersection
	float factor = sqrt(zScreen * zScreen + xScreen * xScreen);
	factor /= 255;
	for (long eachTuple = 0; eachTuple < visibility->size(); eachTuple++)
	{

		int luminosity = Distance(this->position, visibility->at(eachTuple).second, xScreen);

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

float CLightSource::Distance(Vector3D Light, Vector3D Intersection, short xScreen)
{
	return DistanceVectors(Intersection, Light);
}
