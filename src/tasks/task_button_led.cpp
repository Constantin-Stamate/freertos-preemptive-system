#include "task_button_led.h"

void taskButtonLed(void *pvParameters) {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_GREEN, OUTPUT);

    for (;;) {
        // Check if the button is pressed
        if (digitalRead(BUTTON_PIN) == LOW) {
            digitalWrite(LED_GREEN, HIGH);
            vTaskDelay(pdMS_TO_TICKS(1000));
            digitalWrite(LED_GREEN, LOW);

            // Give the semaphore once
            xSemaphoreGive(xButtonSemaphore);

            // Wait for the button to be released to prevent multiple semaphore signals
            while (digitalRead(BUTTON_PIN) == LOW) {
                vTaskDelay(pdMS_TO_TICKS(10));
            }
        }

        vTaskDelay(pdMS_TO_TICKS(10)); // Task recurrence
    }
}