#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "CIntersectionObject.h"
#include "CPlan.h"
#include "CSphere.h"
#include "CLightSource.h"
#include "maths.h"

class CUtils
{
private:
	std::vector<CIntersectionObject*> objects;
	std::vector<CLightSource> light_sources;
	std::vector<CSphere> spheres;
	bool isRelief;

	std::vector<std::string> get_words_from_file(std::string p_file_path);
	std::vector<std::string> parse_line(std::string delimiter, std::string s);
	Vector3D parse_vector3D_from_line(std::string s);
	void initialise_configuration(std::vector<std::string> p_configuration);
public:
	CUtils() = default;
	~CUtils() = default;
	CUtils(std::string p_input_file_path);
	std::vector<CIntersectionObject*> get_objects();
	std::vector<CLightSource> get_light_sources();
	std::vector<CSphere> get_spheres();
	bool get_isRelief();

};
