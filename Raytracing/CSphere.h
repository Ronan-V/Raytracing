#pragma once
#include "CObject.h"
#include "CRay.h"
#include <iostream>

class CSphere :
	public CObject
{
private:
	float rayon;

public:
	CSphere();
	CSphere(Vector3D position, float rayon);
	~CSphere();

	Vector3D SphereIntersection(CRay ray);
	bool SphereIntersectionBool(CRay ray);
};
