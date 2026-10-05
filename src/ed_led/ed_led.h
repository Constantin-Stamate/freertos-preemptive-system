#ifndef ED_LED_H
#define ED_LED_H

#include <Arduino.h>

void ed_led_init(uint8_t pin);
void ed_led_on(uint8_t pin);
void ed_led_off(uint8_t pin);
void ed_led_toggle(uint8_t pin);

#endif