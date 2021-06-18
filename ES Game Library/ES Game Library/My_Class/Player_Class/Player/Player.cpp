#include"Player.h"
#include <cassert>
#include <algorithm>

Player::Player() {

}

void Player::Initialize()
{
	Charactor = GraphicsDevice.CreateModelFromFile(_T("Player/player_car.x"));
	font = GraphicsDevice.CreateSpriteFont(_T("������"), 30);

	//�v���C���[��ԂȂǂ̏�����
	Charactor_State();

	GraphicsDevice.SetRenderState(CullMode_None);

	Material material;
	material.Emissive  = Color(Vector3_One);
	material.Diffuse   = Color(Vector3_One);
	material.Ambient   = Color(Vector3_One / HALF);
	material.Specular  = Color(Vector3_One);
	material.Power     = material_power;
	Charactor->SetMaterial(material);

	Charactor->SetPosition(CharactorInitPos);
	Charactor->SetScale(1.f);

	Charactor->Rotation(CharactorRotate);

	_PlayerShotManager.Initialize();
}

void Player::Charactor_State()
{
	
}

void Player::Update()
{
	PlayerPosition = Charactor->GetPosition();
	GetPlayerPosition();

	//����L�[�Ȃǂ̋L�q
	Player_Operation();
	//�W�����v�Ȃǂ̋L�q
	Charactor_Move();

	GetPlayerPosition();

	_PlayerShotManager.Update();
		
}

void Player::Draw3D()
{
	Charactor->Draw();
	_PlayerShotManager.Draw3D();
}


void Player::Charactor_Move()
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
	Charactor->Move(0, 0,  -Speed_F);


	if (Input.GetKeybordInput(Keys_Right))
		Charactor->Move(-Speed_LR, 0, 0);
	
	if (Input.GetKeybordInput(Keys_Left))
		Charactor->Move(Speed_LR, 0, 0);
		
	if (Input.GetKeybordInput(Keys_Down))
		Charactor->Move(0, 0, Speed_B);


	if (Input.GetKeybordInput(Keys_Space))
		_PlayerShotManager.Shot(GetPlayerPosition());

}

void Player::Draw() {
	SpriteBatch.DrawString(font, Vector2(300,0), Color_White, _T("x: %.02f"),   GetPlayerPosition().x);
	SpriteBatch.DrawString(font, Vector2(300,50), Color_White, _T("y: %.02f"),  GetPlayerPosition().y);
	SpriteBatch.DrawString(font, Vector2(300,100), Color_White, _T("z: %.02f"), GetPlayerPosition().z);
}

MODEL Player::GetModel() {
	assert(Charactor && "Player::GetModel() -Charactor ptr nullptr");
	return Charactor;
}


Vector3 Player::GetPlayerPosition() {
	assert(PlayerPosition && "Player::GetPlayerPosition() - PlayerPosition ptr nullptr");
		return PlayerPosition;
}
	
	
	

