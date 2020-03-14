/*
 * led_statistics.h
 *
 *  Created on: 14.03.2020
 *      Author: hslu
 */

#ifndef LED_LED_STATISTICS_H_
#define LED_LED_STATISTICS_H_

#include "led/led_helper.h"

#include <stdint.h>

struct LedStatistics {
	uint32_t FrontLeftRed;
	uint32_t FrontLeftGreen;
	uint32_t FrontLeftBlue;

	uint32_t FrontRightRed;
	uint32_t FrontRightGreen;
	uint32_t FrontRightBlue;

	uint32_t RearLeftLight;
	uint32_t RearLeftBrake;

	uint32_t RearRightLight;
	uint32_t RearRightBrake;
};

void print_led_stats();

void update_led_stats_front(struct FrontColor color);

void update_led_stats_rear(struct RearColor color);

#endif /* LED_LED_STATISTICS_H_ */
