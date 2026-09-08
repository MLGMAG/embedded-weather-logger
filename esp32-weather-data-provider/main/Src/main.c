#include "hardware/uart_util.h"
#include <stdbool.h>
#include <unistd.h>

static void init(void) {
	UAL_UART_UTIL_Init();
}

void app_main(void) {
	init();

	while (1) {
		vTaskDelay(portMAX_DELAY);
	}
}
