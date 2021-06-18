#include "PlayerShotManager.h"

void PlayerShotManager::Initialize() {
	for (int i = 0; i < MAX_SHOT; ++i) 
		player_shot[i].Initialize();
}

void PlayerShotManager::Update() {
	for (int i = 0; i < MAX_SHOT; ++i)
		player_shot[i].Update();
}

void PlayerShotManager::Draw3D() {
	for (int i = 0; i < MAX_SHOT; ++i)
		player_shot[i].Draw3D();
}

void PlayerShotManager::Shot(Vector3 pos) {
	for (int i = 0; i < MAX_SHOT; ++i) {
		if (player_shot[i].IsShot()) {
		}
		else {
			player_shot[i].Shot(pos);
			break;
		}
	}
}

int PlayerShotManager::IsShot() {
	int shot_count = 0;
	for (int i = 0; i < MAX_SHOT; ++i) {
		if (player_shot[i].IsShot())
			shot_count++;

		return shot_count;
	}
}