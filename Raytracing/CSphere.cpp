#include "CSphere.h"

CSphere::CSphere(Vector3D position, float rayon) : CIntersectionObject(position)
{
	this->rayon = rayon;
}

Vector3D CSphere::get_intersection_coordinates(CRay ray)
{
	float t; //Variable in our equation

	Vector3D rayDirection = ray.GetDirection();
	Vector3D rayOrigin = ray.get_position();
	float X_zero = rayOrigin.x - position.x;
	float Y_zero = rayOrigin.y - position.y;
	float Z_zero = rayOrigin.z - position.z;

	//Equation is: pow(t, 2) * (pow(rayDirection.x, 2) + pow(rayDirection.y, 2) + pow(rayDirection.z, 2)) + 2 * t * (X_zero * rayDirection.x + Y_zero * rayDirection.y + Z_zero * rayDirection.z) + (pow(X_zero, 2) + (pow(Y_zero, 2) + (pow(Z_zero, 2)) - pow(rayon, 2);
	float a = rayDirection.x * rayDirection.x + rayDirection.y * rayDirection.y + rayDirection.z * rayDirection.z;
	float b = 2 * (X_zero * rayDirection.x + Y_zero * rayDirection.y + Z_zero * rayDirection.z);
	float c = (X_zero * X_zero + Y_zero * Y_zero + Z_zero * Z_zero) - rayon * rayon;

	float det = b * b - 4 * a * c;

	if (det == 0) // 1 intersection
	{
		t = -b / (2 * a);
		//std::cout << "1 intersection  : t = " << t << std::endl;
	}
	else if (det > 0) // 2 intersections
	{
		float t1 = (-b + sqrt(det)) / (2 * a);
		float t2 = (-b - sqrt(det)) / (2 * a);
		//std::cout << "2 intersections  : t1 = " << t1 << "t2 = " << t2 << std::endl;
		if (t1 < t2) t = t1;
		else t = t2;
	}
	else //det < 0 --> No intersection
	{
		this->hasIntersection = false;
		return NULL_VECTOR;
	}
	this->hasIntersection = true;
	return rayOrigin + (t * rayDirection);
}
