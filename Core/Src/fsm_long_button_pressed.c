/*
 * fsm_long_button_pressed.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Acer
 */

#include "fsm_long_button_pressed.h"

void fsm_long_button_pressed_run(){
	switch(status){
	case INC_LONG_PRESSED:
		if(is_long_pressed(1) == 1){
			if(is_1s(1) == 1){
				counterLed++;
				if(counterLed > 9) counterLed = 0;
		}
			display7SEG(counterLed);
	}
		//release button
		if(is_long_pressed(1) == 0){
			display7SEG(counterLed);
			status = INIT;
		}
		break;
	case DEC_LONG_PRESSED:
		if(is_long_pressed(2) == 1){
			if(is_1s(2) == 1){
				if(counterLed > 0){
					counterLed--;
			}else{
				counterLed = 9;
			}
		}
			display7SEG(counterLed);
	}
		//release button
		if(is_long_pressed(2) == 0){
			display7SEG(counterLed);
			status = INIT;
		}
		break;
	default:
		break;
	}
}
