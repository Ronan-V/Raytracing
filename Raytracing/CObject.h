#pragma once
#include "maths.h"
class CObject {
protected:
	Vector3D position;
	bool hasIntersection = false;
public:
	CObject();
	CObject(Vector3D position);

	Vector3D get_position();

	~CObject();
};
