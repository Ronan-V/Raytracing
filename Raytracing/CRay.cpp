#include "CRay.h"

CRay::CRay()
{
}

CRay::CRay(Vector3D position, Vector3D direction)
{
	this->position = position;
	this->direction = direction;
}

CRay::~CRay()
{
}

bool CRay::hasIntersection()
{

	return false;
}

Vector3D CRay::GetDirection()
{
	return direction;
}
