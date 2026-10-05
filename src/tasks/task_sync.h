#ifndef TASK_SYNC_H
#define TASK_SYNC_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "semphr.h"

extern SemaphoreHandle_t xButtonSemaphore;
extern QueueHandle_t xBufferQueue;

#define LED_RED 8

void taskSync(void *pvParameters);

#endif