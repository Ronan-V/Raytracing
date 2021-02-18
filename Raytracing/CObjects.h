#pragma once
#include "CScene.h"
#include "CRay.h"
class CObjects :
    public CScene
{
private:
    Vector3D position;

public:
    CObjects();
    ~CObjects();
};