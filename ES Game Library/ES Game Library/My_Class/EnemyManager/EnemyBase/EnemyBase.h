#pragma once
#include"../../../ESGLib.h"
#include"../../Player_Class/Player/Player.h"
#include"../EnemyShotManager/EnemyShotManager.h"
#include"../../Object_Class/Object_Base/ObjectBase.h"

using namespace std;

class EnemyBase : public Object {
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

	const float material_power = 10.0f;
	const int half = 2;

	Vector3 pos = Vector3_Zero;
	const Vector3 collision_fit_pos    = Vector3(0.0f, 0.06f, 0.0f);
	const Vector3 model_init_pos       = Vector3(0.0f, 0.0f, 50.0f);
	const Vector3 collision_scele      = Vector3(0.2f, 0.15f, 0.5f);
};