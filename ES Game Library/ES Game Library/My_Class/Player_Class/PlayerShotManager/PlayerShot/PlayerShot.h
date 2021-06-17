#pragma once
#include "../../../../ESGLib.h"

class PlayerShot {
public:
	void Initialize();
	void Update();
	void Draw3D();

	void  Shot(Vector3 pos);
	int   IsShot() { return shot_flag; }

private:
	MODEL   shot;
	Vector3 shot_pos;
	bool    shot_flag = false;

	enum { HALF = 2 };
	const float speed = 0.2f;
	const float material_power = 10.0f;
	const float shot_erace_pos = 10.0f;
};