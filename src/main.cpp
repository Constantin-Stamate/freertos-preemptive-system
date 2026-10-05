#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "semphr.h"
#include "tasks/task_button_led.h"
#include "tasks/task_sync.h"
#include "tasks/task_async.h"

SemaphoreHandle_t xButtonSemaphore;
QueueHandle_t xBufferQueue;

void setup() {
    Serial.begin(115200);

    xButtonSemaphore = xSemaphoreCreateBinary();
    xBufferQueue = xQueueCreate(20, sizeof(uint8_t));

    xTaskCreate(taskButtonLed, "ButtonLed", 128, NULL, 2, NULL);
    xTaskCreate(taskSync, "Sync", 256, NULL, 2, NULL);
    xTaskCreate(taskAsync, "Async", 256, NULL, 1, NULL);
}

void loop() {
    // FreeRTOS takes control
}