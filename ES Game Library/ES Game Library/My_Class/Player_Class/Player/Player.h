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
	//◆クラス
	//-----------------------------------------------------------------
	Player::Player();

	void Initialize(); //Playerの初期化のクラス
	void Update();     //Playerの更新のクラス
	void Draw3D();       //Playerの描画のクラス
	Vector3 GetPosition();
	MODEL   GetModel();
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


	const float Speed = 0.025f;

	const Vector3 CharactorInitPos = Vector3(0, 0, 0.2f);
	const Vector3 CharactorRotate  = Vector3(0.0f, 180.0f, 0.0f);
	/*CAMERA camera;*/
	//FONT DefaultFont;
	//Player_Attck attck;//Player_Attckクラスへのアクセス
};
