#pragma once
#include"../../ESGLib.h"
#include"../Object_Class/ObjectBasic.h"


class Hit : public Object
{
public:
	//デストラクタ
	Hit::Hit() {};

	virtual Hit::~Hit();

	virtual void Hit::Init()   override;
	virtual void Hit::Update() override { return; };
	virtual void Hit::Draw3D() override;

	void Hit::OnReMove();

	void Hit::SetScale(Vector3 scale) { _model->SetScale(scale); };

	//自身を返す
	Hit* Hit::GetThisHitBox() { return this; };

	//衝突しているHitBoxのリストを取得
	std::list<Hit*> Hit::HitHitlist();

	void    Settags(std::string tags);

	Hit* Hit::Get_Tag_Hit(std::string tag);
	MODEL   Hit::GetModel() { return _model; };

	bool Hit::IsHitObjects(std::string tags);

	bool _flag = false;

private:
	//全てのHitBoxを格納しておくリスト
	static std::list<Hit*> _Hit_list;

	//判定用のモデル
	MODEL _model = nullptr;
	std::string _tag;

	//衝突判定関数
	bool Hit::IsHit(Hit* other);

protected:

};