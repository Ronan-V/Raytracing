#pragma once
#include "CScene.h"

class CLightSource :
	public CScene
{
private:
	Vector3D position;

public:
	CLightSource();
	~CLightSource();
	
	void Illuminate();
};

