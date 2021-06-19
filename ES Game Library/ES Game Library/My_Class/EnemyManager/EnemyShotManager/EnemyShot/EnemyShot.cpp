#include "EnemyShot.h"

void EnemyShot::Initialize() {
	shot = GraphicsDevice.CreateModelFromFile(_T("Player/ball/red.X"));

	Material material;
	material.Emissive = Color(Vector3_One);
	material.Diffuse  = Color(Vector3_One);
	material.Ambient  = Color(Vector3_One / HALF);
	material.Specular = Color(Vector3_One);
	material.Power    = material_power;
	
	shot->SetMaterial(material);
	shot->SetScale(0.25f);

	SimpleShape shape;
	shape.Type = Shape_Box;
	shape.Width = 1;
	shape.Depth = 1;
	shape.Height = 1;

	collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	collision->SetScale(0.1f);
	collision->SetMaterial(material);
	collision->SetPosition(shot_pos);
}

void EnemyShot::Update() {
	if (shot_flag)
		shot_pos.z += speed;
	
	if (frame < MAX_COUNT && shot_flag)
		frame++;
	else {
		shot_flag = false;
		frame = MIN_COUNT;
	}


	shot->SetPosition(shot_pos);
	collision->SetPosition(shot_pos + Vector3(0,0.06f,0));
	shot_pos = shot->GetPosition();
}

void EnemyShot::Draw3D() 
{
	
	if(shot_flag)
	shot->Draw();
	//collision->Draw();

}

void EnemyShot::Shot(Vector3 pos) 
{
		shot_flag = true;
		shot_pos = pos;
}

MODEL EnemyShot::GetEnemyShotCollision() {
	ASSERT(collision && "-EnemyShot::GetEnemyShotCollision() collision ptr nullptr");
	return collision;
}