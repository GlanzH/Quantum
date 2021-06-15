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

	cameraPos = 60.0f;

	camera->SetPerspectiveFieldOfView(cameraPos, 16.0f / 9.0f, 0.1f, 100.0f);

	camera->SetPosition(Player::Instance().GetPlayerPosition() - Vector3(0,0,-10));

	GraphicsDevice.SetLight(light);
	GraphicsDevice.SetCamera(camera);
}

void PlayerCamera::Draw3D()
{
	GraphicsDevice.SetCamera(camera);
}
