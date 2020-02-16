#ifndef __INFRAREDSENSOR_H__
#define __INFRAREDSENSOR_H__

#include <stdint.h>
#include "stm32l4xx_hal.h"

void GetSensorData(void);
extern uint8_t SensorData[3];


#endif

