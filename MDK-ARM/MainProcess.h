#ifndef __MAINPROCESS_H__
#define __MAINPROCESS_H__

#include "stm32l4xx_hal.h"

extern unsigned long int seed;
extern int GameNumber;
extern uint8_t IsRight;

int GetGameNumber(void);
void ChooseMotor(void);
void Check(void);
void GameControl(void);
void MotorBack(void);
void Restart(void);

#endif
