#include "ObjectBase.h"

Object::Object()
{
	//�}�b�v�̃f�[�^�x�[�X�쐬
	_mapdata.reset(new MapData);
}

void Object::Draw3D()
{
	auto&& itr = this->_mapdata->GetPlayerPosition(model_parameters.tags);
}
