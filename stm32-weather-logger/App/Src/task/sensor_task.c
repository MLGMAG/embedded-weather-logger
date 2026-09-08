#include "task/sensor_task.h"
#include "common.h"
#include "cmsis_os.h"
#include "service/sensor_service.h"
#include "service/sensors_data_storage.h"

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
		UAL_SENSORS_DATA_STORAGE_Collect(&sensors_data);
		osDelayUntil(last_tick);
	}
}
