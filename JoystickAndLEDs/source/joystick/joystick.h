/*
 * break.h
 *
 *  Created on: 13.03.2020
 *      Author: hslu
 */

#ifndef CAR_JOYSTICK_H_
#define CAR_JOYSTICK_H_

#include <stdbool.h>

enum JoyStickPos {
	UP,
	RIGHT,
	DOWN,
	LEFT,
	PUSH,
	NONE
};

enum JoyStickPos getPos();
bool isUp();
bool isRight();
bool isDown();
bool isLeft();
bool isPush();



#endif /* CAR_JOYSTICK_H_ */
