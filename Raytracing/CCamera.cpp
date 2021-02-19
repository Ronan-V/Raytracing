#include "CCamera.h"

Vector3D CCamera::FindTopLeftPoint()
{
	Vector3D vecDir = NewVector(0, 0, 1);
	Vector3D upVec = NewVector(0, 1, 0);
	Vector3D rightVec = NewVector(1, 0, 0);
	topLeftPos = SumVectors(SumVectors(position, (FactorizeVector(FactorizeVector(viewPlaneDist, vecDir), FactorizeVector(viewPlaneHeight / 2, upVec)))), FactorizeVector(viewPlaneWidth / 2, rightVec));
}

CCamera::CCamera(float viewPlaneWidth, float viewPlaneHeight, float viewPlaneDist)
{
	this->viewPlaneWidth = viewPlaneWidth;
	this->viewPlaneHeight = viewPlaneHeight;
	this->viewPlaneDist = viewPlaneDist;

	FindTopLeftPoint();
}

CCamera::~CCamera()
{
}
