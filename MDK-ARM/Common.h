#ifndef __COMMON_H__
#define __COMMON_H__

#include "stm32l4xx_hal.h"

#include <stdlib.h>

#include "MainProcess.h"
#include "Button.h"
#include "ComToFPGA.h"
#include "ComToAndroid.h"
#include "InfraredSensor.h"
#include "tcs34725.h"
#include "VL6180.h"
#include "Led.h"


#define Rxbuf_Size	1
extern uint8_t choose_flag ;

extern uint8_t rxbuf;


#endif

