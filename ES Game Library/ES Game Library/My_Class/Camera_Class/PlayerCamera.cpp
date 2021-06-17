#include"PlayerCamera.h"

void PlayerCamera::Init()
{
	Color color = (0.5f, 0.5f, 0.5f);

	light.Type = Light_Directional;
	light.Direction = Vector3_Down + Vector3_Forward;
	light.Diffuse = color;
	light.Ambient = color;
	light.Specular = color;
	light.Position = light_pos;

	camera_pos = CAMERA_POS;

	camera->SetView(Vector3_Zero, Vector3_Zero);
	camera->SetPerspectiveFieldOfView(camera_pos, 16.0f / 9.0f, 0.1f, 100.0f);
	//camera->SetRotation(camera_rotate);
	//camera->SetPosition(camera_init_pos);

	GraphicsDevice.SetLight(light);
	GraphicsDevice.SetCamera(camera);
}

void PlayerCamera::Draw3D()
{
	const Vector3 player_pos = Player::Instance().GetPlayerPosition();


	camera->SetLookAt(player_pos + Vector3_Backward + camera_y, player_pos + camera_z, Vector3_Up);
	GraphicsDevice.SetCamera(camera);
}
