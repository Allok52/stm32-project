#include "i2c_2.h"

static void I2C_2_Delay(void)
{
	uint8_t i;

	for (i = 0; i < 20; i++);
}

void I2C_2_Start(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C���������ź� */
	I2C_2_SDA_HIGH();
//	for(uint16_t j=0;j<100;j++) ;
	I2C_2_SCL_HIGH();
	I2C_2_Delay();
	I2C_2_SDA_LOW();
	I2C_2_Delay();
	I2C_2_SCL_LOW();
	I2C_2_Delay();
}


void I2C_2_Stop(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C����ֹͣ�ź� */
	I2C_2_SDA_LOW();
	I2C_2_SCL_HIGH();
	I2C_2_Delay();
	I2C_2_SDA_HIGH();
}

/**
  * ��������: CPU��I2C�����豸����8bit����
  * �������: Byte �� �ȴ����͵��ֽ�
  * �� �� ֵ: ��
  * ˵    ������
  */
void I2C_2_SendByte(uint8_t Byte)
{
	uint8_t i;

	/* �ȷ����ֽڵĸ�λbit7 */
	for (i = 0; i < 8; i++)
	{		
		if (Byte & 0x80)
		{
			I2C_2_SDA_HIGH();
		}
		else
		{
			I2C_2_SDA_LOW();
		}
		I2C_2_Delay();
		I2C_2_SCL_HIGH();
		I2C_2_Delay();	
		I2C_2_SCL_LOW();
		if (i == 7)
		{
			I2C_2_SDA_HIGH(); // �ͷ�����
		}
		Byte <<= 1;	/* ����һ��bit */
		I2C_2_Delay();
	}
}


/**
  * ��������: CPU��I2C�����豸��ȡ8bit����
  * �������: ��
  * �� �� ֵ: ����������
  * ˵    ������
  */
uint8_t I2C_2_ReadByte(uint8_t ack)
{
	uint8_t i;
	uint8_t value;

	/* ������1��bitΪ���ݵ�bit7 */
	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		I2C_2_SCL_HIGH();
		I2C_2_Delay();
		if (I2C_2_SDA_READ())
		{
			value++;
		}
		I2C_2_SCL_LOW();
		I2C_2_Delay();
	}
  if(ack==0)
		I2C_2_NAck();
	else
		I2C_2_Ack();
	return value;
}

/**
  * ��������: CPU����һ��ʱ�ӣ�����ȡ������ACKӦ���ź�
  * �������: ��
  * �� �� ֵ: ����0��ʾ��ȷӦ��1��ʾ��������Ӧ
  * ˵    ������
  */
uint8_t I2C_2_WaitAck(void)
{
	uint8_t re;

	I2C_2_SDA_HIGH();	/* CPU�ͷ�SDA���� */
	I2C_2_Delay();
	I2C_2_SCL_HIGH();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
	I2C_2_Delay();
	if (I2C_2_SDA_READ())	/* CPU��ȡSDA����״̬ */
	{
		re = 1;
	}
	else
	{
		re = 0;
	}
	I2C_2_SCL_LOW();
	I2C_2_Delay();
	return re;
}

/**
  * ��������: CPU����һ��ACK�ź�
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ������
  */
void I2C_2_Ack(void)
{
	I2C_2_SDA_LOW();	/* CPU����SDA = 0 */
	I2C_2_Delay();
	I2C_2_SCL_HIGH();	/* CPU����1��ʱ�� */
	I2C_2_Delay();
	I2C_2_SCL_LOW();
	I2C_2_Delay();
	I2C_2_SDA_HIGH();	/* CPU�ͷ�SDA���� */
}

/**
  * ��������: CPU����1��NACK�ź�
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ������
  */
void I2C_2_NAck(void)
{
	I2C_2_SDA_HIGH();	/* CPU����SDA = 1 */
	I2C_2_Delay();
	I2C_2_SCL_HIGH();	/* CPU����1��ʱ�� */
	I2C_2_Delay();
	I2C_2_SCL_LOW();
	I2C_2_Delay();	
}

/**
  * ��������: ����I2C���ߵ�GPIO������ģ��IO�ķ�ʽʵ��
  * �������: ��
  * �� �� ֵ: ��
  * ˵    ������
  */
void I2C_2_InitGPIO(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
  /* ��GPIOʱ�� */
	I2C_2_GPIO_CLK_ENABLE();

  GPIO_InitStruct.Pin = I2C_2_SCL_PIN|I2C_2_SDA_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(I2C_2_GPIO_PORT, &GPIO_InitStruct);

  /* ��һ��ֹͣ�ź�, ��λI2C�����ϵ������豸������ģʽ */
  I2C_2_Stop();
}

/**
  * ��������: ���I2C�����豸��CPU�����豸��ַ��Ȼ���ȡ�豸Ӧ�����жϸ��豸�Ƿ����
  * �������: _Address���豸��I2C���ߵ�ַ
  * �� �� ֵ: ����ֵ 0 ��ʾ��ȷ�� ����1��ʾδ̽�⵽
  * ˵    �����ڷ���I2C�豸ǰ�����ȵ��� I2C_CheckDevice() ���I2C�豸�Ƿ��������ú���������GPIO
  */
uint8_t I2C_2_CheckDevice(uint8_t _Address)
{
	uint8_t ucAck;

	I2C_2_InitGPIO();		/* ����GPIO */	
	I2C_2_Start();		/* ���������ź� */
	/* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
	I2C_2_SendByte(_Address | I2C_WR);
	ucAck = I2C_2_WaitAck();	/* ����豸��ACKӦ�� */
	I2C_2_Stop();			/* ����ֹͣ�ź� */
	return ucAck;
}

