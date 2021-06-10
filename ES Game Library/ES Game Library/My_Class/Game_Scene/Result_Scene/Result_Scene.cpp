#include "Result_Scene.h"
#include "../../Scene_Manegeer/SceneManager.h"
#include <algorithm>
#include <fstream>


void Result_Scene::Initialize()
{
	//画像データ
	BG = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/resultbackground.png"));
	RESULT = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/result.png"));
	Fast = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/1st.png"));
	Second = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/2nd.png"));
	Third = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/3rd.png"));
	Push = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/Push.png"));
	font = GraphicsDevice.CreateSpriteFont(_T("digitalism"), 110);
	//変数初期化
	Blinking = 0.0f;
	number = 100;
	image_x = 200;
	numbers_x = 400;
	image_y = 200;
	numbers_y = 400 ;
	image_z = -1;
	font_number = 600;
	//ランキング入れ替え
	/*if (CUI::total > ranking_score[2]) {
		int work = ranking_score[2];
		ranking_score[2] = CUI::total;
	}

	if (ranking_score[2] > ranking_score[1]) {
		int work = ranking_score[1];
		ranking_score[1] = ranking_score[2];
		ranking_score[2] = work;
	}
	if (ranking_score[1] > ranking_score[0]) {
		int work = ranking_score[0];
		ranking_score[0] = ranking_score[1];
		ranking_score[1] = work;
	}*/
	//ランキング保存
	std::ofstream outfile("score.dat");
	outfile << ranking_score[0] << " " << ranking_score[1] << " " << ranking_score[2];
	//ランキングファイル読み込み
	std::ifstream infile("score.dat");
	infile >> ranking_score[0] >> ranking_score[1] >> ranking_score[2];
}
void Result_Scene::Update()
{
	Blinking += 0.01f;
	if (Input.GetKeybordInputDown(Keys_Enter))
	{
		SceneManager::ChangeScene(SceneManager::SCENE::TITLE);
	}
}
void Result_Scene::Draw()
{
	SpriteBatch.Draw(*BG,     Vector3(0, 0, 0));
	SpriteBatch.Draw(*RESULT, Vector3(0, 0, image_z));
	SpriteBatch.Draw(*Fast,   Vector3(image_x, image_y, image_z));
	SpriteBatch.Draw(*Second, Vector3(image_x, image_y + number, image_z));
	SpriteBatch.Draw(*Third,  Vector3(image_x, numbers_y, image_z));
	SpriteBatch.Draw(*Push,   Vector3(-numbers_x, -number, image_z), Blinking);
    SpriteBatch.DrawString(font, Vector2(font_number, image_y), Color(219, 180, 0), _T("%d"), ranking_score[0]);
    SpriteBatch.DrawString(font, Vector2(font_number, image_y + number), Color(185, 195, 201), _T("%d"), ranking_score[1]);
    SpriteBatch.DrawString(font, Vector2(font_number, numbers_y), Color(184, 115, 51), _T("%d"), ranking_score[2]);
}



