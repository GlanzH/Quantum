#include "Game_Over.h"
#include"../../Scene_Manegeer/SceneManager.h"

void Game_Over::Initialize()
{
	OVER = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/GameOver_Material/gameover.png"));
	Push = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/GameOver_Material/Push.png"));
	Blinking = 0;
}
void Game_Over::Update()
{
	Blinking += 0.01f;
	if (Input.GetKeybordInputDown(Keys_Enter))
	{
		SceneManager::ChangeScene(SceneManager::SCENE::TITLE);
	}
}
void Game_Over::Draw()
{
	SpriteBatch.Draw(*OVER, Vector3(0, 0, 0));
	SpriteBatch.Draw(*Push, Vector3(-400, -100, 0), Blinking);
}