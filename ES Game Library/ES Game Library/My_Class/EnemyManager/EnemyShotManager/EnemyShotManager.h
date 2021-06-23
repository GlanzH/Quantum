#pragma once
#include "../../../ESGLib.h"
#include "EnemyShot/EnemyShot.h"


class EnemyShotManager {
public:
	void Initialize();
	void Update();
	void Draw3D();

	void  Shot(Vector3 pos);
	int   IsShot();

private:
	enum { MAX_SHOT = 1 };
	EnemyShot enemy_shot[MAX_SHOT];
};