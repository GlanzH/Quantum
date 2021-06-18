#include "PlayerShot.h"

void PlayerShot::Initialize() {
	shot = GraphicsDevice.CreateModelFromFile(_T("Player/ball/blue.X"));

	Material material;
	material.Emissive = Color(Vector3_One);
	material.Diffuse  = Color(Vector3_One);
	material.Ambient  = Color(Vector3_One / HALF);
	material.Specular = Color(Vector3_One);
	material.Power    = material_power;
	
	shot->SetMaterial(material);
	shot->SetScale(0.25f);
	
}

void PlayerShot::Update() {
	
	if (shot_flag)
	{
		shot_pos.z += speed;
	}
	if (shot_pos.z <= shot_erace_pos)
	{
		shot_flag = false;
	}

	shot->SetPosition(shot_pos);
	shot_pos = shot->GetPosition();
}

void PlayerShot::Draw3D() 
{
	
	if(shot_flag)
	shot->Draw();

}

void PlayerShot::Shot(Vector3 pos) 
{

		shot_flag = true;	
 		shot_pos = pos;

		
}