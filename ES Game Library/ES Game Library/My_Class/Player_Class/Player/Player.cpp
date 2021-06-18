#include"Player.h"
#include"../../Map_Class/Map.h"
#include <cassert>
#include <algorithm>

Player::Player() {
	Charactor = nullptr;
}

void Player::Initialize()
{
	if(Charactor == nullptr)
	Charactor = GraphicsDevice.CreateModelFromFile(_T("Player/player_car.x"));

	//プレイヤー状態などの初期化
	Charactor_State();

	GraphicsDevice.SetRenderState(CullMode_None);

	Material material;
	material.Emissive = Color(1.0f, 1.0f, 1.0f);
	material.Diffuse   = Color(1.0f,1.0f,1.0f);
	material.Ambient   = Color(0.5f,0.5f,0.5f);
	material.Specular  = Color(1.0f,1.0f,1.0f);
	material.Power     = 10.0f;
	Charactor->SetMaterial(material);

	Charactor->SetPosition(CharactorInitPos);
	Charactor->SetScale(1.f);

	Charactor->Rotation(CharactorRotate);

	/*attck.Initialize();*/

}
void Player::Charactor_State()
{
	
}

void Player::Update()
{
	//操作キーなどの記述
	Player_Operation();
	//ジャンプなどの記述
	Charactor_Move();

	/*attck.Update();*/
	
}
void Player::Draw3D()
{
	Charactor->Draw();
	/*attck.Draw();*/
}


void Player::Charactor_Move()
{
	
	//活動制限(範囲)
	PlayerPosition.x = (PlayerPosition.x, 0.0f, 1280.0f - 63.0f);

	/*if (Character_x <= -60.0f)
	{
		Character_x = -60.0f;
	}
	if (Character_x >= 1280.0f)
	{
		Character_x = 0.0f;
	}
	if (Character_y >= 720.0f)
	{
		Character_y = 570.0f;
	}
	if (Character_y <= 0.0f)
	{
		Character_y <= 570.0f;
	}*/
}

void Player::Player_Operation()
{
	if (Input.GetKeybordInput(Keys_Right))
		Charactor->Move(-Speed, 0, 0);
	
	if (Input.GetKeybordInput(Keys_Left))
		Charactor->Move( Speed, 0, 0);
	
	// カーソルキーの↑を押していて、地面についていたらジャンプ
	/*if (Input.GetKeybordInput(Keys_Up))
		Charactor->Move(0, 0, -Speed);
		
	if (Input.GetKeybordInput(Keys_Down))
		Charactor->Move(0, 0, Speed);*/

	//スペースキーを押したら封印の御札発射
	if (Input.GetKeybordInputDown(Keys_Space))
	{

	}
 
	
	PlayerPosition = Charactor->GetPosition();
}

MODEL   Player::GetModel() {
	assert(Charactor && "Player::GetModel() - Charactor ptr nullptr");
	return Charactor;
}

Vector3 Player::GetPosition() {
	assert(PlayerPosition && "Player::GetPlayerPosition() - PlayerPosition ptr nullptr");
		return PlayerPosition;
}



	
	
	
	

