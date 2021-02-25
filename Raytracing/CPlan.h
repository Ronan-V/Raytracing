#pragma once
#include "CObject.h"
#include "CRay.h"
#include <iostream>

class CPlan :
	public CObject
{
private:
	Vector3D rootbg;
	Vector3D roothd;

public:
	CPlan();
	CPlan(Vector3D rootbg, Vector3D roothd);
	~CPlan();
	
	Vector3D get_intersection_coordinates(CRay ray);

};
