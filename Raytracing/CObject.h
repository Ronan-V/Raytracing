#pragma once
#include "maths.h"
class CObject {
protected:
	Vector3D position;
public:
	CObject();
	CObject(Vector3D position);

	Vector3D get_position();

	~CObject();
};
