#include "Item_Class.h"

void Item::Init()
{
	TimeItem = GraphicsDevice.CreateModelFromFile(_T("Object_Material/obj_f.X"));

	model_parameters.tags = 'I';
	model_parameters.p_model_position_revision.y = 0.05f;

	this->attack_parameters._Type = ATTACK_TYPE::ITEM;
}

void Item::Update()
{

}

void Item::Draw3D()
{
	TimeItem->Draw();
}
