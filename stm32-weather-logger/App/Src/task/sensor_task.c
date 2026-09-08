#include "task/sensor_task.h"
#include "common.h"
#include "cmsis_os.h"
#include "service/sensor_service.h"

static void init() {
	UAL_SENSOR_SERVICE_BME280_Init();
	UAL_SENSOR_SERVICE_DS1307_Init();
}

void UAL_SENSOR_TASK_Start(void *argument) {
	uint32_t last_tick = osKernelGetTickCount();

	init();

	while (1) {
		last_tick += pdMS_TO_TICKS(1000);
		SENSORS_DATA_t sensors_data = UAL_SENSOR_SERVICE_GetData();
		osDelayUntil(last_tick);
	}
}
