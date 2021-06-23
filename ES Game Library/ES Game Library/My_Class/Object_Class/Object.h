#include"../../ESGLib.h"
#include "../EnumManager/EnumManager.h"

class Object
{
public:
	Object() {};
	~Object() {};

private:

};
class Item
{
public:
	Item() {};
	virtual ~Item() {};

	virtual void Init()        ;
	virtual void Update()      ;

	virtual void IsCollsion()  ;


private:
	MODEL Goods;



};