#include "MainProcess.h"

#include "Common.h"
#include <stdlib.h>

uint8_t choose_flag = 0;
uint8_t Getnumber_flag = 0;
uint8_t MotorBeChoosed;
int GameNumber = 0;
unsigned long int seed = 0;

uint8_t IsRight;

int GetGameNumber(void)
{
	uint8_t Number;
	srand(seed);
	Number = rand()%3 + 1;
	return Number;
}

void GameControl(void)
{
	if(Mode == 0|Mode == 1)
	{
		if(SensorData[0]|SensorData[1]|SensorData[2])
		{
			choose_flag = 1;
			if(Getnumber_flag != 2)
			{
				Getnumber_flag = 1;
			}
		}
		if(Getnumber_flag == 1)
		{
			GameNumber = GetGameNumber();
			Getnumber_flag = 2;
		}
		if(choose_flag == 1)
		{
			LedLight(GameNumber);
			ChooseMotor();
			Check();
		}
		MotorBack();
		Restart();
	}
	else if(Mode == 2)
	{
		if(Motor_cmd == 2)
		{
			MotorStart(1);
			MotorStart(2);
			MotorStart(3);
			HAL_Delay(500);
			MotorStop(1);
			MotorStop(2);
			MotorStop(3);
		}
	}
}

void ChooseMotor(void)
{
	if(SensorData[0]==1)
	{
		MotorBeChoosed = 1;
	}		
	else if(SensorData[1]==1) 
	{
		MotorBeChoosed = 2;
	}				
	else if(SensorData[2]==1)
	{
		MotorBeChoosed = 3;
	}
	else
	{
		MotorBeChoosed = 0;
	}
}

void Check(void)
{
	if(MotorBeChoosed == GameNumber)
	{
		IsRight = 2;
	}
	else
	{
		IsRight = 1;
	}
}

void MotorBack(void)
{
	if(IsReStart == 1)
	{
		MotorStart(MotorBeChoosed);
		HAL_Delay(1500);
		MotorStop(MotorBeChoosed);
	}
}

void Restart(void)
{
	if(IsReStart == 1)
	{
		IsRight = 0;
		IsReStart = 0;
		MotorBeChoosed = 0;
		Getnumber_flag = 0;
		UserID = 0;
		choose_flag = 0;
		GameNumber = 0;
		LedDark(1);
		LedDark(2);
		LedDark(3);
	}
	else
	{
		uint8_t jkjk;
	}
}













