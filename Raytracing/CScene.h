#pragma once
#include <vector>
#include "CObject.h"
#include "CPlan.h"
#include "CSphere.h"
#include "CIntersectionObject.h"

using namespace std;

class CScene
{
private:
	vector<CIntersectionObject*> myObjects;
	int nbObjects;

public:
	CScene();
	~CScene();

	int get_nb_objects();
	void add_object(CIntersectionObject* object);
	vector<CIntersectionObject*> get_objects_array();
};

