#include "ComToFPGA.h"

void MotorStart(int cs)
{
	switch(cs)
	{
		case 1:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,1);break;
		case 2:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,1);break;
		case 3:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,1);break;
		}
}

void MotorStop(int cs)
{
	switch(cs)
	{
		case 1:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,0);break;
		case 2:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,0);break;
		case 3:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,0);break;
		}
}

