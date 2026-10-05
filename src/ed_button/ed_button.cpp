#include "ed_button.h"

Button::Button(int pin, unsigned long debounceDelay)
    : _pin(pin), _debounceDelay(debounceDelay) {}

void Button::begin() {
    pinMode(_pin, INPUT_PULLUP);
}

bool Button::isPressed() {
    bool reading = digitalRead(_pin);
    
    if (reading != _lastState) {
        _lastDebounceTime = millis();
    }

    _lastState = reading;
    return (reading == LOW) && (millis() - _lastDebounceTime > _debounceDelay);
}