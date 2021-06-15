#include "Main_Scene.h"
#include"../../Scene_Manegeer/SceneManager.h"
#include"../../Player_Class/Player/Player.h"
#include"../../All_Enemy/Enemy_Manager/Enemy_Manager.h"
#include"../../Map_Class/Map.h"

void Main_Scene::Initialize()
{
	Main = GraphicsDevice.CreateSpriteFromFile(_T("Game_Scene/Stage.png"));
	Main_Secoud = GraphicsDevice.CreateSpriteFromFile(_T("Game_Scene/Stage.png"));
    Main_Third = GraphicsDevice.CreateSpriteFromFile(_T("Game_Scene/Stage.png"));
	BGM = SoundDevice.CreateMusicFromFile(_T("Fear_2.wav"));
	/*player.Initialize();
	camera.Init();*/
	map.Initialize();
	Main_x = 0.0f;
	Main2_x = Main_x + 1280.0f;
	Main3_x = Main2_x + 1280.0f;
	//enemy_manager.Initialize();
}
void Main_Scene::Update()
{

	Main_x = Main_x - 2.0f;
	Main2_x = Main2_x - 2.0f;
	Main3_x = Main3_x - 2.0f;
	if (Main_x < -1280) 
	{ 
		Main_x = Main3_x ;
	}
	if (Main2_x < -1280)
	{
		Main2_x = Main_x + 1280;
	}
	if (Main3_x < 0)
	{
		Main3_x = Main2_x + 1280;
	}
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
	/*player.Update();*/
	

	//enemy_manager.Update();//
}
void Main_Scene::Draw()
{
	SpriteBatch.Draw(*Main, Vector3(Main_x , 0, 0));
	SpriteBatch.Draw(*Main_Secoud, Vector3(Main2_x, 0, 0));
	SpriteBatch.Draw(*Main_Third, Vector3(Main3_x, 0, 0));
	//enemy_manager.Draw();
}
void Main_Scene::Draw3D() {
	/*player.Draw3D();
	camera.Draw3D();*/
	map.Draw();
}