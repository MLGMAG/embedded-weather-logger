#include "esp_log.h"
#include "hardware/uart_util.h"
#include "hardware/wifi_sta_util.h"
#include "hardware/http_server_util.h"
#include "task/sensors_data_sync_task.h"
#include <stdbool.h>
#include <unistd.h>

TaskHandle_t SENSORS_DATA_SYNC_TASK_HANDLER = NULL;

QueueHandle_t UART_TX_QUEUE_HANDLER = NULL;
SemaphoreHandle_t SENSORS_DATA_STORAGE_MUTEX = NULL;

static const char *TAG = "MAIN";

static void init_tasks(void) {
	BaseType_t status;

	status = xTaskCreate(UAL_SENSORS_DATA_SYNC_TASK_Start,
						 "SENSORS_DATA_SYNC_TASK", configMINIMAL_STACK_SIZE,
						 NULL, CONFIG_SENSORS_DATA_SYNC_TASK_PRIORITY,
						 &SENSORS_DATA_SYNC_TASK_HANDLER);
	if (status != pdPASS) {
		ESP_LOGE(TAG, "Could not create SENSORS_DATA_SYNC_TASK task, status: %d", status);
		UAL_Error_Handler();
	}
}

static void init(void) {
	SENSORS_DATA_STORAGE_MUTEX = xSemaphoreCreateMutex();

	UAL_UART_UTIL_Init();

	init_tasks();
	
	UAL_WIFI_STA_UTIL_Init();
	UAL_HTTP_SERVER_UTIL_Init();
}

void app_main(void) {
	init();

	while (1) {
		vTaskDelay(portMAX_DELAY);
	}
}
