#include "EnemyShotManager.h"

void EnemyShotManager::Initialize() {
	for (int i = 0; i < MAX_SHOT; ++i) 
		enemy_shot[i].Initialize();
}

void EnemyShotManager::Update() {
	for (int i = 0; i < MAX_SHOT; ++i)
		enemy_shot[i].Update();
}

void EnemyShotManager::Draw3D() {
	for (int i = 0; i < MAX_SHOT; ++i)
		enemy_shot[i].Draw3D();
}

void EnemyShotManager::Shot(Vector3 pos) {
	for (int i = 0; i < MAX_SHOT; ++i) {
		if (enemy_shot[i].IsShot()) {
		}
		else {
			enemy_shot[i].Shot(pos);
			break;
		}
	}
}

int EnemyShotManager::IsShot() {
	int shot_count = 0;
	for (int i = 0; i < MAX_SHOT; ++i) {
		if (enemy_shot[i].IsShot())
			shot_count++;

		return shot_count;
	}
}