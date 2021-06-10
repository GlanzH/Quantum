#include"UI.h"

void UI::Initialize()
{
	GAGE = GraphicsDevice.CreateSpriteFromFile(_T("Gauge/Gauge_B.jpg"));
	GAGE_S = GraphicsDevice.CreateSpriteFromFile(_T("Gauge/Gauge_LR.jpg"));
	Magic = GraphicsDevice.CreateSpriteFromFile(_T("UI/Magic.png"));
	Gauge = 200.0f;
	Gauge_2 = 500.0f;
	Gauge_flg = false;
}

void UI::Update()
{
	if (Gauge_flg == false)
	{
		if (Gauge < 200)
		{
			Gauge += 0.1;
		}
		if (Gauge <= -1)
		{
			Gauge = 0;
		}
		if (Gauge >= 200)
		{
			Gauge = 200;
		}
		//if (key.IsKeyDown(Keys_Enter))
		{
			Gauge = Gauge - 10;
		}
		//if (key.IsKeyDown(Keys_W))
		{

			Gauge = Gauge - 5;
		}
		//if (key.IsKeyDown(Keys_Space))
		{
			Gauge_flg = true;
		}
	}
	if (Gauge_flg == true)
	{
		if (Gauge_2 < 500)
		{
			Gauge_2 += 1.5f;
		}
		if (Gauge_2 <= -10)
		{
			Gauge_2 = 10;

		}
		if (Gauge_2 >= 500)
		{
			Gauge_2 = 500;
		}
		//if (key.IsKeyDown(Keys_Enter))
		{

			Gauge_2 = Gauge_2 - 10;
		}
		//if (key.IsKeyDown(Keys_D))
		{

			Gauge_2 = Gauge_2 - 5;
		}
		//if (key.IsKeyDown(Keys_S))
		{
			Gauge_flg = false;
		}
	}
}

void UI::Draw()
{
	if (Gauge_flg == false)
	{
		SpriteBatch.Draw(*GAGE, Vector3(150, 20, 0), RectWH(0.0f, 0.0f, Gauge, 20.0f));
	}
	if (Gauge_flg == true)
	{
		SpriteBatch.Draw(*GAGE_S, Vector3(150, 20, 0), RectWH(0.0f, 0.0f, Gauge_2, 20.0f));
	}

	SpriteBatch.Draw(*Magic, Vector3(-150, 0, 0));
}
