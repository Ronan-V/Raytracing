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

	Vector3D SphereIntersection(CRay ray);
};

