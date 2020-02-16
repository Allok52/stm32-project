#ifndef __I2C_2_H__
#define	__I2C_2_H__
/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include <inttypes.h>

/* 类型定义 ------------------------------------------------------------------*/
/* 宏定义 --------------------------------------------------------------------*/
#define I2C_2_OWN_ADDRESS                            0x0A

#define I2C_WR	        0		/* 写控制bit */
#define I2C_RD	        1		/* 读控制bit */

#define I2C_2_GPIO_CLK_ENABLE()               __HAL_RCC_GPIOC_CLK_ENABLE()
#define I2C_2_GPIO_PORT                       GPIOC   
#define I2C_2_SCL_PIN                         GPIO_PIN_10
#define I2C_2_SDA_PIN                         GPIO_PIN_12

#define I2C_2_SCL_HIGH()                      HAL_GPIO_WritePin(I2C_2_GPIO_PORT,I2C_2_SCL_PIN,GPIO_PIN_SET)    // 输出高电平
#define I2C_2_SCL_LOW()                       HAL_GPIO_WritePin(I2C_2_GPIO_PORT,I2C_2_SCL_PIN,GPIO_PIN_RESET)  // 输出低电平
#define I2C_2_SDA_HIGH()                      HAL_GPIO_WritePin(I2C_2_GPIO_PORT,I2C_2_SDA_PIN,GPIO_PIN_SET)    // 输出高电平
#define I2C_2_SDA_LOW()                       HAL_GPIO_WritePin(I2C_2_GPIO_PORT,I2C_2_SDA_PIN,GPIO_PIN_RESET)  // 输出低电平
#define I2C_2_SDA_READ()                      HAL_GPIO_ReadPin(I2C_2_GPIO_PORT,I2C_2_SDA_PIN)

/* 扩展变量 ------------------------------------------------------------------*/
/* 函数声明 ------------------------------------------------------------------*/
void    I2C_2_Start(void);
void    I2C_2_Stop(void);
void    I2C_2_SendByte(uint8_t _ucByte);
uint8_t I2C_2_ReadByte(uint8_t ack);
uint8_t I2C_2_WaitAck(void);
void    I2C_2_Ack(void);
void    I2C_2_NAck(void);
uint8_t I2C_2_CheckDevice(uint8_t _Address);
void I2C_2_InitGPIO(void);


#endif /* __I2C_EEPROM_H__ */

/******************* (C) COPYRIGHT 2015-2020 硬石嵌入式开发团队 *****END OF FILE****/

