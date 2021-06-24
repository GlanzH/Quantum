#pragma once
#include "../../../../ESGLib.h"
#include "../../../Player_Class/Player/Player.h"

class EnemyShot 
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

	enum {MIN_COUNT,MAX_COUNT = 120};
	int frame = MAX_COUNT;

	const int half = 2;
	
	const Vector3 collision_fit = Vector3(0, 0.06f, 0);

	const float speed = -0.2f;
	const float material_power  = 10.0f;
	const float model_scale     = 0.25f;
	const float collision_scale = 0.1f;
	float shot_erace_pos ;
};