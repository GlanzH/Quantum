#include"EnemyManager.h"


bool EnemyManager::Initialize() {
	enemy.Initialize();
	return true;
}

int EnemyManager::Update() {
	enemy.Update();

	auto itr = enemy_list.begin();
	while (itr != enemy_list.end()) {
		if ((*itr)->LifeDeathDecision() == LIFE)
			itr++;
		else if ((*itr)->LifeDeathDecision() == DEAD) {

		}
		else {

		}
	}

	return 0;
}

void EnemyManager::Draw3D() {
	enemy.Draw3D();
}