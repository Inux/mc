/*
 * joystick.c
 *
 *  Created on: 13.03.2020
 *      Author: hslu
 */
#include "joystick.h"

#include "pin_mux.h"
#include "fsl_gpio.h"

enum JoyStickPos getPos() {
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
