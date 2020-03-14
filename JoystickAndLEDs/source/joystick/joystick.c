/*
 * joystick.c
 *
 *  Created on: 13.03.2020
 *      Author: hslu
 */
#include "joystick.h"

#include "pin_mux.h"
#include "fsl_gpio.h"

#include "utils/sleep.h"

const uint32_t DEBOUNCE_TIME_MS = 150;

enum JoyStickPos debounce(enum JoyStickPos pos);
enum JoyStickPos currentPos();

enum JoyStickPos getPos() {
	if(isUp()) {
		return debounce(UP);
	}
	if(isRight()) {
		return debounce(RIGHT);
	}
	if(isDown()) {
		return debounce(DOWN);
	}
	if(isLeft()) {
		return debounce(LEFT);
	}
	if(isPush()) {
		return debounce(PUSH);
	}
	return NONE;
}

enum JoyStickPos debounce(enum JoyStickPos pos) {
	sleep(DEBOUNCE_TIME_MS);
	if(pos == currentPos()) {
		return pos;
	}
	return NONE;
}

enum JoyStickPos currentPos() {
	if(isUp()) {
		return UP;
	}
	if(isRight()) {
		return RIGHT;
	}
	if(isDown()) {
		return DOWN;
	}
	if(isLeft()) {
		return LEFT;
	}
	if(isPush()) {
		return PUSH;
	}
	return NONE;
}

bool isUp() {
	if(GPIO_PinRead(BOARD_JOYSTICK_UP_GPIO, BOARD_JOYSTICK_UP_PIN) == 0) {
		return true;
	}
	return false;
}

bool isRight() {
	if(GPIO_PinRead(BOARD_JOYSTICK_RIGHT_GPIO, BOARD_JOYSTICK_RIGHT_PIN) == 0) {
		return true;
	}
	return false;
}

bool isDown() {
	if(GPIO_PinRead(BOARD_JOYSTICK_DOWN_GPIO, BOARD_JOYSTICK_DOWN_PIN) == 0) {
		return true;
	}
	return false;
}

bool isLeft() {
	if(GPIO_PinRead(BOARD_JOYSTICK_LEFT_GPIO, BOARD_JOYSTICK_LEFT_PIN) == 0) {
		return true;
	}
	return false;
}

bool isPush() {
	if(GPIO_PinRead(BOARD_JOYSTICK_PUSH_GPIO, BOARD_JOYSTICK_PUSH_PIN) == 0) {
		return true;
	}
	return false;
}
