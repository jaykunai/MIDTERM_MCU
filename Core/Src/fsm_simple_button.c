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
		if(timer1_flag == 1){
			status = TIME_OUT;
			setTimer1(1000);
		}
		if(is_button_pressed(0) == 1){
			counterLed = 0;
			display7SEG(counterLed);
			setTimer1(10000);
		}
		if(is_button_pressed(1) == 1){
			counterLed++;
			display7SEG(counterLed);
			setTimer1(10000);
			status = INC_IS_PRESSED;
		}
		if(is_button_pressed(2) == 1){
				counterLed = 9;
				setTimer1(10000);
				status = DEC_IS_PRESSED;
		}
		break;
	case INC_IS_PRESSED:
		if(timer1_flag == 1){
			status = TIME_OUT;
			setTimer1(1000);
		}
		//if INC button is being long pressed
		if(is_long_pressed(1) == 1){
			setTimer1(10000);
			status = INC_LONG_PRESSED;
		}
		// INC button is being pressed
		if(is_button_pressed(1) == 1){
			counterLed++;
			if(counterLed > 9) counterLed = 0;
			display7SEG(counterLed);
			setTimer1(10000);
		}
		if(is_button_pressed(0) == 1){
			setTimer1(10000);
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
			setTimer1(10000);
			status = DEC_IS_PRESSED;
		}
		break;
	case DEC_IS_PRESSED:
		if(timer1_flag == 1){
			status = TIME_OUT;
			setTimer1(1000);
		}
		//if INC button is being long pressed
		if(is_long_pressed(2) == 1){
			setTimer1(10000);
			status = DEC_LONG_PRESSED;
		}
		// DEC_BUTTON is being pressed
		if(is_button_pressed(2) == 1){
			if(counterLed > 0) counterLed--;
			else{
				counterLed = 9;
			}
			display7SEG(counterLed);
			setTimer1(10000);
		}
		if(is_button_pressed(1) == 1){
			if(counterLed == 9){
				counterLed = 0;
			}else{
				counterLed++;
			}
			display7SEG(counterLed);
			setTimer1(10000);
			status = INC_IS_PRESSED;
		}
		if(is_button_pressed(0) == 1){
			counterLed = 0;
			display7SEG(counterLed);
			setTimer1(10000);
			status = RESET_IS_PRESSED;
		}
		break;
	case TIME_OUT:
		if(is_button_pressed(1) == 1){
			counterLed++;
			if(counterLed > 9) counterLed = 0;
			display7SEG(counterLed);
			setTimer1(10000);
			status = INC_IS_PRESSED;
		}
		if(is_button_pressed(2) == 1){
			if(counterLed > 0){
				counterLed--;
			}else{
				counterLed = 9;
			}
			setTimer1(10000);
			status = DEC_IS_PRESSED;
		}
		if(timer1_flag == 1){
			if(counterLed > 0) counterLed--;
			display7SEG(counterLed);
			setTimer1(1000);
		}
		break;
	default:
		break;
	}

}
