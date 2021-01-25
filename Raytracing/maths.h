#pragma once
#include <math.h>

struct Vector3D {
	float x, y, z;
};

Vector3D NewVector(float x, float y, float z)
{
	Vector3D newVector = { x, y, z };
	return newVector;
}

float GetNorme(const Vector3D& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3D NormalizedVector(const Vector3D& vector)
{
	Vector3D normalizedVector;

	float norm = GetNorme(vector);
	if (norm != 0)
	{
		normalizedVector.x = vector.x / norm;
		normalizedVector.y = vector.y / norm;
		normalizedVector.z = vector.z / norm;
	}
	else
	{
		std::cout << "La norme est égal à 0" << std::endl;
	}
	return normalizedVector;
}

float ScalarProduct(const Vector3D& vector1, const Vector3D& vector2) // MA.MB
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

Vector3D VectorProduct(const Vector3D& vector1, const Vector3D& vector2) // MA * MB
{
	Vector3D resultedVector;
	resultedVector.x = vector1.y * vector2.z - vector1.z * vector2.y;
	resultedVector.x = vector1.z * vector2.x - vector1.x * vector2.z;
	resultedVector.x = vector1.x * vector2.y - vector1.y * vector2.x;
	return resultedVector;
}


Vector3D FactorizeVector(float factor, const Vector3D& vector) // x * MA
{
	Vector3D factorizedVector;
	factorizedVector.x = vector.x * factor;
	factorizedVector.y = vector.y * factor;
	factorizedVector.z = vector.z * factor;
	return factorizedVector;
}

Vector3D SoustractVectors(const Vector3D& vector1, const Vector3D& vector2)
{
	Vector3D soustractedVector;
	soustractedVector.x = vector1.x - vector2.x;
	soustractedVector.y = vector1.y - vector2.y;
	soustractedVector.z = vector1.z - vector2.z;
	return soustractedVector;
}

Vector3D SumVectors(const Vector3D& vector1, const Vector3D& vector2)
{
	Vector3D summedVector;
	summedVector.x = vector1.x + vector2.x;
	summedVector.y = vector1.y + vector2.y;
	summedVector.z = vector1.z + vector2.z;
	return summedVector;
}

Vector3D ReflectedRay(const Vector3D& incidentVector, const Vector3D& normalVector)
{
	//R = I - 2 x (I.N) x N
	Vector3D reflectedRay;
	float scalar = 2 * ScalarProduct(incidentVector, normalVector); // 2 x (I.N)
	Vector3D tmp = FactorizeVector(scalar, normalVector); // 2 x (I.N) * N
	reflectedRay = SoustractVectors(incidentVector, tmp); // I - 2 x (I.N) * N
}

Vector3D RefractedRay(const Vector3D& incidentVector, const Vector3D& normalVector, float RefractiveIndexN1, float RefractiveIndexN2)
{
	float Scalar = ScalarProduct(incidentVector, normalVector); //cos(Teta) = (u.v) / ||u|| . ||v||
	Vector3D NormInci = NormalizedVector(incidentVector);
	Vector3D NormNormal = NormalizedVector(normalVector);
	float NormScalar = ScalarProduct(NormInci, NormNormal);
	float CosTeta = Scalar / NormScalar;
	float Teta = acos(CosTeta) * 180 / 3.141;
	float Teta2 = Re

