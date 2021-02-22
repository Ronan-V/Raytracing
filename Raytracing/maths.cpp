#pragma once
#include "maths.h";

inline Vector3D NewVector(float x, float y, float z)
{
	Vector3D newVector = { x, y, z };
	return newVector;
}

inline float GetNorme(const Vector3D& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3D NormalizedVector(const Vector3D& vector)
{
	Vector3D normalizedVector;

	float norm = GetNorme(vector);
	if (norm != 0)
	{
		normalizedVector = norm / vector;
	}
	else
	{
		std::cout << "La norme est égal à 0" << std::endl;
	}
	return normalizedVector;
}

inline float ScalarProduct(const Vector3D& vector1, const Vector3D& vector2) // MA.MB
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

inline Vector3D operator*(const Vector3D& vector1, const Vector3D& vector2) // MA * MB
{
	Vector3D resultedVector;
	resultedVector.x = vector1.y * vector2.z - vector1.z * vector2.y;
	resultedVector.y = vector1.z * vector2.x - vector1.x * vector2.z;
	resultedVector.z = vector1.x * vector2.y - vector1.y * vector2.x;
	return resultedVector;
}


inline Vector3D operator*(float factor, const Vector3D& vector) // x * MA
{
	Vector3D factorizedVector;
	factorizedVector.x = vector.x * factor;
	factorizedVector.y = vector.y * factor;
	factorizedVector.z = vector.z * factor;
	return factorizedVector;
}

inline Vector3D operator/(float quotient, const Vector3D& vector)
{
	Vector3D dividedVector;
	dividedVector.x = vector.x / quotient;
	dividedVector.y = vector.y / quotient;
	dividedVector.z = vector.z / quotient;
	return dividedVector;
}

inline Vector3D operator-(const Vector3D& vector1, const Vector3D& vector2)
{
	Vector3D soustractedVector;
	soustractedVector.x = vector1.x - vector2.x;
	soustractedVector.y = vector1.y - vector2.y;
	soustractedVector.z = vector1.z - vector2.z;
	return soustractedVector;
}

inline Vector3D operator+(const Vector3D& vector1, const Vector3D& vector2)
{
	Vector3D summedVector;
	summedVector.x = vector1.x + vector2.x;
	summedVector.y = vector1.y + vector2.y;
	summedVector.z = vector1.z + vector2.z;
	return summedVector;
}

inline bool operator==(const Vector3D& vector1, const Vector3D& vector2)
{
	return vector1.x == vector2.x && vector1.y == vector2.y && vector1.z == vector2.z;
}

inline bool operator!=(const Vector3D& vector1, const Vector3D& vector2)
{
	return !(vector1 == vector2);
}

inline Vector3D ReflectedRay(const Vector3D& incidentVector, const Vector3D& normalVector)
{
	//R = I - 2 x (I.N) x N
	Vector3D reflectedRay;
	float scalar = ScalarProduct(incidentVector, normalVector); // (I.N)
	reflectedRay = incidentVector - 2 * scalar * normalVector; // I - 2 x (I.N) * N
	return reflectedRay;
}

inline Vector3D RefractedRay(const Vector3D& incidentVector, const Vector3D& normalVector, float RefractiveIndexN1, float RefractiveIndexN2)
{
	float Scalar = ScalarProduct(incidentVector, normalVector); //cos(Teta) = (u.v) / ||u|| . ||v||
	Vector3D NormInci = NormalizedVector(incidentVector);
	Vector3D NormNormal = NormalizedVector(normalVector);
	float NormScalar = ScalarProduct(NormInci, NormNormal);
	float CosTeta = Scalar / NormScalar;
	float Teta1 = acos(CosTeta);
	float Teta2 = RefractiveIndexN1 * sin(Teta1) / RefractiveIndexN2;
	Vector3D RefractedRayD2 = NewVector(incidentVector.x * RefractiveIndexN1 / RefractiveIndexN2 + (RefractiveIndexN1 / RefractiveIndexN2 * cos(Teta1) - cos(Teta2)) * normalVector.x,
		incidentVector.y * RefractiveIndexN1 / RefractiveIndexN2 + (RefractiveIndexN1 / RefractiveIndexN2 * cos(Teta1) - cos(Teta2)) * normalVector.y,
		incidentVector.z * RefractiveIndexN1 / RefractiveIndexN2 + (RefractiveIndexN1 / RefractiveIndexN2 * cos(Teta1) - cos(Teta2)) * normalVector.z);
	return RefractedRayD2;
}
