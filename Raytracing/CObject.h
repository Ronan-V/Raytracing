#pragma once
#include "CScene.h"
#include "CRay.h"
class CObject {
private:
protected:
	Vector3D position;
public:
	CObject();
	CObject(Vector3D position);

	Vector3D get_position();

	~CObject();
};
