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

CPlan::CPlan(const Vector3D& pointOnPlane, const Vector3D& normal, bool DifferenciationConstructeurTemporaire)
{
	this->normal = Normalize(normal);
	this->pointOnPlane = pointOnPlane;
}

Vector3D CPlan::get_intersection_coordinates_Ronan(CRay& ray)
{
	Vector3D rayDirection = ray.GetDirection();
	Vector3D rayOrigin = ray.get_position();

	float tmp = ScalarProduct(normal, rayDirection);

	if (tmp == 0)
	{
		this->hasIntersection = false;
		return NewVector(0, 0, 0);
	}
	float mabite = ScalarProduct(normal, rayOrigin - pointOnPlane);
	float t = (-(ScalarProduct(normal, rayOrigin - pointOnPlane))) / tmp;

	if (t < 0)
	{
		this->hasIntersection = false;
		return NewVector(0, 0, 0);
	}

	this->hasIntersection = true;
	return rayOrigin + (t * rayDirection);
}

bool CPlan::has_intersection()
{
	return this->hasIntersection;
}
