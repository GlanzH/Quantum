#pragma
#include "../../Scene_Manegeer/SceneManager.h"

class Title_Scene : public BaseScene
{
public:
	Title_Scene() {};
	virtual ~Title_Scene() {};

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()override;

	virtual void DrawEnd() {};
private:
	SPRITE Title_BG;
	SPRITE Letter;
	SOUND se;
	float Blinking;
};

