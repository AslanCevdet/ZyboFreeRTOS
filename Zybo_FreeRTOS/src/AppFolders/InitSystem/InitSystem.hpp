#pragma once

#include <AppFolders/TestTask/TestTask.hpp>
#include <FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include <Drivers/ScuGicDriver/ScuGicDriver.hpp>
#include <task.h>
#include <xpseudo_asm.h>
#include <xil_mmu.h>

class InitSystem{

public:
	InitSystem();
	void SetupFreeRTOS();
	void Create();


	TestTask*   pTestTask;
};
