/*
 * led_statistics.c
 *
 *  Created on: 14.03.2020
 *      Author: hslu
 */

#include "led/led_statistics.h"

#include "led/led_helper.h"

#include <stdio.h>

static volatile struct LedStatistics LedStats = {0,0,0, 0,0,0, 0,0, 0,0};

void print_led_stats() {
	char* format = "LED Statistic: \n\n"
			   "Front Left: \n"
				"\tRed:       %d\n"
				"\tGreen:     %d\n"
				"\tBlue:      %d\n"

				"Front Right: \n"
				"\tRed:       %d\n"
				"\tGreen:     %d\n"
				"\tBlue:      %d\n"

				"Rear Left: \n"
				"\tLight:     %d\n"
				"\tBrake:     %d\n"

				"Rear Right: \n"
				"\tLight:     %d\n"
				"\tBrake:     %d\n";

	printf(format,
	 LedStats.FrontLeftRed,
	 LedStats.FrontLeftGreen,
	 LedStats.FrontLeftBlue,
	 LedStats.FrontRightRed,
	 LedStats.FrontRightGreen,
	 LedStats.FrontRightBlue,
	 LedStats.RearLeftLight,
	 LedStats.RearLeftBrake,
	 LedStats.RearRightLight,
	 LedStats.RearRightBrake);
}

void update_led_stats_front(struct FrontColor color) {
	static struct FrontColor actualColor = {false, false, false};

	if(color.r == true && actualColor.r == false) {
		LedStats.FrontLeftRed++;
		LedStats.FrontRightRed++;
	}
	if(color.g == true && actualColor.g == false) {
		LedStats.FrontLeftGreen++;
		LedStats.FrontRightGreen++;
	}
	if(color.b == true && actualColor.b == false) {
		LedStats.FrontLeftBlue++;
		LedStats.FrontRightBlue++;
	}

	actualColor = color;
}

void update_led_stats_rear(struct RearColor color) {
	static struct RearColor actualColor = {false, false};

	if(color.light == true && actualColor.light == false) {
		LedStats.RearLeftLight++;
		LedStats.RearRightLight++;
	}
	if(color.brake == true && actualColor.brake == false) {
		LedStats.RearLeftBrake++;
		LedStats.RearRightBrake++;
	}

	actualColor = color;
}
