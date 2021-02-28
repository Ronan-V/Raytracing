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
	CLightSource(Vector3D position);
	void Illuminate(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::tuple <RGBQUAD, Vector3D, int, int>>* visibility);
	void ReflectedLight(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<std::tuple <RGBQUAD, Vector3D, int, int>>* visibility);
};
