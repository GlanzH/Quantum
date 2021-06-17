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
	void Character_State();    //プレイヤーの状態
	void Character_Move();     //移動状態
	void Player_Operation();   //移動するためのキーボード操作

	MODEL Character;//キャラクターのモデル
	MODEL Collision;
	Vector3 PlayerPosition;//キャラクターの座標
	Vector3 UpVector;
	const float Speed = 0.002f;//速度の固定化
	/*CAMERA camera;*/
	//FONT DefaultFont;
	//Player_Attck attck;//Player_Attckクラスへのアクセス
};
