#pragma once
#include"../../Scene_Manegeer/SceneManager.h"

class Game_Clear : public BaseScene
{
public:
	Game_Clear() {};
	virtual ~Game_Clear() {};

	virtual void Initialize()override;
	virtual void Update()    override;
	virtual void Draw()      override;
	virtual void Draw3D() {};

	virtual void DrawEnd() {};
private:

	SPRITE Clear;
	SPRITE Push;
	float Blinking;

	const float speed = 0.01f;  //点滅スピード

		//!PUSH画像の座標
	const Vector3 PushPos = Vector3(-400, 0, -1);
};