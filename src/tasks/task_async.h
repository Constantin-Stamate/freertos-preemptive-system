#ifndef TASK_ASYNC_H
#define TASK_ASYNC_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "semphr.h"

extern QueueHandle_t xBufferQueue;

void taskAsync(void *pvParameters);

#endif