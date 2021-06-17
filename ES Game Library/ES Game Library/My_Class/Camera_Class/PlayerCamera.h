#pragma once
#include"../../ESGLib.h"
#include "../Player_Class/Player/Player.h"

class PlayerCamera
{
public:
	PlayerCamera() {};
	~PlayerCamera() {};

	void Init();
	//void Update();
	void Draw3D();
	
	CAMERA Getcamera() const{ return camera; };
	Light  GetLight()  const { return light; };
	void   SetCameraAngle(float _cameraField) { cameraPos += _cameraField; };


private:
	CAMERA camera;
	Light   light;
	float cameraPos;
	const float speed = 0.002f;
	MODEL player;
	enum { CAMERA_POS = 30 };
};

