#pragma once
#include "CObject.h"
#include "CRay.h"
#include <iostream>

class CPlan :
	public CObject
{
private:
	Vector3D root;
	float longueur;
	float largeur;

public:
	CPlan();
	CPlan(Vector3D root, float longueur, float largeur);
	~CPlan();
	
	Vector3D get_intersection_coordinates(CRay ray);

};
