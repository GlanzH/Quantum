#include"Player.h"
#include <cassert>

Player::Player() {
	Character = nullptr;
}

void Player::Initialize()
{
	if(Character == nullptr)
	Character = GraphicsDevice.CreateModelFromFile(_T("Player/player_car.x"));

	//�v���C���[��ԂȂǂ̏�����
	Character_State();

	GraphicsDevice.SetRenderState(CullMode_None);

	Material material;
	material.Diffuse  = Color(1.0f,1.0f,1.0f);
	material.Ambient  = Color(1.0f,1.0f,1.0f);
	material.Specular = Color(1.0f,1.0f,1.0f);
	material.Power = 10.0f;
	Character->SetMaterial(material);

	Character->SetPosition(Vector3(0, 0, 0.2f));
	Character->SetScale(0.2f);

	Character->Rotation(0.0f, 180.0f, 0.0f);

	/*attck.Initialize();*/

}
void Player::Character_State()
{
	
}

void Player::Update()
{
	//����L�[�Ȃǂ̋L�q
	Player_Operation();
	//�W�����v�Ȃǂ̋L�q
	Character_Move();

	/*attck.Update();*/
	
}
void Player::Draw3D()
{
	/*const Vector3 player_position = Character->GetPosition();*/
	/*camera->SetLookAt(player_position - Character->GetFrontVector() * 15.0f + Vector3(0, 2, 0), player_position, Vector3_Up);*/
	/*GraphicsDevice.SetCamera(camera);*/



	Character->Draw();
	/*attck.Draw();*/
}


void Player::Character_Move()
{
	//�W�����v����
	//��������(�͈�)
	/*PlayerPosition.x = (PlayerPosition.x, 0.0f, 1280.0f - 63.0f);
	PlayerPosition.y = (PlayerPosition.y, 0.0f, 720.0f - 102.0f);*/
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
	//�J�[�\���L�[ ���� ����������ړ��ړ�
	if (Input.GetKeybordInput(Keys_Right))
	{
		Character->Move(-Speed, 0, 0);
	}
	if (Input.GetKeybordInput(Keys_Left))
	{
		Character->Move( Speed, 0, 0);
	}
	// �J�[�\���L�[�́��������Ă��āA�n�ʂɂ��Ă�����W�����v
	if (Input.GetKeybordInput(Keys_Up))
	{
		Character->Move(0, 0, -Speed);
		
	}
	if (Input.GetKeybordInput(Keys_Down))
	{
		Character->Move(0, 0, Speed);

	}
	//�X�y�[�X�L�[���������畕��̌�D����
	if (Input.GetKeybordInputDown(Keys_Space))
	{
	}
 
	PlayerPosition = Character->GetPosition();
}

MODEL   Player::GetModel() {
	assert(Character && "Player::GetModel() - Character ptr nullptr");
	return Character;
}

Vector3 Player::GetPosition() {
	assert(PlayerPosition && "Player::GetPlayerPosition() - PlayerPosition ptr nullptr");
		return PlayerPosition;
}

Vector3 Player::GetUpVector() {
	assert(UpVector && "layer::GetUpVector() - Character ptr nullptr");
	if(Character != nullptr)
	UpVector = Character->GetUpVector();
	return UpVector;
}


	
	
	
	

