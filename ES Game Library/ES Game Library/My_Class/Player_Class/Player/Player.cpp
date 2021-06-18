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

	//�v���C���[��ԂȂǂ̏�����
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
	//����L�[�Ȃǂ̋L�q
	Player_Operation();
	//�W�����v�Ȃǂ̋L�q
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
	
	//��������(�͈�)
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
	
	// �J�[�\���L�[�́��������Ă��āA�n�ʂɂ��Ă�����W�����v
	/*if (Input.GetKeybordInput(Keys_Up))
		Charactor->Move(0, 0, -Speed);
		
	if (Input.GetKeybordInput(Keys_Down))
		Charactor->Move(0, 0, Speed);*/

	//�X�y�[�X�L�[���������畕��̌�D����
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



	
	
	
	

