#pragma once
#include "CScene.h"

class CCamera :
	public CScene
{
private:
	Vector3D position;
	float viewPlaneWidth;
	float viewPlaneHeight;
	float viewPlaneDist;

	float topLeftPos;

	Vector3D FindTopLeftPoint();

public:
	CCamera(float viewPlaneWidth, float viewPlaneHeight, float viewPlaneDist);
	~CCamera();
};

