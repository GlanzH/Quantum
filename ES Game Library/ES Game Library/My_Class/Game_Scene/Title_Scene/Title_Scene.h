#pragma
#include "../../Scene_Manegeer/SceneManager.h"

class Title_Scene : public BaseScene
{
public:
	Title_Scene() {};
	virtual ~Title_Scene() {};

	virtual void Initialize() override;
	virtual void Update()     override;
	virtual void Draw()       override;
	virtual void Draw3D() {};

	virtual void DrawEnd() {};
private:
	SPRITE TitleBG;
	SPRITE Tachyon;
	SPRITE Particles;
	SPRITE Letter;
	SOUND Se;
	short int   CharacterMove;
	float       Blinking;
	const float Speed = 0.01f;
	enum Magic_Num
	{
		ZERO = 0,
		APPEARANCE = 1280,
		Y_POS = 75,
		MOVE = 20,
	};

};

