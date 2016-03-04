#pragma once
#include "DU.h"
ref class BuilderDU
{
public:
	BuilderDU(void);
	virtual DU bildDU() = 0;
	virtual void setParametrs() = 0;
};

