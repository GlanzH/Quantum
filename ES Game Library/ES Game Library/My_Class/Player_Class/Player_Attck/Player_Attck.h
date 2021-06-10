#pragma once
#include "../../../ESGLib.h"


class Player_Attck 
{
public:
	 void Initialize();
	 void Update();
	 void Draw();
	 void shot(float x,float y, int p_direction);
	 void SetDiretion(int direction) { };
	
private:
	SPRITE Ofuda;

	Rect hit_box;

	int direction;
public:
	enum { SHOT_MAX = 1 };
	float shot_x[SHOT_MAX];
	float shot_y[SHOT_MAX];
	int shot_state[SHOT_MAX];
	float x, y;
};

