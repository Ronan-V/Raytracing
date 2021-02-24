#include "CLightSource.h"
#include "FreeImage.h"
#include <vector>
#include "CSphere.h"

CLightSource::CLightSource() : CObject(NewVector(0, 0, 0)) {
}

CLightSource::CLightSource(short x, short y, short z) : CObject(NewVector(x, y, z))
{
}

CLightSource::~CLightSource()
{
}

void CLightSource::Illuminate(short xScreen, short yScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility)
{
	RGBQUAD colorGetter;
	RGBQUAD colorSetter;
	bool interOK; // bool intersection

	for (short eachTuple = 0; eachTuple < visibility->size(); eachTuple++)
	{
		int luminosity = Distance(this->position, visibility->at(eachTuple).second, xScreen);
		colorGetter.rgbRed = visibility->at(eachTuple).first.rgbRed;
		colorGetter.rgbGreen = visibility->at(eachTuple).first.rgbGreen;
		colorGetter.rgbBlue = visibility->at(eachTuple).first.rgbBlue;
		colorSetter.rgbRed = colorGetter.rgbRed - (40 * luminosity);
		colorSetter.rgbGreen = colorGetter.rgbGreen - (40 * luminosity);
		colorSetter.rgbBlue = colorGetter.rgbBlue - (40 * luminosity);

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
		if ((visibility->at(eachTuple).second.x == 500) and (visibility->at(eachTuple).second.y == 500))
		{
			//std::cout << "Tuple numero : " << eachTuple <<" x : " << visibility->at(eachTuple).second.x << " y : " << visibility->at(eachTuple).second.y << " z : " << visibility->at(eachTuple).second.z << std::endl;
		}
	}
	FreeImage_Save(FIF_BMP, image, "3d.bmp");
}

float CLightSource::Distance(Vector3D Light, Vector3D Intersection, short xScreen)
{
	int distance = (DistanceVectors(Intersection, Light)/xScreen)*10;

	return (int)distance;
}
