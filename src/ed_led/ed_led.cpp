#include "ed_led.h"

void ed_led_init(uint8_t pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void ed_led_on(uint8_t pin) {
    digitalWrite(pin, HIGH);
}

void ed_led_off(uint8_t pin) {
    digitalWrite(pin, LOW);
}

void ed_led_toggle(uint8_t pin) {
    digitalWrite(pin, !digitalRead(pin));
}