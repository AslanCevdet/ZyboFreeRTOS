#include <FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include <Drivers/ScuGicDriver/ScuGicDriver.hpp>
#include <task.h>
#include <xpseudo_asm.h>
#include <xil_mmu.h>


void TaskCode(void *p_arg){

	int a = 0;
	while(1){

		a++;
	}

}


int main(int argc, char** p_arg){


	vPortInstallFreeRTOSVectorTable();

	ScuGicDriver::Init();

	ScuGicDriver::DisConnectInterrupt(56);
	ScuGicDriver::DisConnectInterrupt(54);
	ScuGicDriver::DisConnectInterrupt(57);
	ScuGicDriver::DisConnectInterrupt(29);


	xTaskCreate(TaskCode, "TestTask", 4096, NULL, 40, NULL);

	vTaskStartScheduler();

}
