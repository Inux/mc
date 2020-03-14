#ifndef _LED_H_
#define _LED_H_

#include <stdbool.h>
#include <stdint.h>

void leds_front(bool r, bool g, bool b);
void led_front_left(bool r, bool g, bool b);
void led_front_right(bool r, bool g, bool b);
void leds_rear(bool light, bool brake);
void led_rear_left(bool light, bool brake);
void led_rear_right(bool light, bool brake);

void leds_test(uint16_t delay_ms);

#endif
