#include "CCamera.h"

Vector3D CCamera::FindTopLeftPoint()
{
	Vector3D topLeftPos = position + ((viewplaneDist * vecDir) + (viewplaneHeight / 2) * upVec) - ((viewplaneWidth / 2) * rightVec);
	return topLeftPos;
}

Vector3D CCamera::UnitVectorCalculation(float x, float y, float xRes, float yRes)
{
	float xIndent, yIndent;

	xIndent = viewplaneWidth / (float)xRes;
	yIndent = viewplaneHeight / (float)yRes;

	return (FindTopLeftPoint() + x * xIndent * rightVec - y * yIndent * upVec) - position;
}

CCamera::CCamera(float viewplaneWidth, float viewplaneHeight, float viewplaneDist)
{
	this->viewplaneWidth = viewplaneWidth;
	this->viewplaneHeight = viewplaneHeight;
	this->viewplaneDist = viewplaneDist;

	FindTopLeftPoint();
}

CCamera::~CCamera()
{
}
