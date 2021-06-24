#include"ObjectBase.h"
#include"../Player_Class/Player/Player.h"
bool ObjectBase::OnCollsion()
{
	if (p_distance >= 5) return false;
	this->p_hitbox->GetModel()->SetPosition(this->transform.position + model_parameters.p_hitbox_position_revision);
	std::list<Hit*> hitlist = p_hitbox->HitHitlist();
	for (auto&& other : hitlist) {
		if (other->gameObject == this->gameObject) continue;
		if (typeid(*other->gameObject) == typeid(Player))
		{
			this->IsCollsion();
			((Player*)(other->gameObject))->AttackHit(this);
			return true;
		}
	}
	return false;
}

//ObstacleBase::ObstacleBase()
//{
//	//プレイヤーのデータベース作成
//	_iplayer_data.reset(new IPlayerData);
//	//マップのデータベース作成
//	_imap_data.reset(new IMapData);
//	//UIのデータベース作成
//	_iui_data.reset(new UiData);
//}

void ObjectBase::Draw3D()
{
	/*auto&& itr = this->_imap_data->GetPlayerPosition(model_parameters.tags);
	Vector3 player_position = this->_iplayer_data->GetPlayerPosition("player");

	auto& obstacle_itr = itr.begin();
	while (obstacle_itr != itr.end()) {
		this->transform.position = *obstacle_itr;
		this->p_distance = this->transform.position.z - player_position.z;

		if (this->p_distance <= 90.0f) {
			if (PModelParameter(obstacle_itr)) { obstacle_itr = itr.erase(obstacle_itr); continue; };

			this->p_model.SetPosition(this->transform.position + model_parameters.p_model_position_revision);
			this->p_model.Draw();
		}
		if (this->p_distance <= -1.0f) {
			obstacle_itr = itr.erase(obstacle_itr);
			if (typeid(*m_gameObject) == typeid(R_GATEOBSTATCLE)) { p_obsever->IsCollision("GATEBREAK"); }
			continue;
		};
		obstacle_itr++;
	}*/
};
