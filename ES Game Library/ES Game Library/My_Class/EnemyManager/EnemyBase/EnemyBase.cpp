#include"EnemyBase.h"

EnemyBase::EnemyBase() {
}

EnemyBase::~EnemyBase() {

}

bool EnemyBase::Initialize() {
	Model = GraphicsDevice.CreateModelFromFile(_T("Enemy_Material/red/jiki_car_red.X"));

	model_parameters.tags = 'E';
	model_parameters.p_model_position_revision.y = 0.05f;

	this->attack_parameters._Type = ATTACK_TYPE::DAMEGE;

	SimpleShape shape;
	shape.Type = Shape_Box;

	shape.Width  = 1;
	shape.Height = 1;
	shape.Length = 1;

	Material material;
	material.Emissive = Color(Vector3_One);
	material.Diffuse = Color(Vector3_One);
	material.Ambient = Color(Vector3_One / half);
	material.Specular = Color(Vector3_One);
	material.Power = material_power;

	Model->SetPosition(model_init_pos);
	Model->SetMaterial(material);

	Collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	Collision->SetMaterial(material);
	Collision->SetScale(collision_scele);
	Collision->SetPosition(Model->GetPosition());

	enemy_shot_manager.Initialize();
	return true;
}

int EnemyBase::Update() {
	pos = Model->GetPosition();
	Collision->SetPosition(pos + collision_fit_pos);

	enemy_shot_manager.Shot(pos);

	enemy_shot_manager.Update();
	Move();
	return 0;
}

void EnemyBase::Draw3D() {
	Model->Draw();

	enemy_shot_manager.Draw3D();
//	Collision->Draw();
}

void EnemyBase::Move() {

}

int EnemyBase::LifeDeathDecision() {
	if (hp < 0)
		return DEATH;
	else if (Player::Instance().GetPlayerPosition() > pos)
		return AUTODEAD;
	else
		return LIVE;
}

MODEL EnemyBase::GetCollision() {
	ASSERT(Collision && "-EnemyBase::GetCollision() Collision ptr nullptr");
	return Collision;
}