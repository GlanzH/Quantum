#include "Game_Clear.h"
#include"../../Scene_Manegeer/SceneManager.h"

void Game_Clear::Initialize()
{
	Clear = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/GameClare_Material/geme crear.png"));
	Push  = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/GameClare_Material/Push.png"));
	Blinking = 0;
}
void Game_Clear::Update()
{
	Blinking += speed;
	if (Input.GetKeybordInputDown(Keys_Enter))
	{
		SceneManager::Instance().ChangeScene(SceneManager::SCENE::RESULT);
	}
}
void Game_Clear::Draw()
{
	SpriteBatch.Draw(*Clear,Vector3_Zero);
	SpriteBatch.Draw(*Push, PushPos,Blinking);
}
