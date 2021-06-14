#pragma once
#include "../../Scene_Manegeer/SceneManager.h"

class  Game_Over :public BaseScene
{
public:
	Game_Over() {};
	virtual ~Game_Over() {};

	virtual void Initialize() override;
	virtual void Update()     override;
	virtual void Draw()       override;
	virtual void Draw3D() {};

	virtual void DrawEnd() {};
private:
	SPRITE OVER;
	SPRITE Push;
	float Blinking;
};