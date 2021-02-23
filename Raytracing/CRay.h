#pragma once
#include "CScene.h"

class CRay :
	public CScene
{
private:
	Vector3D origin;
	Vector3D direction;

public:
	CRay();
	~CRay();
	CRay(Vector3D origin, Vector3D direction);

	bool hasIntersection();

	Vector3D GetOrigin();
	Vector3D GetDirection();
};

