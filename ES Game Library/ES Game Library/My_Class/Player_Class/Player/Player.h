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
	//◆クラス
	//-----------------------------------------------------------------
	virtual void Initialize(); //Playerの初期化のクラス
	virtual void Update();     //Playerの更新のクラス
	virtual void Draw3D();       //Playerの描画のクラス
	Vector3 GetPlayerPosition() { return PlayerPosition; }
private:
	//-----------------------------------------------------------------
	//◆変数
	//-----------------------------------------------------------------
	void Character_State();    //プレイヤーの状態
	void Character_Move();     //移動状態
	void Player_Operation();   //移動するためのキーボード操作

	MODEL Character;//キャラクターのモデル
	Vector3 PlayerPosition;//キャラクターの座標
	const float speed = 0.002f;//速度の固定化
	/*CAMERA camera;*/
	//FONT DefaultFont;
	//Player_Attck attck;//Player_Attckクラスへのアクセス
};
