#include "CObject.h"

CObject::CObject(Vector3D position)
{
	this->position = position;
}

Vector3D CObject::get_position()
{
	return this->position;
}
