#pragma once
#include "CScene.h"

class CRay :
	public CScene
{
private:
	Vector3D position;
	Vector3D direction;

public:
	CRay();
	~CRay();
};

