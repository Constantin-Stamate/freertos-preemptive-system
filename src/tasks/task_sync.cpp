#include "task_sync.h"

void taskSync(void *pvParameters) {
    static uint8_t N = 0;

    pinMode(LED_RED, OUTPUT);

    for (;;) {
        // Wait for the semaphore from the button task
        if (xSemaphoreTake(xButtonSemaphore, portMAX_DELAY) == pdTRUE) {
            N++; // Increment N on button press

            // Send the sequence 1..N to the buffer immediately
            for (uint8_t i = 1; i <= N; i++) {
                xQueueSendToBack(xBufferQueue, &i, portMAX_DELAY);
                vTaskDelay(pdMS_TO_TICKS(50));
            }

            // Send 0 as the sequence end marker
            uint8_t endMarker = 0;
            xQueueSendToBack(xBufferQueue, &endMarker, portMAX_DELAY);

            // Blink the red LED N times
            for (uint8_t i = 0; i < N; i++) {
                digitalWrite(LED_RED, HIGH);
                vTaskDelay(pdMS_TO_TICKS(300));
                
                digitalWrite(LED_RED, LOW);
                vTaskDelay(pdMS_TO_TICKS(500));
            }

            digitalWrite(LED_RED, LOW);
        }
    }
}