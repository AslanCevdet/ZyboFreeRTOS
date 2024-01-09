#pragma once

#include <Configs/CTaskConfigs.hpp>

class TestTask{
public:
	TestTask(uint32_t task_prio, uint32_t stack_size);
	static void TaskCode(void* p_arg);

};
