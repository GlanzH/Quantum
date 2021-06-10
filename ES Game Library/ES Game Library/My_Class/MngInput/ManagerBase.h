#pragma once
#include "../../ESGLib.h"

class ManagerBase
{
public:
	ManagerBase() {};
	virtual ~ManagerBase() {};

	virtual void Intialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
private:

};

