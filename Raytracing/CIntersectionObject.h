#pragma once
#include "CObject.h"
#include "CRay.h"

class CIntersectionObject
	: public CObject
{
public:
	CIntersectionObject() = default;
	~CIntersectionObject() = default;
	CIntersectionObject(Vector3D position);

	virtual Vector3D get_intersection_coordinates(CRay ray) = 0;
};
