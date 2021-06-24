#pragma once

#include"../../../ESGLib.h"
#include "../../EnumManager/EnumManager.h"
#include"../Object_Basic/ObjectBasic.h"


struct MODEL_PARAMETERS
{
public:
	Vector3 p_model_position_revision = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 p_hitbox_position_revision = Vector3(0.0f, 0.0f, 0.0f);
	//�^�O�̐ݒ�
	char    tags = '?';

private:
};
enum ATTACK_TYPE { DAMEGE, ITEM, GAMEOVER, ITEMBROCK, END };


struct ATTACK_PARAMETERS
{
public:
	//�^����_���[�W��
	float _AddDamege = 0.1f;
	//����
	ATTACK_TYPE _Type;
private:
};

class ObjectBase : public Object
{
public:
	ObjectBase();
	virtual ~ObjectBase() {};

	virtual void Init()        override = 0;
	virtual void Update()      override = 0;
	virtual void Draw3D()      override;

	virtual void DrawAlpha3D() override { return; };
	virtual void Draw2D()      override { return; };

	ATTACK_PARAMETERS GetAttackParameters() const { return attack_parameters; };
private:

protected:
	//�֐��錾

	bool         OnCollsion();
	virtual void IsCollsion() { return; };

	virtual bool PModelParameter(std::vector<Vector3>::iterator& itr) { return false; };

	ATTACK_PARAMETERS attack_parameters;
	MODEL_PARAMETERS   model_parameters;

	//�ϐ��錾
	/*Hit* p_hitbox;*/
	//Model     p_model;
	/*OBSERVER* p_obsever;*/

	float p_distance;

	//�v���C���[�̃f�[�^�x�[�X
	/*std::unique_ptr<IMapData>     _imap_data;
	std::unique_ptr<UiData>       _iui_data;
	std::unique_ptr<IPlayerData>  _iplayer_data;*/
};