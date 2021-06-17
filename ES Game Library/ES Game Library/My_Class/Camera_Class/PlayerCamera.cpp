#include"PlayerCamera.h"

void PlayerCamera::Init()
{

	Color color = (0.5f, 0.5f, 0.5f);

	light.Type = Light_Directional;
	light.Direction = Vector3_Down + Vector3_Forward;
	light.Diffuse = color;
	light.Ambient = color;
	light.Specular = color;
	light.Position = Vector3(0, 10, 0);

	cameraPos = CAMERA_POS;

	camera->SetView(Vector3_Zero, Vector3_Zero);
	camera->SetPerspectiveFieldOfView(cameraPos, 16.0f / 9.0f, 0.1f, 100.0f);
	camera->SetRotation(5.0f, 0.0f, 0.0f);
	camera->SetPosition(0, 0.04f, 0);
	GraphicsDevice.SetLight(light);
	GraphicsDevice.SetCamera(camera);
}

//void PlayerCamera::Update() {
//	//if (Input.GetKeybordInput(Keys_Right))
//	//	camera->Move(-speed, 0, 0);
//
//	//if (Input.GetKeybordInput(Keys_Left))
//	//	camera->Move(speed, 0, 0);
//
//	//GraphicsDevice.SetCamera(camera);
//}

void PlayerCamera::Draw3D()
{
	auto player_pos    = Player::Instance().GetPosition();
	auto player_up_vec = Player::Instance().GetUpVector();

	camera->SetLookAt(player_pos + Vector3_Backward + Vector3(0.0f, 0.1f, -0.5f), player_pos + player_up_vec, Vector3_Up);
	GraphicsDevice.SetCamera(camera);
}
