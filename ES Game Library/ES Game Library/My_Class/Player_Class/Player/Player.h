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

	//-----------------------------------------------------------------
	//���N���X
	//-----------------------------------------------------------------
	Player::Player();

	void Initialize(); //Player�̏������̃N���X
	void Update();     //Player�̍X�V�̃N���X
	void Draw3D();       //Player�̕`��̃N���X
	Vector3 GetPosition();
	MODEL   GetModel();
	Vector3 GetUpVector();
	//MODEL   GetCollision();

	static Player& Instance() {
		static Player instance;
		return instance;
	}

private:
	//-----------------------------------------------------------------
	//���ϐ�
	//-----------------------------------------------------------------
	void Charactor_Move();     //�ړ����
	void Charactor_State();    //�v���C���[�̏��
	void Player_Operation();   //�ړ����邽�߂̃L�[�{�[�h����

	MODEL Charactor;
	MODEL Collision;
	Vector3 PlayerPosition;
	Vector3 UpVector;

	const float Speed = 0.008f;

	const Vector3 CharactorInitPos = Vector3(0, 0, 0.2f);
	const Vector3 CharactorRotate  = Vector3(0.0f, 180.0f, 0.0f);
	/*CAMERA camera;*/
	//FONT DefaultFont;
	//Player_Attck attck;//Player_Attck�N���X�ւ̃A�N�Z�X
};
