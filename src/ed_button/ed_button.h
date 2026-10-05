#ifndef ED_BUTTON_H
#define ED_BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(int pin, unsigned long debounceDelay = 50);
    void begin();
    bool isPressed();

private:
    int _pin;
    unsigned long _debounceDelay;
    unsigned long _lastDebounceTime = 0;
    bool _lastState = HIGH;
};

#endif