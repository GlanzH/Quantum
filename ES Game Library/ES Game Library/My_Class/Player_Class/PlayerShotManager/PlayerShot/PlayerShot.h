#pragma once
#include "../../../../ESGLib.h"

class PlayerShot 
{
public:
	void Initialize();
	void Update();
	void Draw3D();

	void  Shot(Vector3 pos);
	int   IsShot() { return shot_flag; }
	MODEL GetCollision();

private:
	MODEL   shot;
	MODEL   collision;
	Vector3 shot_pos;
	bool    shot_flag = false;

	enum { MIN_COUNT, MAX_COUNT = 50 };
	int frame = MAX_COUNT;

	const Vector3 collision_fit = Vector3(0, 0.06f, 0);

	const int half = 2;

	const float speed = 0.5f;
	const float material_power  = 10.0f;
	const float model_scale     = 0.25f;
	const float collision_scale = 0.1f;
	float shot_erace_pos ;
};