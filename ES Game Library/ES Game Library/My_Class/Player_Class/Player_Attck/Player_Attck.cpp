#include "Player_Attck.h"


void Player_Attck::Initialize()
{
	shot = GraphicsDevice.CreateModelFromFile(_T(""));

	for (int i = 0; i < SHOT_MAX; i++)
	{
		shot_state[i] = 0;
		bull_pos = Vector3_Zero;
	}
	 
}

void Player_Attck::Update()
{
	for (int i = 0; i < SHOT_MAX; i++)
	{
		//if (shot_state[i] == 1)
		//{
		//	shot_x[i] += this->direction  * 20;
		//	if ((shot_x[i]) > 1280 || (shot_x[i]) < -10)
		//	{
		//		shot_state[i] = 0;
		//	}
		//}
	}
	
}



void Player_Attck::Draw3D()
{
	for (int i = 0; i < SHOT_MAX; i++)
	{
		if (shot_state[i] == 1)
		{
			shot->Draw();
		}
	}
}

void Player_Attck::Shot(float x,float y, int p_direction)
{
	for (int i = 0; i < SHOT_MAX; i++)
	{
		if (shot_state[i] == 0)
		{
			shot_state[i] = 1;
			//shot_x[i] = x + 100;
			//shot_y[i] = y + 40;
			direction = p_direction;
			break;
		}
	}
	
}


	


