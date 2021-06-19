#pragma once
#include"../../../ESGLib.h"
#include"../../Player_Class/Player/Player.h"
#include"../EnemyShotManager/EnemyShotManager.h"

using namespace std;

class EnemyBase {
public:
	EnemyBase();
	~EnemyBase();

	bool Initialize();
	int  Update();
	void Draw3D();
	MODEL   GetCollision();

	int LifeDeathDecision();

private:
	void Move();
	
	enum { LIVE, DEATH, AUTODEAD };

	EnemyShotManager enemy_shot_manager;

	MODEL Model;
	MODEL Collision;
	int hp;

	Vector3 pos = Vector3_Zero;
	const Vector3 collision_fit_pos = Vector3(0, 0.06f, 0);
};