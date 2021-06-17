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
	void   SetCameraAngle(float _cameraField) { camera_pos += _cameraField; };


private:
	CAMERA camera;
	Light   light;
	float camera_pos;
	const float speed = 0.002f;
	MODEL player;

	const Vector3 light_pos = Vector3( 0, 10, 0);

	const Vector3 camera_rotate   = Vector3(5.0f, 0.0f, 0.0f);
	const Vector3 camera_init_pos = Vector3(0.0f, 0.04f, 0.0f);

	const Vector3 camera_y = Vector3(0.0f, 0.5f, -0.9f);
 	const Vector3 camera_z = Vector3(0.0f, -0.56f, 7.0f);
	enum { CAMERA_POS = 30 };
};

