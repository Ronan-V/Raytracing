#pragma once
#include "CScene.h"
#include "FreeImage.h"

class CLightSource :
	public CScene
{
private:
	Vector3D position;

public:
	CLightSource();
	~CLightSource();
	CLightSource(short x, short y, short z);

	void Illuminate(short xScreen, short yScreen, FIBITMAP* image, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility);
	float Distance(Vector3D Light, Vector3D Intersection);

};

