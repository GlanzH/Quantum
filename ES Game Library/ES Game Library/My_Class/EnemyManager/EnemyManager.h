#pragma once
#include"../../ESGLib.h"
#include"EnemyBase/EnemyBase.h"

class EnemyManager {
public:
	EnemyManager();
	~EnemyManager();

	bool Initialize();
	int  Update();
	void Draw3D();
	void Generate();
	std::list<EnemyBase*> PushBackList();
private:
	int frame = 0;

	EnemyBase enemy;
	std::list<EnemyBase*> enemy_list;
	enum {LIFE,DEAD,AUTODEAD};
protected:
};