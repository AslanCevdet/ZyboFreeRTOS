#include <AppFolders/InitSystem/InitSystem.hpp>
#include <AppFolders/TestTask/TestTask.hpp>
#include <Configs/CTaskConfigs.hpp>


InitSystem::InitSystem(){

	InitSystem::SetupFreeRTOS();
	InitSystem::Create();
	//IP initalization will be implemented here


}


void InitSystem::Create(){

	/*
	 * All the tasks will be created here
	 * The task prioerties and stack sizes will be stored in TaskConfigs.
	 * */

	/*
	 * The "task classes" should be implemented below
	 * */
	pTestTask = new TestTask(CTaskConfigs::TestTaskPrio, CTaskConfigs::TestTaskStackSize);

}


void InitSystem::SetupFreeRTOS(){

	vPortInstallFreeRTOSVectorTable();

	ScuGicDriver::Init();

	ScuGicDriver::DisConnectInterrupt(56);
	ScuGicDriver::DisConnectInterrupt(54);
	ScuGicDriver::DisConnectInterrupt(57);
	ScuGicDriver::DisConnectInterrupt(29);

}

