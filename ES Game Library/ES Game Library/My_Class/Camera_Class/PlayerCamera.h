#pragma once
#include"../../ESGLib.h"

class PlayerCamera
{
public:
	PlayerCamera() {};
	virtual ~PlayerCamera() {};

	virtual void Init();
	virtual void Draw3D();
	
	CAMERA Getcamera() const{ return camera; };
	Light  GetLight()  const { return light; };
	void   SetCameraAngle(float _cameraField) { cameraPos += _cameraField; };


private:
	CAMERA camera;
	Light   light;


	float cameraPos;
};

