#pragma once
#include"../../ESGLib.h"
#include"../Object_Class/Object_Base/ObjectBase.h"
#include "../DATE/Map_Date/MapDate.h"

class ObjectPlan : public Object
{
public:
	ObjectPlan() ;
	~ObjectPlan() {};

	void Init() ;
	void Update() ;
	void Draw3D();
private:
	std::vector<cstring>  mapdata;

	void MapdataTagsPos();

	//プレイヤーのデータベース
	std::unique_ptr<MapData>   _mapdata;
};


