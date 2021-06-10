#include "Map.h"

void Map::Initialize()
{
	Road = GraphicsDevice.CreateModelFromFile(_T("Map_Material/Road.X"));
	Pillar = GraphicsDevice.CreateModelFromFile(_T("Map_Material/kari.X"));
	Side = GraphicsDevice.CreateModelFromFile(_T("Map_Material/pro_set.X"));
}	

void Map::Update()
{
}

void Map::Draw()
{
	Road->Draw();
	Pillar->Draw();
	Side->Draw();
}
