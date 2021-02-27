#pragma once
#include "CScene.h"

enum TypeReflexion
{
	diffuse
};

class CMaterials
{
private:
	Vector3D viewPointDirection;
	Vector3D lightSourceDirection;
public:
	CMaterials() = default;
	~CMaterials() = default;
};
