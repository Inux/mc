/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    JoystickAndLEDs.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK22F51212.h"

#include "joystick/joystick.h"
#include <led/led_helper.h>
#include "led/led_statistics.h"

#include <time.h>

int main(void) {
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    leds_off();

    //printf("LEDs test...");
    //leds_test(2500);

    printf("Reading JoyStick\n");

    time_t lastStatsUpdate = time(NULL);
	print_led_stats();

    while(true) {
    	enum JoyStickPos pos = getPos();

		switch(pos) {
		case UP:
			printf("UP - leds_front_on()\n");
			leds_front_on();
			break;
		case RIGHT:
			printf("RIGHT - leds_front_next()\n");
			leds_front_next();
			break;
		case DOWN:
			printf("DOWN - leds_rear_next()\n");
			leds_rear_next();
			leds_rear_on();
			break;
		case LEFT:
			printf("LEFT - leds_front_last()\n");
			leds_front_last();
			break;
		case PUSH:
			printf("PUSH - leds_off()\n");
			leds_off();
			break;
		case NONE:
		default:
			break;
		}

		time_t currentTime = time(NULL);
		if((currentTime - lastStatsUpdate) > 10) {
			print_led_stats();
			lastStatsUpdate = currentTime;
		}
    }
	return 0;
}
