#pragma once
#include"../../Scene_Manegeer/SceneManager.h"
#include"../../EnemyManager/EnemyManager.h"
#include"../../Player_Class/Player/Player.h"
#include"../../Camera_Class/PlayerCamera.h" 
#include"../../Map_Class/Map.h"
#include"../../UI_Class/UI.h"

class Main_Scene : public BaseScene
{
public:
	/*Main_Scene() : player(CollisionMediator) {};*/
	Main_Scene();
	virtual  ~Main_Scene();

	virtual void Initialize()override;
	virtual void Update()    override;
	virtual void Draw()      override;
	virtual void Draw3D()    override;

	virtual void DrawEnd() {};
private:
	SPRITE bg;
	Map map;
	PlayerCamera camera;
	EnemyManager enemymanager;
	UI ui;

	const Vector3 bg_pos = Vector3(0, 0, 10000);
};