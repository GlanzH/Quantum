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

	MODEL GetEnemyShotCollision();

private:
	MODEL   shot;
	MODEL   collision;
	Vector3 shot_pos;
	bool    shot_flag = false;

	enum { HALF = 2 };
	enum {MIN_COUNT,MAX_COUNT = 120};

	int frame = MAX_COUNT;


	const float speed = -0.2f;
	const float material_power = 10.0f;
	float shot_erace_pos ;
};