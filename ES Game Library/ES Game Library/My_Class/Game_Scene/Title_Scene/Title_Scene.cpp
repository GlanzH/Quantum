#include "Title_Scene.h"
#include"../../Scene_Manegeer/SceneManager.h"

void Title_Scene::Initialize()
{
	TitleBG = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/Title.png"));
	Tachyon = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/Tachyon.png"));
	Particles = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/particles.png"));
	Letter = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Title_Material/start.png"));
	Blinking= ZERO;
	CharacterMove = ZERO;

	SceneManager::Instance().SetScore(ZERO);

	InputDevice.CreateGamePad(4);
	
}
void Title_Scene::Update()
{ 
	CharacterMove += MOVE;
	if (CharacterMove >= APPEARANCE)
	{ 
		CharacterMove = APPEARANCE;   Blinking += Speed;
	}

	GamePadState pad = GamePad(0)->GetState();
	GamePadBuffer pad_buffer = GamePad(0)->GetBuffer();
	if (Input.GetKeybordInputDown(Keys_Enter)/*||Input.GetPadInputDown(GamePad_Button2)*/)
	{
			SceneManager::Instance().ChangeScene(SceneManager::SCENE::MAIN);
	}
	
}
void Title_Scene::Draw()
{
	SpriteBatch.Draw(*TitleBG,Vector3_Zero);
	SpriteBatch.Draw(*Tachyon,   Vector3 (-APPEARANCE + CharacterMove , Y_POS, ZERO));
	SpriteBatch.Draw(*Particles, Vector3(  APPEARANCE - CharacterMove, Y_POS, ZERO));

	SpriteBatch.Draw(*Letter,    Vector3(ZERO, Y_POS, ZERO),Blinking);
}