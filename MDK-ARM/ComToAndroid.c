#include "ComToAndroid.h"
#include "Common.h"

uint8_t MesToAndroid[2];
uint8_t rxbuf;
uint8_t txbuf[5];

uint8_t Mode;//Mode 1维护 Mode 0正常运行
uint8_t IsReStart;//1重启 0不重启
uint8_t Motor_cmd;
uint8_t color;
uint8_t Distance;
uint8_t RGB_R;
uint8_t RGB_G;
uint8_t RGB_B;

void MessageProcess(void)
{
	Mode = rxbuf & 0x03;
	IsReStart = (rxbuf & 0x04) >> 2;
	Motor_cmd = rxbuf >> 4;
	
	
	txbuf[0] = (/*test[0]*/0|test[1]<<1|test[2]<<2|test[3]<<3) | color << 4 | IsRight << 6;
	txbuf[1] = Distance;
	txbuf[2] = RGB_R;
	txbuf[3] = RGB_G;
	txbuf[4] = RGB_B;
//	if(IsRight == 1)
//	{
//		IsRight = 0;
//	}
}
