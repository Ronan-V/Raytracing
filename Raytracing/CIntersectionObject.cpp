#include "CIntersectionObject.h"

CIntersectionObject::CIntersectionObject(Vector3D position) : CObject(position)
{
}

bool CIntersectionObject::has_intersection(CRay ray)
{
	return get_intersection_coordinates(ray) != NewVector(0, 0, 0);
}
