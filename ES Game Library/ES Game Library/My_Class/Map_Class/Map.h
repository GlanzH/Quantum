#pragma once
#include"../../ESGLib.h"

class Map
{
public:
	Map() {};
	~Map() {};
	virtual void Initialize();
	virtual void Update();
	virtual void Draw();
private:
	void AddModelParametor(LPCTSTR _filename, int interval, Vector3 position);
	std::vector<MODEL> model;
	std::vector<std::vector<Vector3>> model_position;
	std::vector<int>                  model_interval;
	
	enum Interval
	{
		//
		ROAD_INTERVAL = 17,
		//
		PILLAR_INTERVAL = 23,
		//
		SIDE_INTERVAL = 60
	};

};