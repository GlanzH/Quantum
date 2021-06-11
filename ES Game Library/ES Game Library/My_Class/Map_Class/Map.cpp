#include "Map.h"

void Map::Initialize()
{
	Road = GraphicsDevice.CreateModelFromFile(_T("Map_Material/Road.X"));
	Pillar = GraphicsDevice.CreateModelFromFile(_T("Map_Material/kari.X"));
	Side = GraphicsDevice.CreateModelFromFile(_T("Map_Material/pro_set.X"));

	Material material;
	material.Diffuse = Color(1.0f, 0.0f, 0.0f);
	material.Ambient = Color(5.0f, 5.0f, 5.0f);
	material.Specular = Color(1.0f, 0.0f, 0.0f);
	material.Power = 10.0f;
	Road->SetMaterial(material);
	Pillar->SetMaterial(material);
	Side->SetMaterial(material);
	Road->GetFrontVector();
	Pillar->GetFrontVector();
	Side->GetFrontVector();
	Road->GetUpVector();
	Pillar->GetUpVector();
	Side->GetUpVector();





}	

void Map::Update()
{
}

void Map::Draw()
{
	GraphicsDevice.BeginAlphaBlend();
	Road->DrawAlpha(0.5f);
	Pillar->DrawAlpha(0.5f);
	Side->DrawAlpha(0.5f);
	GraphicsDevice.EndAlphaBlend();
	Road->Draw();
	Pillar->Draw();
	Side->Draw();
}
