#pragma once
#include"../../Scene_Manegeer/SceneManager.h"

class Result_Scene : public BaseScene
{
public:
	Result_Scene() {};
	virtual ~Result_Scene() {};

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;

	virtual void DrawEnd() {};
private:
	SPRITE BG;//背景
	SPRITE RESULT;//リザルト文字
	SPRITE Push;//Pushボタン
	SPRITE Fast;//1位のボタン
	SPRITE Second;//2位のボタン
	SPRITE Third;//3位のボタン
	FONT font;
	short int image_x;//
	short int numbers_x;//
	short int image_y;//
	short int numbers_y;//
	short int image_z;//
	short int number;//
	short int font_number;//
	unsigned short int ranking_score[3];//
	float Blinking;//点滅
};