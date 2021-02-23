#pragma once
#include "CObject.h"
#include <FreeImage.h>
#include <vector>
#include "CSphere.h"
class CCamera :
	public CObject
{
private:
	float viewplaneWidth;
	float viewplaneHeight;
	float viewplaneDist;

	Vector3D vecDir = NewVector(0, 0, 1);
	Vector3D upVec = NewVector(0, 1, 0);
	Vector3D rightVec = NewVector(1, 0, 0);

	Vector3D topLeftPos;


	Vector3D FindTopLeftPoint();
public:
	CCamera();
	Vector3D UnitVectorCalculation(float x, float y, float xRes, float yRes);
	CCamera(Vector3D position, float viewplaneWidth, float viewplaneHeight, float viewplaneDist);
	~CCamera();
	void Iradiate(short xScreen, short yScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<std::pair <RGBQUAD, Vector3D>> visibility);
};
