/* The classic "blink" example
 *
 * This sample code is in the public domain.
 */
#include "espressif/esp_common.h"
#include "esp/uart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "esp8266.h"
#include <stdio.h>

#ifdef WIFI_SSID
#undef WIFI_SSID
#endif

#ifdef WIFI_PASS
#undef WIFI_PASS
#endif


#define WIFI_SSID "IC"
#define WIFI_PASS "icomputacaoufal"
//#define WIFI_SSID "GVT-C3C5"
//#define WIFI_PASS "5403000556"

void blinkenTask(void *pvParameters)
{
    while(1) {
        printf("tic %.2f\n", 1.3 + 3.5);
        vTaskDelay(1000 / portTICK_RATE_MS);        
        printf("tac\n");
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
    vTaskDelete(NULL);
}

void user_init(void)
{
    uart_set_baud(UART0, 115200);
    xTaskCreate(blinkenTask, (signed char *)"blinkenTask", 256, NULL, 2, NULL);    
}
