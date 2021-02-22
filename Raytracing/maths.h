#pragma once

Vector3D NewVector(float x, float y, float z);
float GetNorme(const Vector3D& v);
Vector3D NormalizedVector(const Vector3D& vector);
float ScalarProduct(const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator*(const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator*(float factor, const Vector3D& vector);
Vector3D operator/(float quotient, const Vector3D& vector);
Vector3D operator-(const Vector3D& vector1, const Vector3D& vector2);
Vector3D operator+(const Vector3D& vector1, const Vector3D& vector2);
Vector3D ReflectedRay(const Vector3D& incidentVector, const Vector3D& normalVector);
Vector3D RefractedRay(const Vector3D& incidentVector, const Vector3D& normalVector, float RefractiveIndexN1, float RefractiveIndexN2);


