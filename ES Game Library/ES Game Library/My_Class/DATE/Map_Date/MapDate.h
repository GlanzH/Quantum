#pragma once
#include "../../../ESGLib.h"

//�}�b�v�̃p�����[�^
class  MapParametor;
//�}�b�v�̍��W
struct MapPos;
//�}�b�v�̃f�[�^
class  MapData;

struct MapPos
{
	std::vector<Vector3>  _position;
};

class MapParametor
{
public:
	friend class MapData;

	MapParametor() {};
	virtual ~MapParametor() {};

	static MapParametor& Instance() 
	{
		static MapParametor instance;
		return instance;
	};

	void CreateParametor(char name) { _map_params.emplace(name, _map_param); }

	std::map<char, MapPos> _map_params;
private:
	MapParametor(const MapParametor&) = delete;
	void      operator=(const MapParametor&) = delete;

	MapPos  _map_param;
};


class MapData
{
public:
	MapData() {};
	virtual ~MapData() {};

	void SetPlayerPosition(char name, Vector3 position)
	{
		if (MapParametor::Instance()._map_params.count(name) == 0)
			ASSERT("�A�z�z��̑��݂��܂���B");

		MapParametor::Instance()._map_params[name]._position.push_back(position);
	}

	std::vector<Vector3>& GetPlayerPosition(char name)
	{
		if (MapParametor::Instance()._map_params.count(name) == 0)
			ASSERT("�A�z�z��̑��݂��܂���B");

		return MapParametor::Instance()._map_params[name]._position;
	}

};