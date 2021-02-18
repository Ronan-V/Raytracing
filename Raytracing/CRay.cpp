#include "CRay.h"

CRay::CRay()
{
}

CRay::~CRay()
{
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
