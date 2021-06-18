#pragma once
#include"../../Scene_Manegeer/SceneManager.h"
#include"../../Player_Class/Player/Player.h"
#include"../../All_Enemy/Enemy_Base/Enemy_Base.h"
#include"../../All_Enemy/Enemy_Manager/Enemy_Manager.h"
#include"../../Camera_Class/PlayerCamera.h"
#include"../../Map_Class/Map.h"

class Main_Scene : public BaseScene
{
public:
	/*Main_Scene() : player(CollisionMediator) {};*/
	virtual ~Main_Scene() {};

	virtual void Initialize()override;
	virtual void Update()    override;
	virtual void Draw()      override;
	virtual void Draw3D()    override;

	virtual void DrawEnd() {};
private:
	SPRITE bg;
	Map map;
	PlayerCamera camera;
    
	//Enemy_Manager enemy_manager;
	enum MagicNum
	{
		Zero = 0
	};
};