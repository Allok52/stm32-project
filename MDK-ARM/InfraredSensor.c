#include "InfraredSensor.h"

uint8_t SensorData[3]={0};

void GetSensorData(void)
{
	SensorData[0] = !(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13));
	SensorData[1] = !(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_14));
	SensorData[2] = !(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_15));
}


