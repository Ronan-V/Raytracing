#include "CScene.h"

CScene::CScene()
{
	nbObjects = 0;
}

CScene::~CScene()
{
}

int CScene::get_nb_objects()
{
	return nbObjects;
}

void CScene::add_object(CIntersectionObject* object)
{
	nbObjects++;
	myObjects.push_back(object);
}

vector<CIntersectionObject*> CScene::get_objects_array()
{
	return myObjects;
}
