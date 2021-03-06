#include "Main_Scene.h"

Main_Scene::Main_Scene() {
}

Main_Scene::~Main_Scene(){
}

void Main_Scene::Initialize()
{
	bg = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/MainScene_Material/Red.png"));
	
	Player::Instance().Initialize();
	camera.Init();
	map.Initialize();
	enemymanager.Initialize();
	ui.Initialize();
}
void Main_Scene::Update()
{
	Player::Instance().Update();
	map.Update();
	enemymanager.Update();
	ui.Update();

	if (Input.GetKeybordInputDown(Keys_Enter))
	{
		SceneManager::Instance().ChangeScene(SceneManager::SCENE::CLEAR_SCENE);
		//return;
	}
	if (ui.gameover_flg == true)
	{
		SceneManager::Instance().ChangeScene(SceneManager::SCENE::OVER_SCENE);
		//return;
	}
}
void Main_Scene::Draw()
{
	//enemy_manager.Draw();
	SpriteBatch.Draw(*bg,bg_pos);
	ui.Draw();
	
}
void Main_Scene::Draw3D() 
{
	Player::Instance().Draw3D();
	camera.Draw3D();
	map.Draw3D();
	enemymanager.Draw3D();
}