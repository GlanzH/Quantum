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
	SPRITE bg;     //�w�i
	SPRITE result; //���U���g����
	SPRITE push;   //Push�{�^��
	SPRITE first;   //1�ʂ̃{�^��
	SPRITE second; //2�ʂ̃{�^��
	SPRITE third;  //3�ʂ̃{�^��
	FONT font;

	//!����
	enum Rank {
		FIRST,
		SECOND,
		THIRD,
		NUM
	};

	//!�X�R�A�\�����W�v�Z�p
	enum ScoreCalculate {
		SCORE_FIRST  = 0,
		SCORE_SECOND = 150,
		SCORE_THIRD  = 300
	};

	//!�t�H���g�T�C�Y
	const int font_size = 110;

	//!PUSH�摜�̍��W
	const Vector3 push_pos = Vector3(-400,0,-1);

	//!���ʉ摜�̏������W
	Vector3 image_pos = Vector3(200,170,-1);

	//!�X�R�A�������W
	Vector2 font_pos  = Vector2(600, 200);

	int ranking_score[NUM]; 
	float blinking = 0.0f;      //�_�ŗp
	const float speed = 0.01f;  //�_�ŃX�s�[�h
};