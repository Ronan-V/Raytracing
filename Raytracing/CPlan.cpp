#include "CPlan.h"

CPlan::CPlan()
{
}

CPlan::CPlan(Vector3D rootbg, Vector3D roothd)
{
	this->rootbg = rootbg;
	this->roothd = roothd;
}

CPlan::~CPlan()
{
}

Vector3D CPlan::get_intersection_coordinates(CRay ray)
{
	Vector3D rayDirection = ray.GetDirection();
	Vector3D rayOrigin = ray.get_position();

	for (int pixel = rayOrigin.z; pixel <= rayDirection.z; pixel++)
	{
		if (pixel == this->rootbg.z)
			return (NewVector(rayOrigin.x, rayOrigin.y, pixel));
		else
		{
			return (NewVector(0, 0, 0));
		}
	}
}