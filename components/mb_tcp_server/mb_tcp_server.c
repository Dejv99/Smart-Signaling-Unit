// #include "sdkconfig.h"		// for KConfig options
#include "mb_tcp_server.h"	// for Modbus TCP Server implementation
#include "esp_err.h"		// for error handling
#include "esp_log.h"		// for logging functionalities
#include "nvs_flash.h"

static const char *TAG = "mb_server";

void nvs_flash_initialization(void){
	esp_err_t result = nvs_flash_init(); // NVS ... Non-volatile Storage
	if (result == ESP_ERR_NVS_NO_FREE_PAGES || result == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		result = nvs_flash_init();
	}
	ESP_ERROR_CHECK(result);
}

void mb_server_test(void){
	esp_log_level_set(TAG, ESP_LOG_INFO); // Set UART log level

	void *mbc_slave_handler = NULL;
	ESP_ERROR_CHECK(mbc_slave_init_tcp(&mbc_slave_handler)); // Initialization of Modbus controller

	mb_param_info_t reg_info; // keeps the Modbus registers access information
	mb_register_area_descriptor_t reg_area; // Modbus register area descriptor structure

	mb_communication_info_t comm_info = { 0 };
	comm_info.ip_port = MB_TCP_PORT_NUMBER;
}