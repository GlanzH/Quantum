#include "Hit.h"

std::list<Hit*> Hit::_Hit_list;

//デストラクタ
Hit::~Hit()
{
	OnReMove();
}
void Hit::Init() {
	//自分をリストに挿入
	_Hit_list.push_back(this);

	//タグ設定
	_tag = "HitBox";

	SimpleShape   shape;
	shape.Type = Shape_Box;
	shape.Width = 1.0f; shape.Height = 1.0f; shape.Depth = 1.0f;
	_model = GraphicsDevice.CreateModelFromSimpleShape(shape);

	_model->SetScale(0.3f);
};

void Hit::Draw3D() {
	if (_flag) return;
	_model->SetPosition(this->transform.position);
	//_model->Draw();
}

void Hit::Settags(std::string tags) {
	_tag = tags;
}

// 消去時に呼ばれる処理
void Hit::OnReMove() {
	auto it = _Hit_list.begin();
	while (it != _Hit_list.end()) {
		if ((*it) != this) {
			it++;
		}
		else {
			it = _Hit_list.erase(it);
			return;
		}
	}
}

bool Hit::IsHit(Hit* other) {
	OrientedBoundingBox model_obb1 = this->_model->GetOBB();
	OrientedBoundingBox model_obb2 = other->_model->GetOBB();
	return model_obb1.Intersects(model_obb2);
}

std::list<Hit*> Hit::HitHitlist() {
	std::list<Hit*>  result;
	for (auto&& h : _Hit_list) {
		if (h->GetThisHitBox() == this) continue;
		if (h->IsHit(this)) result.push_back(h->GetThisHitBox());
	}
	return result;
};

Hit* Hit::Get_Tag_Hit(std::string tag)
{
	Hit* hit= nullptr;
	for (auto&& other_hitbox : _Hit_list)
	{
		if (other_hitbox->_tag != tag) continue;
		if (this == other_hitbox->GetThisHitBox()) continue;

		hit = other_hitbox->GetThisHitBox();
	}

	return hit;
}

bool Hit::IsHitObjects(std::string tags)
{
	bool result = false;
	std::list<Hit*> HitList = HitHitlist();
	for (auto&& other : HitList)
	{
		if (other->_tag == tags)
		{
			result = true;
		}
	}
	return result;
}