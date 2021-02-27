#include "CPlan.h"

CPlan::CPlan(const Vector3D& pointOnPlane, const Vector3D& normal)
{
	this->normal = Normalize(normal);
	this->pointOnPlane = pointOnPlane;
}

Vector3D CPlan::get_intersection_coordinates(CRay ray)
{
	Vector3D rayDirection = ray.GetDirection();
	Vector3D rayOrigin = ray.get_position();

	float tmp = ScalarProduct(normal, rayDirection);
	if (tmp != 0)
	{
		float t = (-(ScalarProduct(normal, rayOrigin - pointOnPlane))) / tmp;

		if (t >= 0)
		{
			this->hasIntersection = true;
			return rayOrigin + (t * rayDirection);
		}
	}

	this->hasIntersection = false;
	return NULL_VECTOR;
}
