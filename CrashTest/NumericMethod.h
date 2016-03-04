#include "DU.h"
#include "TaskKoshi.h"

#pragma once

ref class NumericMethod
{
private: 
	DU du;
	TaskKoshi task;
public:
	NumericMethod();
	NumericMethod(DU du, TaskKoshi task);
	virtual void setDU(DU du) = 0;
	virtual void setTaskKoshi(TaskKoshi task) = 0;
	virtual double executeMethood() = 0;
};

