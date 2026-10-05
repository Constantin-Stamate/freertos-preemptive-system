#include "task_async.h"

void taskAsync(void *pvParameters) {
    uint8_t val;

    for (;;) {
        // Read the buffer every 200 ms
        if (xQueueReceive(xBufferQueue, &val, 0) == pdTRUE) {
            do {
                if (val == 0) {
                    Serial.println(); // New line after sequence
                    break;
                }

                Serial.print(val);
                Serial.print(" ");
            } while (xQueueReceive(xBufferQueue, &val, 0) == pdTRUE);
        }

        vTaskDelay(pdMS_TO_TICKS(200));
    }
}