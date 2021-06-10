#pragma once
#include"../../Scene_Manegeer/SceneManager.h"

class Game_Claer : public BaseScene
{
public:
	Game_Claer() {};
	virtual ~Game_Claer() {};

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;

	virtual void DrawEnd() {};
private:

	SPRITE CLAER;
	SPRITE Push;
	float Blinking;
};