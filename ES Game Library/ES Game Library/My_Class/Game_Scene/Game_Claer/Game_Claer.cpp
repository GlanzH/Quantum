#include "Game_Claer.h"
#include"../../Scene_Manegeer/SceneManager.h"

void Game_Claer::Initialize()
{
	CLAER = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/GameClare_Material/geme crear.png"));
	Push = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/GameClare_Material/Push.png"));
	Blinking = 0;
}
void Game_Claer::Update()
{
	Blinking += 0.01f;
	if (Input.GetKeybordInputDown(Keys_Enter))
	{
		SceneManager::ChangeScene(SceneManager::SCENE::RESULT);
	}
}
void Game_Claer::Draw()
{
	SpriteBatch.Draw(*CLAER, Vector3(0, 0, 0));
	SpriteBatch.Draw(*Push, Vector3(-400, -100, 0),Blinking);
}
