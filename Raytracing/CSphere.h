#pragma once
#include "CObjects.h"

class CSphere :
	public CObjects
{
private:
	Vector3D position;
	float rayon;

public:
	CSphere();
	~CSphere();
	CSphere(Vector3D position, float rayon);

	Vector3D SphereIntersection(CRay ray);
};

