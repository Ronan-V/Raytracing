#pragma once
#include "CIntersectionObject.h"
#include <vector>

using namespace std;

class CScene
{
private:
	vector<CIntersectionObject*> myObjects;
public:
	CScene() = default;
	~CScene() = default;

	int get_nb_objects();
	void add_object(CIntersectionObject* object);
	vector<CIntersectionObject*> get_objects_array();
};
