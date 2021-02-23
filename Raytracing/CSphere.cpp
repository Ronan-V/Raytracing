#include "CSphere.h"

CSphere::CSphere()
{
}

CSphere::CSphere(Vector3D position, float rayon)
{
	this->position = position;
	this->rayon = rayon;
}

CSphere::~CSphere()
{
}

Vector3D CSphere::SphereIntersection(CRay ray)
{
	float t;

	Vector3D rayDirection = ray.GetDirection();
	Vector3D rayOrigin = ray.get_position();
	float X_zero = rayOrigin.x - position.x;
	float Y_zero = rayOrigin.y - position.y;
	float Z_zero = rayOrigin.z - position.z;

	//Equation is: pow(t, 2) * (pow(rayDirection.x, 2) + pow(rayDirection.y, 2) + pow(rayDirection.z, 2)) + 2 * t * (X_zero * rayDirection.x + Y_zero * rayDirection.y + Z_zero * rayDirection.z) + (pow(X_zero, 2) + (pow(Y_zero, 2) + (pow(Z_zero, 2)) - pow(rayon, 2);
	float a = rayDirection.x*rayDirection.x + rayDirection.y*rayDirection.y + rayDirection.z*rayDirection.z;
	float b = X_zero * rayDirection.x + Y_zero * rayDirection.y + Z_zero * rayDirection.z;
	float c = (X_zero*X_zero + Y_zero*Y_zero + Z_zero*Z_zero) - rayon*rayon;

	float det = b*b - 4 * a * c;

	if (det == 0) // 1 intersection
	{
		t = -b / (2 * a);
	}
	else if (det > 0) // 2 intersections
	{
		float t1 = (-b + sqrt(det)) / (2 * a);
		float t2 = (-b - sqrt(det)) / (2 * a);
		//std::cout << t2;
		//TODO Calculer lequel est le plus près de la caméra et return celui-ci car c'est celui qu'il faut afficher
		if (t1 < t2) t = t1;
		else t = t2;
	}
	else //det < 0 --> No intersection
	{
		t = 0;
	}

	if (t == 0) return NewVector(0, 0, 0); // No intersection

	Vector3D intersection = rayOrigin + (t * rayDirection);
	return intersection;
}

bool CSphere::SphereIntersectionBool(CRay ray) {
	return SphereIntersection(ray) != NewVector(0, 0, 0);
}
