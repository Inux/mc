#include <led/leds.h>
#include <utils/sleep.h>
#include "pin_mux.h"
#include "fsl_gpio.h"


void leds_front(bool r, bool g, bool b) {
	led_front_left(r, g, b);
	led_front_right(r, g, b);
}

void led_front_left(bool r, bool g, bool b) {
	GPIO_PinWrite(BOARD_LED_RED_F_L_GPIO, BOARD_LED_RED_F_L_PIN, !r);
	GPIO_PinWrite(BOARD_LED_GREEN_F_L_GPIO, BOARD_LED_GREEN_F_L_PIN, !g);
	GPIO_PinWrite(BOARD_LED_BLUE_F_L_GPIO, BOARD_LED_BLUE_F_L_PIN, !b);
}

void led_front_right(bool r, bool g, bool b){
	GPIO_PinWrite(BOARD_LED_RED_F_R_GPIO, BOARD_LED_RED_F_R_PIN, !r);
	GPIO_PinWrite(BOARD_LED_GREEN_F_R_GPIO, BOARD_LED_GREEN_F_R_PIN, !g);
	GPIO_PinWrite(BOARD_LED_BLUE_F_R_GPIO, BOARD_LED_BLUE_F_R_PIN, !b);
}

void leds_rear(bool light, bool brake) {
	led_rear_left(light, brake);
	led_rear_right(light, brake);
}

void led_rear_left(bool light, bool brake) {
	GPIO_PinWrite(BOARD_LED_RED_R_L_GPIO, BOARD_LED_RED_R_L_PIN, !light);
	GPIO_PinWrite(BOARD_LED_RED_R_L_BREAK_GPIO, BOARD_LED_RED_R_L_BREAK_PIN, !brake);
}

void led_rear_right(bool light, bool brake) {
	GPIO_PinWrite(BOARD_LED_RED_R_R_GPIO, BOARD_LED_RED_R_R_PIN, !light);
	GPIO_PinWrite(BOARD_LED_RED_R_R_BREAK_GPIO, BOARD_LED_RED_R_R_BREAK_PIN, !brake);
}

void leds_test(uint16_t delay_ms) {
	//test all front left LEDs (from r to b)
	led_front_left(true, false, false);
	sleep(delay_ms);
	led_front_left(false, true, false);
	sleep(delay_ms);
	led_front_left(false, false, true);
	sleep(delay_ms);
	led_front_left(false, false, false);

	//test all front right LEDS (from r to b)
	led_front_right(true, false, false);
	sleep(delay_ms);
	led_front_right(false, true, false);
	sleep(delay_ms);
	led_front_right(false, false, true);
	sleep(delay_ms);
	led_front_right(false, false, false);

	//test all rear left LEDS (light then brake)
	led_rear_left(true, false);
	sleep(delay_ms);
	led_rear_left(false, true);
	sleep(delay_ms);
	led_rear_left(true, true);
	sleep(delay_ms);
	led_rear_left(false, false);

	//test all rear right LEDS (light then brake)
	led_rear_right(true, false);
	sleep(delay_ms);
	led_rear_right(false, true);
	sleep(delay_ms);
	led_rear_right(true, true);
	sleep(delay_ms);
	led_rear_right(false, false);

	sleep(50);
}
