#pragma once
#include "CIntersectionObject.h"
#include <iostream>

class CPlan :
	public CIntersectionObject
{
private:
	Vector3D rootbg;
	Vector3D roothd;

	//Ronan
	Vector3D normal;
	Vector3D pointOnPlane;

public:
	CPlan() = default;
	~CPlan() = default;

	CPlan(Vector3D rootbg, Vector3D roothd);

	Vector3D get_intersection_coordinates(CRay ray);

	//Ronan
	CPlan(const Vector3D& pointOnPlane, const Vector3D& normal, bool DifferenciationConstructeurTemporaire);
	Vector3D get_intersection_coordinates_Ronan(CRay& ray);
	bool has_intersection();


};
