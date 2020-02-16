#include "Button.h"

uint8_t	UserID=0x00;
uint8_t test[4];
void ButtonToID(void)
{
	test[0] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11);
	test[1] = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12);
	test[2] = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_11);
	test[3] = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_12);
//	UserID = test[0]|test[1]<<1|test[2]<<2|test[3]<<3;
}

