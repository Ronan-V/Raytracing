#include "CRay.h"

CRay::CRay()
{
}

CRay::~CRay()
{
}

CRay::CRay(Vector3D origin, Vector3D direction)
{
	this->origin = origin;
	this->direction = direction;
}

bool CRay::hasIntersection()
{

	return false;
}

Vector3D CRay::GetOrigin()
{
	return origin;
}

Vector3D CRay::GetDirection()
{
	return direction;
}
