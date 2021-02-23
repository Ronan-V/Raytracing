#include "CScene.h"
#include "FreeImage.h"
#include <vector>
#include "CSphere.h"


class CCamera :
	public CScene
{
private:

public:
	~CCamera();
	CCamera();
	void Iradiate(short xScreen, short yScreen, FIBITMAP* image, std::vector<CSphere> mySpheres, std::vector<std::pair <RGBQUAD, Vector3D>> *visibility);
};

