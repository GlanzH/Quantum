#include"Player.h"


void Player::Initialize()
{
	//キャラクター描画
	Character = GraphicsDevice.CreateModelFromFile(_T("Player/player_car.x"));
	
	//プレイヤー状態などの初期化
	Character_State();
//------------------------------------------------------------
	GraphicsDevice.SetRenderState(CullMode_None);

	/*camera->SetView(Vector3(30, 10, 110), Vector3(0, 0, 0));
	camera->SetPerspectiveFieldOfView(45.0f, 16.0f / 9.0f, 1.0f, 10000.0f);*/

	/*GraphicsDevice.SetCamera(camera);*/
	Material material;
	material.Diffuse = Color(Vector3_One);
	material.Ambient = Color(Vector3_One);
	material.Specular = Color(Vector3_One);
	material.Power = 10.0f;
	Character->SetMaterial(material);

	Character->SetPosition(Vector3(0, 0, 0.2f));
	Character->SetScale(0.1f);

	Character->Rotation(0.0f, 180.0f, 0.0f);

	

	/*Light light;
	light.Type = Light_Directional;
	light.Direction = Vector3(0.0f, -1.0f, 1.0f);
	light.Diffuse = Color(1.0f, 1.0f, 1.0f);
	light.Ambient = Color(5.0f, 5.0f, 5.0f);
	light.Specular = Color(1.0f, 1.0f, 1.0f);
	GraphicsDevice.SetLight(light);*/

	/*camera->GetRightVector();*/

	//camera->GetFrontVector();
	//座標の指定の仕方

	/*Vector3(30, 0, 130);
	camera->GetPosition();
	camera->GetPosition() + Vector3(30, 0, 130);*/




	/*attck.Initialize();*/

}
void Player::Character_State()
{
	
}

void Player::Update()
{
	//操作キーなどの記述
	Player_Operation();
	//ジャンプなどの記述
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
	//カーソルキー ←→ を押したら移動移動
	if (Input.GetKeybordInput(Keys_Right))
	{
		Character->Move(-speed, 0, 0);
	}
	if (Input.GetKeybordInput(Keys_Left))
	{
		Character->Move( speed, 0, 0);
	}
	// カーソルキーの↑を押していて、地面についていたらジャンプ
	if (Input.GetKeybordInput(Keys_Up))
	{
		Character->Move(0, 0, -speed);
		
	}
	//スペースキーを押したら封印の御札発射
	if (Input.GetKeybordInputDown(Keys_Space))
	{
	}
 
	PlayerPosition = Character->GetPosition();
}

    
	
	
	
	

