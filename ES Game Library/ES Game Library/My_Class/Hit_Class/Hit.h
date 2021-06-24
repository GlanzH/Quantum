#pragma once
#include"../../ESGLib.h"
#include"../Object_Class/ObjectBasic.h"


class Hit : public Object
{
public:
	//�f�X�g���N�^
	Hit::Hit() {};

	virtual Hit::~Hit();

	virtual void Hit::Init()   override;
	virtual void Hit::Update() override { return; };
	virtual void Hit::Draw3D() override;

	void Hit::OnReMove();

	void Hit::SetScale(Vector3 scale) { _model->SetScale(scale); };

	//���g��Ԃ�
	Hit* Hit::GetThisHitBox() { return this; };

	//�Փ˂��Ă���HitBox�̃��X�g���擾
	std::list<Hit*> Hit::HitHitlist();

	void    Settags(std::string tags);

	Hit* Hit::Get_Tag_Hit(std::string tag);
	MODEL   Hit::GetModel() { return _model; };

	bool Hit::IsHitObjects(std::string tags);

	bool _flag = false;

private:
	//�S�Ă�HitBox���i�[���Ă������X�g
	static std::list<Hit*> _Hit_list;

	//����p�̃��f��
	MODEL _model = nullptr;
	std::string _tag;

	//�Փ˔���֐�
	bool Hit::IsHit(Hit* other);

protected:

};