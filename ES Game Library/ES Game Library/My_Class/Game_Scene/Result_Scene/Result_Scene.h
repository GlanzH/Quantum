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
	SPRITE BG;//�w�i
	SPRITE RESULT;//���U���g����
	SPRITE Push;//Push�{�^��
	SPRITE Fast;//1�ʂ̃{�^��
	SPRITE Second;//2�ʂ̃{�^��
	SPRITE Third;//3�ʂ̃{�^��
	FONT font;
	short int image_x;//
	short int numbers_x;//
	short int image_y;//
	short int numbers_y;//
	short int image_z;//
	short int number;//
	short int font_number;//
	unsigned short int ranking_score[3];//
	float Blinking;//�_��
};