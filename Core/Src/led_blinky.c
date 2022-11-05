/*
 * led_blinky.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Acer
 */
#include "led_blinky.h"

void led_Blinky(){
	switch(status){
	case INIT:
	case RESET_IS_PRESSED:
	case INC_IS_PRESSED:
	case DEC_IS_PRESSED:
	case TIME_OUT:
		if(timer2_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			setTimer2(100);
		}
	break;
	case INC_LONG_PRESSED:
	case DEC_LONG_PRESSED:
		if(timer2_flag == 1){
					HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
					setTimer2(1000);
				}
	    break;
	default:
		break;
	}
}

