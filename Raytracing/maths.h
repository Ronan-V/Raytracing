#pragma once
#include <iostream>
#include <math.h>

struct Vector3D {
	float x;
	float y;
	float z;
};

Vector3D NewVector(float x, float y, float z);
const Vector3D NULL_VECTOR = NewVector(0, 0, 0);

float GetNorme(const Vector3D& v);
Vector3D Normalize(const Vector3D& vector);
float ScalarProduct(const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator*(const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator*(float factor, const Vector3D& vector);
Vector3D operator/(float quotient, const Vector3D& vector);
Vector3D operator-(const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator+(const Vector3D& vector1, const Vector3D& vector2);
bool operator==(const Vector3D& vector1, const Vector3D& vector2);
bool operator!=(const Vector3D& vector1, const Vector3D& vector2);
Vector3D ReflectedRay(const Vector3D& incidentVector, const Vector3D& normalVector);
Vector3D RefractedRay(const Vector3D& incidentVector, const Vector3D& normalVector, float RefractiveIndexN1, float RefractiveIndexN2);
float DistanceVectors(const Vector3D& vector1, const Vector3D& vector2);
