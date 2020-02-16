#include "tcs34725.h"
#include "ComToAndroid.h"

void TCS34725_WriteReg(uint8_t reg_add,uint8_t reg_dat)
{
	I2C_Start();
	I2C_SendByte(TCS34725_ADDRESS << 1);
	I2C_WaitAck();
	I2C_SendByte(reg_add|TCS34725_COMMAND_BIT);//根据手册，发送需操作的地址时应使最高为置为1
	I2C_WaitAck();
	I2C_SendByte(reg_dat);
	I2C_WaitAck();
	I2C_Stop();
}

void TCS34725_ReadData(uint8_t reg_add,uint8_t *Read,uint8_t num)
{
	unsigned char i;
	
	I2C_Start();
	I2C_SendByte(TCS34725_ADDRESS << 1);
	I2C_WaitAck();
	I2C_SendByte(reg_add|TCS34725_COMMAND_BIT);
	I2C_WaitAck();
	
	I2C_Start();
	I2C_SendByte(TCS34725_ADDRESS << 1 | 0x01);//iic最后一位1代表读，0代表写
	I2C_WaitAck();
	
	for(i=0;i<(num-1);i++){
		*Read=I2C_ReadByte(1);
		Read++;
	}
	*Read=I2C_ReadByte(0);
	I2C_Stop();
}

void TCS34725_Init(void)
{
  int i=0,j=0;
  for(i=0;i<1000;i++)
  {
    for(j=0;j<1000;j++)
    {
      ;
    }
  }
	TCS34725_WriteReg(TCS34725_ATIME,TCS34725_INTEGRATIONTIME_154MS);//设置积分时间
	TCS34725_WriteReg(TCS34725_CONTROL,TCS34725_GAIN_16X);//设置增益
	
}
	uint8_t ID = 0;
void TCS34725_ReadID(void)
{
	TCS34725_ReadData(TCS34725_ID,&ID,1);
	
//	if(ID == 0x44)
//	{
//		printf("Search sucessed\n");
//	}
}

	RGB_t RGB_Value;
	uint8_t temp[6];
void TCS34725_GetRGB(void)
{
	TCS34725_ReadData(TCS34725_RDATAL,temp,6);
	RGB_Value.RED = (temp[1] <<8 | temp[0])/128;
	RGB_Value.GREEN = (temp[3] << 8 | temp[2])/128;
	RGB_Value.BLUE = (temp[5] << 8 | temp[4])/128;
	printf("R=%d G=%d B=%d\n",RGB_Value.RED,RGB_Value.GREEN,RGB_Value.BLUE);
	RGB_R = RGB_Value.RED;
	RGB_G = RGB_Value.GREEN;
	RGB_B = RGB_Value.BLUE;
	if(RGB_Value.RED > 255)
	{
		RGB_R = 255;
	}
	if(RGB_Value.GREEN > 255)
	{
		RGB_G = 255;
	}
	if(RGB_Value.BLUE > 255)
	{
		RGB_B = 255;
	}
	if(RGB_Value.RED > RGB_Value.GREEN && RGB_Value.RED > RGB_Value.BLUE)
	{
		color = 0x0;
	}
	if(RGB_Value.GREEN > RGB_Value.RED && RGB_Value.GREEN > RGB_Value.BLUE)
	{
		color = 0x1;
	}
	if(RGB_Value.BLUE > RGB_Value.GREEN && RGB_Value.BLUE > RGB_Value.RED)
	{
		color = 0x2;
	}
}

void TCS34725_Enable(void)
{
	TCS34725_WriteReg(TCS34725_ENABLE, TCS34725_ENABLE_PON);
	//delay_ms(3);//延时应该放在设置AEN之后
	TCS34725_WriteReg(TCS34725_ENABLE, TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN);
	HAL_Delay(3);
}

void TCS34725_Disable(void)
{
	TCS34725_WriteReg(TCS34725_ENABLE, 0x00);
	TCS34725_WriteReg(TCS34725_ENABLE, 0x00 & ~(TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN));
}


