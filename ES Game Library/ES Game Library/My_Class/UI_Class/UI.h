#pragma once
#include"../../ESGLib.h"
#include"../Scene_Manegeer/SceneManager.h"

class UI
{
public:
	void Initialize();
	void Update();
	void Draw();

	int GetTime() { return time; }
	void TimeLeft();


private:
	enum Time  {MIN_TIME, MAX_TIME  = 30};
	enum Frame {MIN_FRAME,MAX_FRAME = 60};
	
	const Vector2 time_pos  = Vector2(600, 0);
	const Vector2 score_pos = Vector2(800, 0);

	const int font_size = 90;
	const int score_font_size = 70;

	FONT font,score_font;
	int time  = MAX_TIME;
	int frame = MIN_FRAME;
};

