#pragma once
#include "CObject.h"
#include <FreeImage.h>
#include <vector>
#include "CSphere.h"
#include "maths.h"

class CLightSource :
	public CObject
{
private:

public:
	CLightSource();
	~CLightSource();

	void Illuminate();
	CLightSource(short x, short y, short z);
	void Illuminate(short xScreen, short yScreen, short zScreen , FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility);
	float Distance(Vector3D Light, Vector3D Intersection, short xScreen);
};
