#pragma once
#include "CObject.h"

class CRay :
	public CObject
{
private:
	Vector3D direction;
public:
	CRay();
	CRay(Vector3D position, Vector3D direction);
	~CRay();

	bool hasIntersection();

	Vector3D GetDirection();
};
