#pragma once
#include "CIntersectionObject.h"
#include <iostream>

class CPlan :
	public CIntersectionObject
{
private:
	Vector3D normal;
	Vector3D pointOnPlane;

public:
	CPlan() = default;
	~CPlan() = default;

	CPlan(const Vector3D& pointOnPlane, const Vector3D& normal);

	Vector3D get_intersection_coordinates(CRay ray);
};
