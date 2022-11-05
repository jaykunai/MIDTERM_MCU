/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Acer
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"

#define INIT 1
#define RESET_IS_PRESSED 2
#define INC_IS_PRESSED 3
#define DEC_IS_PRESSED 4
#define TIME_OUT 5

#define INC_LONG_PRESSED 7
#define DEC_LONG_PRESSED 8
#define BOTH_LONG_PRESSED 9

extern int status;
extern int counterLed;

#endif /* INC_GLOBAL_H_ */
