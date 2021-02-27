#pragma once
#include "maths.h"

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
