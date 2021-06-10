#pragma once
#include"../../Scene_Manegeer/SceneManager.h"
#include"../../Player_Class/Player/Player.h"
#include"../../All_Enemy/Enemy_Base/Enemy_Base.h"
#include"../../All_Enemy/Enemy_Manager/Enemy_Manager.h"

class Main_Scene : public BaseScene
{
public:
	/*Main_Scene() : player(CollisionMediator) {};*/
	virtual ~Main_Scene() {};

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;

	virtual void DrawEnd() {};
private:

	SPRITE Main;
	SPRITE Main_Secoud;
	SPRITE Main_Third;
	float Main_x;
	float Main2_x;
	float Main3_x;
     //Player player;//
	//Enemy_Manager enemy_manager;
	MUSIC  BGM;
};