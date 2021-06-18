#pragma once
#include "../../../ESGLib.h"
#include "PlayerShot/PlayerShot.h"


class PlayerShotManager {
public:
	void Initialize();
	void Update();
	void Draw3D();

	void  Shot(Vector3 pos);
	int   IsShot();

private:
	enum { MAX_SHOT = 1 };
	PlayerShot player_shot[MAX_SHOT];
};