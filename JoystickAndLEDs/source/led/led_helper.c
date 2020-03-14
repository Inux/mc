/*
 * led_helper.c
 *
 *  Created on: 13.03.2020
 *      Author: hslu
 */
#include "led/leds.h"
#include <led/led_helper.h>
#include <led/leds.h>
#include <led/led_statistics.h>


// Front LEDs

const uint8_t FRONT_COLOR_COUNT = 7;
const struct FrontColor front_colors[7] = {
	{false, false,  true},
	{false,  true, false},
	{false,  true,  true},
	{ true, false, false},
	{ true, false,  true},
	{ true,  true, false},
	{ true,  true,  true}
};

static volatile bool ledsFrontOn = false;
static volatile int8_t front_color_current = 0;

void leds_front_on() {
	struct FrontColor color = front_colors[front_color_current];
	leds_front(color.r, color.g, color.b);
	ledsFrontOn = true;
	update_led_stats_front(color);
}

void leds_front_next() {
	if(!ledsFrontOn) {
		return;
	}

	++front_color_current;
	if(front_color_current >= FRONT_COLOR_COUNT) {
		front_color_current = 0;
	}
	leds_front_on();
}

void leds_front_last() {
	if(!ledsFrontOn) {
		return;
	}

	--front_color_current;
	if(front_color_current < 0) {
		front_color_current = (FRONT_COLOR_COUNT-1);
	}
	leds_front_on();
}


// Rear LEDs

const uint8_t REAR_COLOR_COUNT = 2;
const struct RearColor rear_colors[2] = {
	{ true, false},
	{ true,  true}
};

static volatile bool ledsRearOn = false;
static volatile uint8_t rear_color_current = 0;

void leds_rear_on() {
	struct RearColor color = rear_colors[rear_color_current];
	leds_rear(color.light, color.brake);
	ledsRearOn = true;
	update_led_stats_rear(color);
}

void leds_rear_next() {
	if(!ledsRearOn) {
		return;
	}

	++rear_color_current;
	if(rear_color_current >= REAR_COLOR_COUNT) {
		rear_color_current = 0;
	}
	leds_rear_on();
}


// Common methods

void leds_off() {
	leds_front(false, false, false);
	ledsFrontOn = false;

	leds_rear(false, false);
	ledsRearOn = false;
}
