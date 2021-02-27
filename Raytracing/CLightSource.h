#pragma once
#include "CObject.h"
#include <FreeImage.h>
#include <vector>
#include "CSphere.h"
#include "maths.h"

class CLightSource :
	public CObject
{
public:
	CLightSource();
	~CLightSource() = default;

	CLightSource(short x, short y, short z);
	void Illuminate(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility);
	void ReflectedLight(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility);
};
