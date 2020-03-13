#ifndef _LED_H_
#define _LED_H_

#include <stdbool.h>
#include <stdint.h>

enum LED {
	REAR_BRAKE_R,
	REAR_R,
	REAR_BRAKE_L,
	REAR_L,
	FRONT_GREEN_L,
	FRONT_RED_L,
	FRONT_BLUE_L,
	REAR_GREEN_R,
	REAR_BLUE_R,
	REAR_RED_R
};

void toggle_led(enum LED led, bool led_state);

void front_left(bool r, bool g, bool b);
void front_right(bool r, bool g, bool b);
void rear_left(bool light, bool brake);
void rear_right(bool light, bool brake);

void leds_test(uint16_t delay_ms);

#endif
