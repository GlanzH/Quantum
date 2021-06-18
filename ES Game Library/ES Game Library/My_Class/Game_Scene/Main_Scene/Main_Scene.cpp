#include "Main_Scene.h"
#include"../../Scene_Manegeer/SceneManager.h"
#include"../../Player_Class/Player/Player.h"
#include"../../All_Enemy/Enemy_Manager/Enemy_Manager.h"
#include"../../Map_Class/Map.h"

void Main_Scene::Initialize()
{
	bg = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/MainScene_Material/Red.png"));
	
	Player::Instance().Initialize();
	camera.Init();
	map.Initialize();
	

	//enemy_manager.Initialize();
}
void Main_Scene::Update()
{
	Player::Instance().Update();
	
	if (Input.GetKeybordInputDown(Keys_Enter))
	{
		SceneManager::ChangeScene(SceneManager::SCENE::CLAER_SCENE);
		return;
	}
	if (Input.GetKeybordInputDown(Keys_LeftShift))
	{
		SceneManager::ChangeScene(SceneManager::SCENE::OVER_SCENE);
		return;
	}
	
	map.Update();
	//enemy_manager.Update();//
}
void Main_Scene::Draw()
{
	//enemy_manager.Draw();
	SpriteBatch.Draw(*bg,Vector3(Zero, Zero,10000));
	
}
void Main_Scene::Draw3D() 
{
	Player::Instance().Draw3D();
	camera.Draw3D();
	map.Draw3D();
}