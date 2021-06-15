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
	MODEL Road;
	MODEL Pillar;
	MODEL Side;
};