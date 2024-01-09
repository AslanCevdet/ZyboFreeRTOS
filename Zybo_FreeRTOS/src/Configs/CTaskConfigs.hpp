#pragma once
#include <FreeRTOSConfig.h>

class CTaskConfigs{
public:

	static const uint32_t PrioBase				= configMAX_PRIORITIES - 20;
	static const uint32_t DefaultStackSize		= 2048;
	//Idle lowest, EMAC and IP highest respectively.

	static const uint32_t TestTaskPrio			= PrioBase - 6;
	static const uint32_t TestTaskStackSize		= DefaultStackSize;

private:
};
