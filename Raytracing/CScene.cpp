#include "CScene.h"

int CScene::get_nb_objects()
{
	return myObjects.size();
}

void CScene::add_object(CIntersectionObject* object)
{
	myObjects.push_back(object);
}

vector<CIntersectionObject*> CScene::get_objects_array()
{
	return myObjects;
}
