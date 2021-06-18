#pragma once
#include"../../ESGLib.h"
#include"../Player_Class/Player/Player.h"

class Map
{
public:
	Map() {};
	~Map() {};
	virtual void Initialize();
	virtual void Update();
	virtual void Draw3D();
private:

	void AddModelParametor(LPCTSTR _filename, int interval, Vector3 position);
	std::vector<MODEL> model;
	std::vector<std::vector<Vector3>> model_position;
	std::vector<int>                  model_interval;
	const Vector3 road_pos   = Vector3(0.0f, -0.25f, 0.0f);
	const Vector3 side_pos   = Vector3(0.0f, -8.0f, 0.0f);
	const Vector3 pillar_pos = Vector3_Zero;
	std::unique_ptr<Player>player_pos;

	float Move;

	enum Magic_Num
	{
	 //Ÿ“¹‚ÌŠÔŠu
	 ROAD_INTERVAL = 17,
	 //Ÿ’Œ‚ÌŠÔŠu
	 PILLAR_INTERVAL = 23,
	 //Ÿƒrƒ‹‚ÌŠÔŠu
	 SIDE_INTERVAL = 60,
	 //ŸˆÊ’u
	 REMOVE_POS = 20
	};

};