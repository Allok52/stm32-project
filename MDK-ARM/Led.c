#include "led.h"

void LedLight(int num)
{
	switch(num)
	{
		case 1:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);break;
		case 2:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);break;
		case 3:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);break;
		}
}

void LedDark(int num)
{
	switch(num)
	{
		case 1:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,0);break;
		case 2:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,0);break;
		case 3:HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,0);break;
		}
}


