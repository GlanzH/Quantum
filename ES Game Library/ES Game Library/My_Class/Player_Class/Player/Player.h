#pragma once
#include"../../../ESGLib.h"
//#include"../Player_Attck/Player_Attck.h"
#include "../../Scene_Manegeer/BaseScene.h"
//#include"../../Mediator_Class/Mediator/Mediator.h"

class Player 
{
//private:
//	CollisionMediator* m_Mediator;
public:
	
public:
	//-----------------------------------------------------------------
	//���N���X
	//-----------------------------------------------------------------
	virtual void Initialize(); //Player�̏������̃N���X
	virtual void Update();     //Player�̍X�V�̃N���X
	virtual void Draw3D();       //Player�̕`��̃N���X
	Vector3 GetPlayerPosition() { return PlayerPosition; }
private:
	//-----------------------------------------------------------------
	//���ϐ�
	//-----------------------------------------------------------------
	void Character_State();    //�v���C���[�̏��
	void Character_Move();     //�ړ����
	void Player_Operation();   //�ړ����邽�߂̃L�[�{�[�h����

	MODEL Character;//�L�����N�^�[�̃��f��
	Vector3 PlayerPosition;//�L�����N�^�[�̍��W
	const float speed = 0.002f;//���x�̌Œ艻
	/*CAMERA camera;*/
	//FONT DefaultFont;
	//Player_Attck attck;//Player_Attck�N���X�ւ̃A�N�Z�X
};
