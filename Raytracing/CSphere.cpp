#include "CSphere.h"

CSphere::CSphere()
{
}

CSphere::~CSphere()
{
}

CSphere::CSphere(Vector3D position, float rayon)
{
	this->position = position;
	this->rayon = rayon;
}

Vector3D CSphere::SphereIntersection(CRay ray)
{
	float t; //Variable in our equation

	Vector3D rayDirection = ray.GetDirection();
	Vector3D rayOrigin = ray.GetOrigin();
	float X_zero = rayOrigin.x - position.x;
	float Y_zero = rayOrigin.y - position.y;
	float Z_zero = rayOrigin.z - position.z;

	//Equation is: pow(t, 2) * (pow(rayDirection.x, 2) + pow(rayDirection.y, 2) + pow(rayDirection.z, 2)) + 2 * t * (X_zero * rayDirection.x + Y_zero * rayDirection.y + Z_zero * rayDirection.z) + (pow(X_zero, 2) + (pow(Y_zero, 2) + (pow(Z_zero, 2)) - pow(rayon, 2);
	float a = pow(rayDirection.x, 2) + pow(rayDirection.y, 2) + pow(rayDirection.z, 2);
	float b = (X_zero * rayDirection.x + Y_zero * rayDirection.y + Z_zero * rayDirection.z)/4;
	float c = (pow(X_zero, 2) + pow(Y_zero, 2) + pow(Z_zero, 2)) - pow(rayon, 2);

	float det = pow(b, 2) - 4 * a * c;
	int float_det = (int)det;

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
		t = 0;
		//std::cout << "0 intersection" << std::endl;;
	}

	if (t == 0) return NewVector(0, 0, 0); // No intersection

	Vector3D intersection = SumVectors(rayOrigin, FactorizeVector(t, rayDirection));
	return intersection;
}
