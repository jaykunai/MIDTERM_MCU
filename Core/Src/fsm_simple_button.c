/*
 * fsm_simple_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Acer
 */


#include "fsm_simple_button.h"

void fsm_simple_button_run(){
	switch(status){
	case INIT:
		if(is_button_pressed(0) == 1 || is_button_pressed(2) == 1){
			counterLed = 0;
			status = RESET_IS_PRESSED;
		}
		if(is_button_pressed(1) == 1){
			counterLed++;
			if(counterLed > 9) counterLed = 0;
			display7SEG(counterLed);
			status = INC_IS_PRESSED;
		}
		break;
	case RESET_IS_PRESSED:
		if(is_button_pressed(0) == 1){
			counterLed = 0;
			display7SEG(counterLed);
		}
		if(is_button_pressed(1) == 1){
			counterLed++;
			display7SEG(counterLed);
			status = INC_IS_PRESSED;
		}
		if(is_button_pressed(2) == 1){
				counterLed = 9;
				status = DEC_IS_PRESSED;
		}
		break;
	case INC_IS_PRESSED:
		//if INC button is being long pressed
		if(is_long_pressed(1) == 1){
			status = INC_LONG_PRESSED;
		}
		// INC button is being pressed
		if(is_button_pressed(1) == 1){
			counterLed++;
			if(counterLed > 9) counterLed = 0;
			display7SEG(counterLed);
		}
		if(is_button_pressed(0) == 1){
			status = RESET_IS_PRESSED;
		}
		if(is_button_pressed(2) == 1){
			if(counterLed > 0){
				counterLed--;
			}
			else{
				counterLed = 9;
			}
			display7SEG(counterLed);
			status = DEC_IS_PRESSED;
		}
		break;
	case DEC_IS_PRESSED:
		//if INC button is being long pressed
		if(is_long_pressed(2) == 1){
			status = DEC_LONG_PRESSED;
		}
		// DEC_BUTTON is being pressed
		if(is_button_pressed(2) == 1){
			if(counterLed > 0) counterLed--;
			else{
				counterLed = 9;
			}
			display7SEG(counterLed);
		}
		if(is_button_pressed(1) == 1){
			if(counterLed == 9){
				counterLed = 0;
			}else{
				counterLed++;
			}
			display7SEG(counterLed);
			status = INC_IS_PRESSED;
		}
		if(is_button_pressed(0) == 1){
			counterLed = 0;
			display7SEG(counterLed);
			status = RESET_IS_PRESSED;
		}
		break;
	default:
		break;
	}

}
