#include "CUtils.h"
/* Constructors */

/// <summary>
/// Fetches the configuration from the input file, 
/// </summary>
/// <param name="p_input_file_path">The input file's path</param>
CUtils::CUtils(std::string p_input_file_path) {
	std::vector<std::string> configuration = get_words_from_file(p_input_file_path);
	initialise_configuration(configuration);
}

/* Getters */

/// <summary>
/// Returns a list of CIntersectionObject pointers
/// </summary>
/// <returns>A list of CIntersectionObject pointers</returns>
std::vector<CIntersectionObject*> CUtils::get_objects()
{
	return this->objects;
}

std::vector<CLightSource> CUtils::get_light_sources()
{
	return this->light_sources;
}

std::vector<CSphere> CUtils::get_spheres()
{
	return this->spheres;
}

bool CUtils::get_isRelief()
{
	return this->isRelief;
}

/* IO */

/// <summary>
/// Reads a file and return a list of words contained in it
/// </summary>
/// <param name="p_file_path">The file's path to extract the words from</param>
/// <returns>A list of strings representing the words contained in the file</returns>
std::vector<std::string> CUtils::get_words_from_file(std::string p_file_path)
{
	std::vector<std::string> ret;
	std::ifstream configFile(p_file_path);

	std::string line;

	if (configFile.is_open()) {
		while (configFile >> line)
		{
			ret.push_back(line);
		}

		configFile.close();
	}
	else {
		std::cerr << "Error while processing the input file '" << p_file_path << "'" << std::endl;
	}

	return ret;
}

/* Configuration */

std::vector<std::string> CUtils::parse_line(std::string delimiter, std::string s) {
	std::vector<std::string> ret = std::vector<std::string>();

	size_t pos = 0;
	std::string token;

	for (size_t i = 0; i < 3; i++)
	{
		pos = s.find(delimiter);

		token = s.substr(0, pos);
		ret.push_back(token);
		s.erase(0, pos + delimiter.length());
	}

	return ret;
}

Vector3D CUtils::parse_vector3D_from_line(std::string s) {
	std::vector<std::string> coordinates = parse_line(",", s);

	if (coordinates.size() != 3)
	{
		std::cerr << "Error, there are not 3 coordinates in the input'" << s << "'" << std::endl;
		return NULL_VECTOR;
	}

	return NewVector(stof(coordinates[0]), stof(coordinates[1]), stof(coordinates[2]));
}

/// <summary>
/// Initialises the class members
/// </summary>
/// <param name="p_configuration"></param>
void CUtils::initialise_configuration(std::vector<std::string> p_configuration) {
	this->objects = std::vector<CIntersectionObject*>();
	this->light_sources = std::vector<CLightSource>();
	this->spheres = std::vector<CSphere>();
	this->isRelief = false;

	if (p_configuration[0] == "relief" && p_configuration[1] == "true")
	{
		this->isRelief = true;
	}
	int nbObjects = stoi(p_configuration[2]);


	p_configuration.erase(p_configuration.begin(), p_configuration.begin() + 3);

	int i = 0;
	int objectsDone = 0;
	while (objectsDone < nbObjects && i < p_configuration.size())
	{
		CIntersectionObject* ret;
		if (p_configuration[i] == "lightSource")
		{
			CLightSource light = CLightSource(parse_vector3D_from_line(p_configuration[i + 1]));
			this->light_sources.push_back(light);
			i += 2;
		}
		else {
			if (p_configuration[i] == "plan")
			{
				ret = new CPlan(parse_vector3D_from_line(p_configuration[i + 1]), parse_vector3D_from_line(p_configuration[i + 2]));
			}
			else if (p_configuration[i] == "sphere")
			{
				ret = new CSphere(parse_vector3D_from_line(p_configuration[i + 1]), stof(p_configuration[i + 2]));
				this->spheres.push_back(CSphere(parse_vector3D_from_line(p_configuration[i + 1]), stof(p_configuration[i + 2])));
			}
			else
			{
				std::cerr << "Error, object type not recognised '" << p_configuration[i] << "'" << std::endl;
				break;
			}
			i += 3;
			this->objects.push_back(ret);
		}
		objectsDone++;
	}
}
