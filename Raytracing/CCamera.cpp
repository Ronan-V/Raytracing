#include "CCamera.h"

Vector3D CCamera::FindTopLeftPoint()
{
	return position + ((viewplaneDist * vecDir) + (viewplaneHeight / 2) * upVec) - ((viewplaneWidth / 2) * rightVec);
}

Vector3D CCamera::UnitVectorCalculation(float x, float y, float xRes = 640, float yRes = 480)
{
	float xIndent = viewplaneWidth / xRes;
	float yIndent = viewplaneHeight / yRes;

	return (FindTopLeftPoint() + x * xIndent * rightVec - y * yIndent * upVec) - position;
}

CCamera::CCamera(Vector3D position, float viewplaneWidth, float viewplaneHeight, float viewplaneDist)
{
	this->position = position;
	this->viewplaneWidth = viewplaneWidth;
	this->viewplaneHeight = viewplaneHeight;
	this->viewplaneDist = viewplaneDist;
	this->topLeftPos = FindTopLeftPoint();
}

CCamera::~CCamera()
{
}
