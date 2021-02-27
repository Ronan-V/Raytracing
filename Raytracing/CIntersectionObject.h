#pragma once
#include "CObject.h"
#include "CRay.h"

/// <summary>
/// This class represents an object with a position, that can intersect with a ray
/// </summary>
class CIntersectionObject
	: public CObject
{
public:
	CIntersectionObject() = default;
	~CIntersectionObject() = default;

	/// <summary>
	/// Creates an object with a position, that can intersect with a ray
	/// </summary>
	/// <param name="position">The object's position</param>
	CIntersectionObject(Vector3D position);

	/// <summary>
	/// Returns the intersection coordinates with the passed ray if there is an intersection, a zero vector else
	/// </summary>
	/// <param name="ray">The ray</param>
	/// <returns>The intersection coordinates with the passed ray if there is an intersection, a zero vector else</returns>
	virtual Vector3D get_intersection_coordinates(CRay ray) = 0;

	/// <summary>
	/// Returns true if the ray intersects with the object, false else
	/// </summary>
	/// <param name="ray">The ray</param>
	/// <returns>true if the ray intersects with the object, false else</returns>
	bool has_intersection(CRay ray);
};
