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
	SPRITE Title_BG;
	SPRITE Tachyon;
	SPRITE particles;
	SPRITE Letter;
	SOUND se;
	short int character_move;
	float Blinking;
	enum Magic_Num
	{
		Zero = 0,
		APPEARANCE = 1280,
		Y_POS = 75,
		MOVE = 20,
	};

};

