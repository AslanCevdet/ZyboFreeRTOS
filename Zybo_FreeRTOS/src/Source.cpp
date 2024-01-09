#include <AppFolders/InitSystem/InitSystem.hpp>
#include <FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include <task.h>
#include <xpseudo_asm.h>
#include <xil_mmu.h>

int main(int argc, char** p_arg){


	InitSystem();

	vTaskStartScheduler();

}
