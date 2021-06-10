#pragma once
#include"../../ESGLib.h"


class UI
{
public:
	virtual void Initialize();
	virtual void Update();
	virtual void Draw();


private:
	SPRITE GAGE;
	SPRITE GAGE_S;
	SPRITE Magic;
	int Gauge_flg;
	float Gauge;
	float Gauge_2;
};

