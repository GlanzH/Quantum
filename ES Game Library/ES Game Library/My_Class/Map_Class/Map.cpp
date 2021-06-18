#include "Map.h"

void Map::Initialize()
{
	AddModelParametor(_T("Map_Material/Road.X"), ROAD_INTERVAL, road_pos);
	AddModelParametor(_T("Map_Material/kari.X"), PILLAR_INTERVAL, pillar_pos);
	AddModelParametor(_T("Map_Material/pro_set.X"), SIDE_INTERVAL, side_pos);
}	

void Map::Update()
{
	Vector3 player_position = player_pos->GetPlayerPosition();

	for (int y = 0; y < model_position.size(); ++y)
	{
		Vector3 position = *model_position[y].begin();
		int remove_position = REMOVE_POS;
		if (position.z + remove_position <= player_position.z)
		{
			model_position[y].erase(model_position[y].begin());
			model_position[y].push_back(Vector3(position.x, position.y, (model_position[y].back().z + model_interval[y])));
		}
	}
}

void Map::Draw3D()
{
	for (int y = 0; y < model_position.size(); ++y)
	{
		for (int x = 0; x < model_position[y].size(); ++x)
		{
			model[y]->SetPosition(model_position[y][x]);
			model[y]->Draw();
		}
	}

	return;
}

void Map::AddModelParametor(LPCTSTR _filename, int interval, Vector3 position)
{
	Material mtrl;
	mtrl.Emissive = Color(1.0f, 1.0f, 1.0f);

	model.push_back(GraphicsDevice.CreateModelFromFile(_filename));
	model[model.size() - 1]->SetScale(1.0f);
	model[model.size() - 1]->SetMaterial(mtrl);
	model_interval.push_back(interval);
	model_position.resize(model.size());

	int model_size = 8;

	for (int i = 0; i < model_size; i++)
	{
		model_position[model.size() - 1].push_back(position + Vector3(0.0f, 0.0f, -5 + (i * interval)));
	}
}
