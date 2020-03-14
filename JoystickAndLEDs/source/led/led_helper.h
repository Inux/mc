/*
 * led_helper.h
 *
 *  Created on: 13.03.2020
 *      Author: hslu
 */

#ifndef LED_LED_HELPER_H_
#define LED_LED_HELPER_H_

#include <stdbool.h>
#include <stdint.h>

struct FrontColor {
	bool r;
	bool g;
	bool b;
};

struct RearColor {
	bool light;
	bool brake;
};

void leds_front_on();
void leds_front_next();
void leds_front_last();

void leds_rear_on();
void leds_rear_next();

void leds_off();


#endif /* LED_LED_HELPER_H_ */
