#include "Result_Scene.h"
#include "../../Scene_Manegeer/SceneManager.h"
#include <algorithm>
#include <fstream>


void Result_Scene::Initialize()
{
	//画像データ
	bg     = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/resultbackground.png"));
	result = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/result.png"));
	first  = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/1st.png"));
	second = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/2nd.png"));
	third  = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/3rd.png"));
	push   = GraphicsDevice.CreateSpriteFromFile(_T("GameSceneMaterial/Result_Material/Push.png"));

	//!ファイルをダウンロードさせず、プログラムで読み込みフォント作成
	AddFontResourceEx(_T("font/digitalism/digitalism.ttf"), FR_PRIVATE, nullptr);
	font   = GraphicsDevice.CreateSpriteFont(_T("digitalism"), font_size);

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
	outfile << ranking_score[FIRST] << " " << ranking_score[SECOND] << " " << ranking_score[THIRD];
	//ランキングファイル読み込み
	std::ifstream infile("score.dat");
	infile >> ranking_score[FIRST] >> ranking_score[SECOND] >> ranking_score[THIRD];
}
void Result_Scene::Update()
{
	blinking += speed;
	if (Input.GetKeybordInputDown(Keys_Enter))
	{
		SceneManager::Instance().ChangeScene(SceneManager::SCENE::TITLE);
	}
}
void Result_Scene::Draw()
{
	SpriteBatch.Draw(*bg,Vector3_Zero);

	SpriteBatch.Draw(*result, Vector3(0, 0, image_pos.z));

	SpriteBatch.Draw(*first,  Vector3(image_pos.x, image_pos.y + SCORE_FIRST , image_pos.z));
	SpriteBatch.Draw(*second, Vector3(image_pos.x, image_pos.y + SCORE_SECOND, image_pos.z));
	SpriteBatch.Draw(*third,  Vector3(image_pos.x, image_pos.y + SCORE_THIRD , image_pos.z));

	SpriteBatch.Draw(*push,   Vector3(push_pos), blinking);

    SpriteBatch.DrawString(font, Vector2(font_pos.x, font_pos.y + SCORE_FIRST),  Color(219, 180, 0),   _T("%d"), ranking_score[FIRST]);
    SpriteBatch.DrawString(font, Vector2(font_pos.x, font_pos.y + SCORE_SECOND), Color(185, 195, 201), _T("%d"), ranking_score[SECOND]);
    SpriteBatch.DrawString(font, Vector2(font_pos.x, font_pos.y + SCORE_THIRD),  Color(184, 115, 51),  _T("%d"), ranking_score[THIRD]);
}



