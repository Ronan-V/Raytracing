#include "CPlan.h"

CPlan::CPlan()
{
}

CPlan::CPlan(Vector3D root, float longueur, float largeur)
{
	this->root = root;
	this->longueur = longueur;
	this->largeur = largeur;
}

CPlan::~CPlan()
{
}

Vector3D CPlan::get_intersection_coordinates(CRay ray)
{
	Vector3D rayDirection = ray.GetDirection();
	Vector3D rayOrigin = ray.get_position();
}