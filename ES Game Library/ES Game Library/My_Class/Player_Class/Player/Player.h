#pragma once
#include"../../../ESGLib.h"
#include "../../Scene_Manegeer/BaseScene.h"
#include"../../Map_Class/Map.h"
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


	const float Speed = 0.025f;

	const Vector3 CharactorInitPos = Vector3(0, 0, 0.2f);
	const Vector3 CharactorRotate  = Vector3(0.0f, 180.0f, 0.0f);
	/*CAMERA camera;*/
	//FONT DefaultFont;
	//Player_Attck attck;//Player_Attck�N���X�ւ̃A�N�Z�X
};
