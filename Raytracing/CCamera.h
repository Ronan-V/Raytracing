#pragma once
#include "CScene.h"

class CCamera :
	public CScene
{
private:
	Vector3D position;

public:
	CCamera();
	~CCamera();
};

