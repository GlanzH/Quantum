#include "Title_Scene.h"
#include"../../Scene_Manegeer/SceneManager.h"

void Title_Scene::Initialize()
{
	Title_BG = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/Title.png"));
	Tachyon = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/Tachyon.png"));
	particles = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/particles.png"));
	Letter = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/start.png"));
	Blinking= Zero;
	character_move = Zero;
	InputDevice.CreateGamePad(4);
	
}
void Title_Scene::Update()
{ 
	character_move += MOVE;
	if (character_move >= APPEARANCE)
	{ 
		character_move = APPEARANCE;   Blinking += 0.01;
	}

	GamePadState pad = GamePad(0)->GetState();
	GamePadBuffer pad_buffer = GamePad(0)->GetBuffer();
	if (Input.GetKeybordInputDown(Keys_Enter)/*||Input.GetPadInputDown(GamePad_Button2)*/)
	{
			SceneManager::ChangeScene(SceneManager::SCENE::MAIN);
	}
	
}
void Title_Scene::Draw()
{
	SpriteBatch.Draw(*Title_BG,Vector3_Zero);
	SpriteBatch.Draw(*Tachyon, Vector3(-APPEARANCE + character_move , Y_POS, Zero));
	SpriteBatch.Draw(*particles, Vector3(APPEARANCE - character_move, Y_POS, Zero));
	SpriteBatch.Draw(*Letter, Vector3(Zero, Y_POS, Zero),Blinking);
}