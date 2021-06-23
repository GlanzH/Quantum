#pragma once
#include"../../Scene_Manegeer/SceneManager.h"

class Result_Scene : public BaseScene
{
public:
	Result_Scene() {};
	virtual ~Result_Scene() {};

	virtual void Initialize() override;
	virtual void Update()     override;
	virtual void Draw()       override;
	virtual void Draw3D() {};

	virtual void DrawEnd() {};
private:
	SPRITE bg;     //背景
	SPRITE result; //リザルト文字
	SPRITE push;   //Pushボタン
	SPRITE first;   //1位のボタン
	SPRITE second; //2位のボタン
	SPRITE third;  //3位のボタン
	FONT font;

	//!順位
	enum Rank {
		FIRST,
		SECOND,
		THIRD,
		NUM
	};

	//!スコア表示座標計算用
	enum ScoreCalculate {
		SCORE_FIRST  = 0,
		SCORE_SECOND = 150,
		SCORE_THIRD  = 300
	};

	//!フォントサイズ
	const int font_size = 110;

	//!PUSH画像の座標
	const Vector3 push_pos = Vector3(-400,0,-1);

	//!順位画像の初期座標
	Vector3 image_pos = Vector3(200,170,-1);

	//!スコア初期座標
	Vector2 font_pos  = Vector2(600, 200);

	int ranking_score[NUM]; 
	float blinking = 0.0f;      //点滅用
	const float speed = 0.01f;  //点滅スピード
};