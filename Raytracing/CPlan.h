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

	//Ronan
	Vector3D normal;
	Vector3D pointOnPlane;

public:
	CPlan();
	CPlan(Vector3D rootbg, Vector3D roothd);
	~CPlan();
	
	Vector3D get_intersection_coordinates(CRay ray);

	//Ronan
	CPlan(const Vector3D& pointOnPlane, const Vector3D& normal, bool DifferenciationConstructeurTemporaire);
	Vector3D get_intersection_coordinates_Ronan(CRay& ray);
	bool has_intersection();


};
