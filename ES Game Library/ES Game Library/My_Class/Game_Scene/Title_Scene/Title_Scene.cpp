#include "Title_Scene.h"
#include"../../Scene_Manegeer/SceneManager.h"

void Title_Scene::Initialize()
{
	Title_BG = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/Title.png"));
	Letter = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/start.png"));
	
	 Blinking= 0;
}
void Title_Scene::Update()
{ 
	Blinking += 0.01;
	
	if (Input.GetKeybordInputDown(Keys_Enter))
	{
			SceneManager::ChangeScene(SceneManager::SCENE::MAIN);
	}
	
}
void Title_Scene::Draw()
{
	SpriteBatch.Draw(*Title_BG, Vector3(0, 0, 0));
	SpriteBatch.Draw(*Letter, Vector3(0, -50, 0),Blinking);
}