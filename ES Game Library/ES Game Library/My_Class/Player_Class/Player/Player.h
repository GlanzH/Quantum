#pragma once
#include"../../../ESGLib.h"
#include"../PlayerShotManager/PlayerShotManager.h"
#include "../../Scene_Manegeer/BaseScene.h"

class PlayerShotManager;

class Player 
{
public:

	void Initialize();
    void Update();   
	void Draw();
	void Draw3D();    
	Vector3 GetPlayerPosition();

	MODEL   GetModel();
	//MODEL   GetCollision();

	static Player & Instance() 
	{
		static Player instance;
		return instance;
	}

private:
	Player::Player();

	void Charactor_Move();     //◆移動状態
	void Charactor_State();    //◆プレイヤーの状態
	void Player_Operation();   //◆移動するためのキーボード操作

	MODEL Charactor;
	MODEL Collision;
	Vector3 PlayerPosition = Vector3_Zero;

	//Vector3 

	FONT font;
	//◆LEFT:RIGHHT
	const float Speed_LR = 0.05f;
	//◆FRONT
	const float Speed_F = 0.25f;
	//◆BACK
	const float Speed_B = 0.09f;

	const Vector3 CharactorInitPos = Vector3(0, 0, 0.2f);
	const Vector3 CharactorRotate  = Vector3(0.0f, 180.0f, 0.0f);

	enum {HALF = 2};
	const float material_power = 10.0f;
	PlayerShotManager _PlayerShotManager;
};
