#pragma once
#include"../../ESGLib.h"


class UI
{
public:
	void Initialize();
	void Update();
	void Draw();

	int GetTime() { return time; }
	void TimeLeft();


private:
	enum {MIN_TIME, MAX_TIME  = 30};
	enum {MIN_FRAME,MAX_FRAME = 60};

	FONT font;
	int time  = MAX_TIME;
	int frame = MIN_FRAME;
};

