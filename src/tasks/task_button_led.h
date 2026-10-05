#ifndef TASK_BUTTON_LED_H
#define TASK_BUTTON_LED_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "semphr.h"

extern SemaphoreHandle_t xButtonSemaphore;

#define BUTTON_PIN 2
#define LED_GREEN 7

void taskButtonLed(void *pvParameters);

#endif