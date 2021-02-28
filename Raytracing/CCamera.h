#pragma once
#include "CObject.h"
#include <FreeImage.h>
#include <vector>
#include "CSphere.h"
#include "CPlan.h"
#include "CScene.h"

/// <summary>
/// This class represents a camera
/// </summary>
class CCamera :
	public CObject
{
private:
	/// <summary>
	/// The viewplane's width
	/// </summary>
	float viewplaneWidth;

	/// <summary>
	/// Z vector
	/// </summary>
	Vector3D vecDir = NewVector(0, 0, 1);

	/// <summary>
	/// Y vector
	/// </summary>
	Vector3D upVec = NewVector(0, 1, 0);

	/// <summary>
	/// X vector
	/// </summary>
	Vector3D rightVec = NewVector(1, 0, 0);

	/// <summary>
	/// The viewplane's heigth
	/// </summary>
	float viewplaneHeight;

	/// <summary>
	/// The distance between the camera and the viewplane
	/// </summary>
	float viewplaneDist;

	/// <summary>
	/// The viewplane's top lef point position
	/// </summary>
	Vector3D topLeftPos;
public:
	CCamera() = default;
	~CCamera() = default;

	/// <summary>
	/// Creates a camera
	/// </summary>
	/// <param name="position">The camera's position</param>
	/// <param name="viewplaneWidth">The viewplane's width</param>
	/// <param name="viewplaneHeight">The viewplane's height</param>
	/// <param name="viewplaneDist">The distance between the camera and the viewplane</param>
	/// <param name="lookPosition">Position where the camera is looking</param>
	CCamera(Vector3D position, float viewplaneWidth, float viewplaneHeight, float viewplaneDist, Vector3D lookPosition);

	/// <summary>
	/// Calculates the normalised unit vector from the camera's position to a given pixel on viewplane
	/// </summary>
	/// <param name="x">Pixel's coordinates for X axis</param>
	/// <param name="y">Pixel's coordinates for Y axis</param>
	/// <param name="xRes">Viewplane width size (X axis)</param>
	/// <param name="yRes">Viewplane length size (Y axis)</param>
	/// <returns>The normalised unit vector from the camera's position to a given pixel on viewplane</returns>
	Vector3D calculate_normalised_unit_vector(float x, float y, float xRes, float yRes);

	//TODO documentation
	void Iradiate(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<std::pair <RGBQUAD, Vector3D>>* visibility);
	void IradiateBrice(short xScreen, short yScreen, short zScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<CPlan> myPlans, std::vector<std::pair<RGBQUAD, Vector3D>>* visibility, CScene& scene);
};
