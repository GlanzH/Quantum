#pragma once
#include"../../../ESGLib.h"
#include"../PlayerShotManager/PlayerShotManager.h"
#include "../../Scene_Manegeer/BaseScene.h"

class PlayerShotManager;

class Player 
{
public:
	Player::Player();

	void Initialize();
    void Update();   
	void Draw();
	void Draw3D();    
	Vector3 GetPlayerPosition();

	MODEL   GetModel();
	//MODEL   GetCollision();

	static Player Instance() {
		Player instance;
		return instance;
	}

private:
	void Charactor_Move();     //移動状態
	void Charactor_State();    //プレイヤーの状態
	void Player_Operation();   //移動するためのキーボード操作

	MODEL Charactor;
	MODEL Collision;
	Vector3 PlayerPosition = Vector3_Zero;
	//Vector3 

	FONT font;

	const float Speed = 0.008f;

	const Vector3 CharactorInitPos = Vector3(0, 0, 0.2f);
	const Vector3 CharactorRotate  = Vector3(0.0f, 180.0f, 0.0f);

	enum {HALF = 2};
	const float material_power = 10.0f;
	PlayerShotManager _PlayerShotManager;
};
