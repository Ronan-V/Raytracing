#include "CCamera.h"

Vector3D CCamera::FindTopLeftPoint()
{
	
	Vector3D topLeftPos = SoustractVectors(
							SumVectors(
								position,
								(SumVectors(
										FactorizeVector(viewplaneDist, vecDir),
										FactorizeVector(viewplaneHeight / 2, upVec)
									))), 
							FactorizeVector(viewplaneWidth / 2, rightVec));
	return topLeftPos;
}

Vector3D CCamera::UnitVectorCalculation(float x, float y, float xRes, float yRes)
{
	float xIndent, yIndent;

	xIndent = viewplaneWidth / (float)xRes;
	yIndent = viewplaneHeight / (float)yRes;

	return (FindTopLeftPoint() + rightVec * xIndent * x - upVec * yIndent * y) - position;
}

CCamera::CCamera(float viewPlaneWidth, float viewPlaneHeight, float viewPlaneDist)
{
	this->viewplaneWidth = viewPlaneWidth;
	this->viewplaneHeight = viewPlaneHeight;
	this->viewplaneDist = viewPlaneDist;

	FindTopLeftPoint();
}

CCamera::~CCamera()
{
}
