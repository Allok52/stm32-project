#ifndef __COMTOANDROID_H__
#define __COMTOANDROID_H__

#include "stm32l4xx_hal.h"

void MessageProcess(void);

extern uint8_t Mode;//Mode 1ά�� Mode 0��������
extern uint8_t IsReStart;//1���� 0������
extern uint8_t Motor_cmd;
extern uint8_t txbuf[5];
extern uint8_t color;
extern uint8_t Distance;
extern uint8_t RGB_R;
extern uint8_t RGB_G;
extern uint8_t RGB_B;

#endif



