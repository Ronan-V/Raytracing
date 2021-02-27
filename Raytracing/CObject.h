#pragma once
#include "maths.h"

/// <summary>
/// This class represents an object with a position
/// </summary>
class CObject {
protected:
	/// <summary>
	/// The object's position
	/// </summary>
	Vector3D position;

	//TODO ???
	bool hasIntersection = false;
public:
	CObject() = default;
	~CObject() = default;

	/// <summary>
	/// Creates an object with a position
	/// </summary>
	/// <param name="position">The object's position</param>
	CObject(Vector3D position);

	/// <summary>
	/// Returns the object's position
	/// </summary>
	/// <returns>The object's position</returns>
	Vector3D get_position();
};
