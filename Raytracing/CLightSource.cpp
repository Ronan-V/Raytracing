#include "CLightSource.h"

CLightSource::CLightSource() : CObject(NewVector(0, 0, 0)) {
}

CLightSource::CLightSource(short x, short y, short z) : CObject(NewVector(x, y, z))
{
}

CLightSource::~CLightSource()
{
}

void CLightSource::Illuminate(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility)
{
	RGBQUAD colorGetter;
	RGBQUAD colorSetter;
	bool interOK; // bool intersection
	float factor = sqrt(zScreen * zScreen + xScreen * xScreen);
	std::cout << factor << std::endl;
	factor /= 255;
	std::cout << factor << std::endl;
	for (int eachTuple = 0; eachTuple < visibility->size(); eachTuple++)
	{
		int luminosity = Distance(this->position, visibility->at(eachTuple).second, xScreen);
		colorGetter.rgbRed = visibility->at(eachTuple).first.rgbRed;
		colorGetter.rgbGreen = visibility->at(eachTuple).first.rgbGreen;
		colorGetter.rgbBlue = visibility->at(eachTuple).first.rgbBlue;
		colorSetter.rgbRed = colorGetter.rgbRed - luminosity / factor;
		colorSetter.rgbGreen = colorGetter.rgbGreen - luminosity / factor;
		colorSetter.rgbBlue = colorGetter.rgbBlue - luminosity / factor;

		if (colorSetter.rgbRed < 0)
		{
			colorSetter.rgbRed = 0;
		}
		if (colorSetter.rgbGreen < 0)
		{
			colorSetter.rgbGreen = 0;
		}
		if (colorSetter.rgbBlue < 0)
		{
			colorSetter.rgbBlue = 0;
		}

		FreeImage_SetPixelColor(image, visibility->at(eachTuple).second.x, visibility->at(eachTuple).second.y, &colorSetter);
	}
	FreeImage_Save(FIF_BMP, image, "3d.bmp");
}

float CLightSource::Distance(Vector3D Light, Vector3D Intersection, short xScreen)
{
	float distance = (DistanceVectors(Intersection, Light));
	return (int)distance;
}
