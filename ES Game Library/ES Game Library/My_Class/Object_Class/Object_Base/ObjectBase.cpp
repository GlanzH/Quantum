#include "ObjectBase.h"

Object::Object()
{
	//マップのデータベース作成
	_mapdata.reset(new MapData);
}

void Object::Draw3D()
{
	auto&& itr = this->_mapdata->GetPlayerPosition(model_parameters.tags);
}
