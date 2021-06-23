#include"Player.h"
#include <cassert>
#include <algorithm>

Player::Player() {

}

void Player::Initialize()
{
	Charactor = GraphicsDevice.CreateModelFromFile(_T("Player/player_car.x"));
	font = GraphicsDevice.CreateSpriteFont(_T("游明朝"), 30);

	//プレイヤー状態などの初期化
	Charactor_State();

	GraphicsDevice.SetRenderState(CullMode_None);

	Material material;
	material.Emissive  = Color(Vector3_One);
	material.Diffuse   = Color(Vector3_One);
	material.Ambient   = Color(Vector3_One / half);
	material.Specular  = Color(Vector3_One);
	material.Power     = MaterialPower;

	Charactor->SetMaterial(material);

	Charactor->SetPosition(CharactorInitPos);
	Charactor->SetScale(ModelScele);

	Charactor->Rotation(CharactorRotate);

	SimpleShape shape;
	shape.Type   = Shape_Box;
	shape.Width  = 1;
	shape.Depth  = 1;
	shape.Height = 1;
	
	Collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	Collision->SetMaterial(material);
	Collision->SetScale(CollisionScale);

	_PlayerShotManager.Initialize();
}

void Player::Charactor_State()
{

}

void Player::Update()
{
	PlayerPosition = Charactor->GetPosition();
	GetPlayerPosition();

	//操作キーなどの記述
	Player_Operation();
	//ジャンプなどの記述
	//Charactor_Move();

	GetPlayerPosition();

	Collision->SetPosition(Charactor->GetPosition() + Vector3(0,0.06f,0));

	_PlayerShotManager.Update();
		
}

void Player::Draw3D()
{
	Charactor->Draw();
	//Collision->Draw();
	_PlayerShotManager.Draw3D();
}


void Player::Charactor_Move()
{
	//ジャンプ処理
	//活動制限(範囲)
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
		
	if (Input.GetKeybordInput(Keys_Up))
	{
		Charactor->Move(0, 0, -Speed_F+ -Speed_B);
	}

	if (Input.GetKeybordInput(Keys_Down))
		Charactor->Move(0, 0, +Speed_F);
	
	if (Input.GetKeybordInputDown(Keys_Space))
		_PlayerShotManager.Shot(GetPlayerPosition());


	
}

void Player::Draw() {
	SpriteBatch.DrawString(font, Vector2(300,0), Color_White, _T("x: %.02f"),   GetPlayerPosition().x);
	SpriteBatch.DrawString(font, Vector2(300,50), Color_White, _T("y: %.02f"),  GetPlayerPosition().y);
	SpriteBatch.DrawString(font, Vector2(300,100), Color_White, _T("z: %.02f"), GetPlayerPosition().z);
}

MODEL Player::GetCollision() {
	assert(Collision && "Player::GetCollision() - Collision ptr nullptr");
	return Collision;
}
	
	
	

