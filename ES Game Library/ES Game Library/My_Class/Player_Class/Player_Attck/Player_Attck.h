#pragma once
#include "../../../ESGLib.h"


class Player_Attck 
{
public:
	 void Initialize();
	 void Update();
	 void Draw3D();
	 void Shot(float x,float y, int p_direction);
	 void SetDiretion(int direction) { };

	 MODEL GetShotModel() { return shot; }
	 MODEL GetCollision() { return hit_box; }

private:
	MODEL shot;

	MODEL hit_box;

	int direction;

	enum { SHOT_MAX = 1 };
	float shot_x[SHOT_MAX];
	float shot_y[SHOT_MAX];
	int shot_state[SHOT_MAX];
	Vector3 bull_pos;
};

