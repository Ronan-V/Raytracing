#pragma once
#include "CIntersectionObject.h"
#include <iostream>

/// <summary>
/// This class represents a Sphere
/// </summary>
class CSphere :
	public CIntersectionObject
{
private:
	float rayon;

public:
	CSphere() = default;
	~CSphere() = default;

	CSphere(Vector3D position, float rayon);

	Vector3D get_intersection_coordinates(CRay ray);
};
