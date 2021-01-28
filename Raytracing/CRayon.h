#pragma once
#include "CScene.h"

class CRayon :
	public CScene
{
private:
	Vector3D position;
	Vector3D direction;

public:
	CRayon();
	~CRayon();
	bool hasIntersection();
};

