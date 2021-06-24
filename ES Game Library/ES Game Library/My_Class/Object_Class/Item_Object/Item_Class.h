#include"../../../ESGLib.h"
#include"../Object_Base/ObjectBase.h"

class Item :public Object
{
public:
	Item() {};
	virtual ~Item() {};
	virtual void Init();
	virtual void Update();
	virtual void Draw3D();

private:
	MODEL TimeItem;
};

