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
	//◆クラス
	//-----------------------------------------------------------------
	Player::Player();

	void Initialize(); //Playerの初期化のクラス
	void Update();     //Playerの更新のクラス
	void Draw3D();       //Playerの描画のクラス
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
	//◆変数
	//-----------------------------------------------------------------
	void Charactor_Move();     //移動状態
	void Charactor_State();    //プレイヤーの状態
	void Player_Operation();   //移動するためのキーボード操作

	MODEL Charactor;
	MODEL Collision;
	Vector3 PlayerPosition;
	Vector3 UpVector;

	const float Speed = 0.008f;

	const Vector3 CharactorInitPos = Vector3(0, 0, 0.2f);
	const Vector3 CharactorRotate  = Vector3(0.0f, 180.0f, 0.0f);
	/*CAMERA camera;*/
	//FONT DefaultFont;
	//Player_Attck attck;//Player_Attckクラスへのアクセス
};
