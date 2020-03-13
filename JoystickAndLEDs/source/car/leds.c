#include <car/leds.h>
#include <utils/sleep.h>
#include "pin_mux.h"
#include "fsl_gpio.h"


void toggle_led(enum LED led, bool led_state) {
	switch (led) {
		case REAR_BRAKE_R:
	  		GPIO_PinWrite(BOARD_LED_RED_R_R_BREAK_GPIO, BOARD_LED_RED_R_R_BREAK_PIN, led_state);
			break;
		case REAR_R:
	  		GPIO_PinWrite(BOARD_LED_RED_R_R_GPIO, BOARD_LED_RED_R_R_PIN, led_state);
			break;
		case REAR_BRAKE_L:
	  		GPIO_PinWrite(BOARD_LED_RED_R_L_BREAK_GPIO, BOARD_LED_RED_R_L_BREAK_PIN, led_state);
			break;
		case REAR_L:
	        GPIO_PinWrite(BOARD_LED_RED_R_L_GPIO, BOARD_LED_RED_R_L_PIN, led_state);
			break;
		case FRONT_GREEN_L:
	    	GPIO_PinWrite(BOARD_LED_GREEN_F_L_GPIO, BOARD_LED_GREEN_F_L_PIN, led_state);
			break;
		case FRONT_RED_L:
	        GPIO_PinWrite(BOARD_LED_RED_F_L_GPIO, BOARD_LED_RED_F_L_PIN, led_state);
			break;
		case FRONT_BLUE_L:
	  		GPIO_PinWrite(BOARD_LED_BLUE_F_L_GPIO, BOARD_LED_BLUE_F_L_PIN, led_state);
			break;
		case REAR_GREEN_R:
	    	GPIO_PinWrite(BOARD_LED_GREEN_F_R_GPIO, BOARD_LED_GREEN_F_R_PIN, led_state);
	    	break;
		case REAR_BLUE_R:
	  		GPIO_PinWrite(BOARD_LED_BLUE_F_R_GPIO, BOARD_LED_BLUE_F_R_PIN, led_state);
			break;
		case REAR_RED_R:
	  		GPIO_PinWrite(BOARD_LED_RED_F_R_GPIO, BOARD_LED_RED_F_R_PIN, led_state);
			break;
		default:
	  		break;
	}
}

void front_left(bool r, bool g, bool b) {
	GPIO_PinWrite(BOARD_LED_RED_F_L_GPIO, BOARD_LED_RED_F_L_PIN, !r);
	GPIO_PinWrite(BOARD_LED_GREEN_F_L_GPIO, BOARD_LED_GREEN_F_L_PIN, !g);
	GPIO_PinWrite(BOARD_LED_BLUE_F_L_GPIO, BOARD_LED_BLUE_F_L_PIN, !b);
}

void front_right(bool r, bool g, bool b){
	GPIO_PinWrite(BOARD_LED_RED_F_R_GPIO, BOARD_LED_RED_F_R_PIN, !r);
	GPIO_PinWrite(BOARD_LED_GREEN_F_R_GPIO, BOARD_LED_GREEN_F_R_PIN, !g);
	GPIO_PinWrite(BOARD_LED_BLUE_F_R_GPIO, BOARD_LED_BLUE_F_R_PIN, !b);
}

void rear_left(bool light, bool brake) {
	GPIO_PinWrite(BOARD_LED_RED_R_L_GPIO, BOARD_LED_RED_R_L_PIN, !light);
	GPIO_PinWrite(BOARD_LED_RED_R_L_BREAK_GPIO, BOARD_LED_RED_R_L_BREAK_PIN, !brake);
}

void rear_right(bool light, bool brake) {
	GPIO_PinWrite(BOARD_LED_RED_R_R_GPIO, BOARD_LED_RED_R_R_PIN, !light);
	GPIO_PinWrite(BOARD_LED_RED_R_R_BREAK_GPIO, BOARD_LED_RED_R_R_BREAK_PIN, !brake);
}

void leds_test(uint16_t delay_ms) {
	//test all front left LEDs (from r to b)
	front_left(true, false, false);
	sleep(delay_ms);
	front_left(false, true, false);
	sleep(delay_ms);
	front_left(false, false, true);
	sleep(delay_ms);
	front_left(false, false, false);

	//test all front right LEDS (from r to b)
	front_right(true, false, false);
	sleep(delay_ms);
	front_right(false, true, false);
	sleep(delay_ms);
	front_right(false, false, true);
	sleep(delay_ms);
	front_right(false, false, false);

	//test all rear left LEDS (light then brake)
	rear_left(true, false);
	sleep(delay_ms);
	rear_left(false, true);
	sleep(delay_ms);
	rear_left(true, true);
	sleep(delay_ms);
	rear_left(false, false);

	//test all rear right LEDS (light then brake)
	rear_right(true, false);
	sleep(delay_ms);
	rear_right(false, true);
	sleep(delay_ms);
	rear_right(true, true);
	sleep(delay_ms);
	rear_right(false, false);

	sleep(50);
}
