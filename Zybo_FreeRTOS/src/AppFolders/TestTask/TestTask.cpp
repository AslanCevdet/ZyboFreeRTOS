#include <AppFolders/TestTask/TestTask.hpp>
#include <FreeRTOS.h>
#include <task.h>


TestTask::TestTask(uint32_t task_prio, uint32_t stack_size){

	BaseType_t ret = pdPASS;


	ret = xTaskCreate(TestTask::TaskCode, "TestTask", stack_size, NULL, task_prio, NULL);
	if(pdPASS != ret){
		//ErrorSender will be implemented here
	}

}

void TestTask::TaskCode(void* p_arg){

	uint32_t TestNumber = 0;

	TaskStatus_t* pxTaskStatusArray;
	volatile UBaseType_t uxArraySize, x;
	unsigned long ulTotalRunTime, ulStatsAsPercentage;

	uxArraySize = uxTaskGetNumberOfTasks();

	pxTaskStatusArray = (TaskStatus_t*)pvPortMalloc(uxArraySize * sizeof(TaskStatus_t));



	while(1){

		TestNumber++;
		vTaskDelay(pdMS_TO_TICKS(100));

		if( pxTaskStatusArray != NULL )
			   {
			      /* Generate raw status information about each task. */
			      uxArraySize = uxTaskGetSystemState( pxTaskStatusArray,
			                                 uxArraySize,
			                                 &ulTotalRunTime );

			      /* For percentage calculations. */
			      ulTotalRunTime /= 100UL;

			      /* Avoid divide by zero errors. */
			      if( ulTotalRunTime > 0 )
			      {
			         /* For each populated position in the pxTaskStatusArray array,
			         format the raw data as human readable ASCII data. */
			         for( x = 0; x < uxArraySize; x++ )
			         {
			            /* What percentage of the total run time has the task used?
			            This will always be rounded down to the nearest integer.
			            ulTotalRunTimeDiv100 has already been divided by 100. */
			            ulStatsAsPercentage =
			                  pxTaskStatusArray[ x ].ulRunTimeCounter / ulTotalRunTime;

			            if( ulStatsAsPercentage > 0UL )
			            {
//			               sprintf( pcWriteBuffer, "%stt%lutt%lu%%rn",
//			                                 pxTaskStatusArray[ x ].pcTaskName,
//			                                 pxTaskStatusArray[ x ].ulRunTimeCounter,
//			                                 ulStatsAsPercentage );
			            }
			            else
			            {
			               /* If the percentage is zero here then the task has
			               consumed less than 1% of the total run time. */
//			               sprintf( pcWriteBuffer, "%stt%lutt<1%%rn",
//			                                 pxTaskStatusArray[ x ].pcTaskName,
//			                                 pxTaskStatusArray[ x ].ulRunTimeCounter );
			            }


			         }
			      }
			   }

	}

}
