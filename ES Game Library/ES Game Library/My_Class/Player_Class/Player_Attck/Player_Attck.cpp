#include "Player_Attck.h"


void Player_Attck::Initialize()
{
	Ofuda = GraphicsDevice.CreateSpriteFromFile(_T("Player_Enemy/Ofuda.png"));/*png*/

	for (int i = 0; i < SHOT_MAX; i++)
	{
		shot_state[i] = 0;
		shot_x[i] = 0.0f;
		shot_y[i] = 0.0f;
	}
	 
}

void Player_Attck::Update()
{
	for (int i = 0; i < SHOT_MAX; i++)
	{
		if (shot_state[i] == 1)
		{
			shot_x[i] += this->direction  * 20;
			if ((shot_x[i]) > 1280 || (shot_x[i]) < -10)
			{
				shot_state[i] = 0;
			}
		}
	}
	
}



void Player_Attck::Draw()
{
	for (int i = 0; i < SHOT_MAX; i++)
	{
		if (shot_state[i] == 1)
		{
			SpriteBatch.Draw(*Ofuda, Vector3(shot_x[i], shot_y[i], 0));
		}
	}
}

void Player_Attck::shot(float x,float y, int p_direction)
{
	for (int i = 0; i < SHOT_MAX; i++)
	{
		if (shot_state[i] == 0)
		{
			shot_state[i] = 1;
			shot_x[i] = x + 100;
			shot_y[i] = y + 40;
			direction = p_direction;
			break;
		}
	}
	
}


	


