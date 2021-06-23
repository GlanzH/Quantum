#include "EnemyShot.h"

void EnemyShot::Initialize() {
	shot = GraphicsDevice.CreateModelFromFile(_T("Player/ball/red.X"));

	Material material;
	material.Emissive = Color(Vector3_One);
	material.Diffuse  = Color(Vector3_One);
	material.Ambient  = Color(Vector3_One / half);
	material.Specular = Color(Vector3_One);
	material.Power    = material_power;
	
	shot->SetMaterial(material);
	shot->SetScale(model_scale);

	SimpleShape shape;
	shape.Type = Shape_Box;
	shape.Width = 1;
	shape.Depth = 1;
	shape.Height = 1;

	collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	collision->SetScale(collision_scale);
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
	collision->SetPosition(shot_pos + collision_fit);
	shot_pos = shot->GetPosition();
}

void EnemyShot::Draw3D() 
{
	
	if (shot_flag) {
		shot->Draw();
		//collision->Draw();
	}

}

void EnemyShot::Shot(Vector3 pos) 
{
		shot_flag = true;
		shot_pos = pos;
}

MODEL EnemyShot::GetCollision() {
	ASSERT(collision && "-EnemyShot::GetEnemyShotCollision() collision ptr nullptr");
	return collision;
}