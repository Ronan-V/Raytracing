#include "CLightSource.h"
#include "FreeImage.h"
#include <vector>
#include "CSphere.h"

CLightSource::CLightSource()
{
	this->position = NewVector(0,0,0);
}

CLightSource::CLightSource(short x, short y, short z)
{
	this->position = NewVector(x, y, z);
}

CLightSource::~CLightSource()
{
}

void CLightSource::Illuminate(short xScreen, short yScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility)
{
	RGBQUAD colorGetter;
	RGBQUAD colorSetter;
	bool interOK; // bool intersection

	for (size_t i = 0; i < xScreen; i++)
	{
		for (size_t j = 0; j < yScreen; j++)
		{
			for (short eachTuple = 0; eachTuple < visibility->size(); eachTuple++)
			{
				int luminosity = Distance(this->position, visibility->at(eachTuple).second);

				colorGetter.rgbRed = visibility->at(eachTuple).first.rgbRed;
				colorGetter.rgbGreen = visibility->at(eachTuple).first.rgbGreen;
				colorGetter.rgbBlue = visibility->at(eachTuple).first.rgbBlue;

				colorSetter.rgbRed = colorGetter.rgbRed - luminosity;
				colorSetter.rgbGreen = colorGetter.rgbGreen - luminosity;
				colorSetter.rgbBlue = colorGetter.rgbBlue - luminosity;

				FreeImage_SetPixelColor(image, i, j, &colorSetter);
			}
		}
	}
	FreeImage_Save(FIF_BMP, image, "out.bmp");
}

float CLightSource::Distance(Vector3D Light, Vector3D Intersection)
{

}
