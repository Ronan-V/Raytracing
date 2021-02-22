#pragma once
#include "CScene.h"

class CCamera :
	public CScene
{
private:
	Vector3D position;
	float viewplaneWidth;
	float viewplaneHeight;
	float viewplaneDist;

	Vector3D vecDir = NewVector(0, 0, 1);
	Vector3D upVec = NewVector(0, 1, 0);
	Vector3D rightVec = NewVector(1, 0, 0);

	float topLeftPos;

	Vector3D FindTopLeftPoint();
	Vector3D UnitVectorCalculation();

public:
	CCamera(float viewPlaneWidth, float viewPlaneHeight, float viewPlaneDist);
	~CCamera();
};

