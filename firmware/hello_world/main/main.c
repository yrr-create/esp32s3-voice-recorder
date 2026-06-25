#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    int count = 0;

    printf("ESP32-S3 voice recorder board boot OK\n");

    while (1) {
        printf("hello esp32-s3: %d\n", count++);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

