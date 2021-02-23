#include "CCamera.h"

CCamera::CCamera()
{
}

CCamera::~CCamera()
{
}

void CCamera::Iradiate(short xScreen, short yScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<std::pair <RGBQUAD, Vector3D>> *visibility)
{
	RGBQUAD colorSetter;
	RGBQUAD colorGetter;
	bool interOK; // bool intersection

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
					visibility->push_back(std::pair <RGBQUAD, Vector3D>(colorSetter, Intersec));
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