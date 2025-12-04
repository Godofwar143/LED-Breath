#include "stm32f10x.h"                  // Device header
/**
  * 函    数：LED初始化
  * 参    数：无
  * 返 回 值：无
  */
void LED_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//开启GPIOA的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//将PA1和PA2引脚初始化为推挽输出
	
	/*设置GPIO初始化后的默认电平*/
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);				//设置PA1和PA2引脚为高电平
}
/**
  * @brief  点亮LED1
  * @param  无
  * @retval 无
  */
void LED1_ON(void)//Open LED1
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}
/**
  * @brief  关闭LED1
  * @param  无
  * @retval 无
  */
void LED1_OFF(void)//Close LED1
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}
/**
  * @brief  反转LED1的电平
  * @param  无
  * @retval 无
  */
void LED1_Turn()
{
	
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1) == 1)
	{
			GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	}
	else
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
	}
}
/**
  * @brief  点亮LED2
  * @param  无
  * @retval 无
  */
void LED2_ON(void)//Open LED2
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}
/**
  * @brief  关闭LED2
  * @param  无
  * @retval 无
  */
void LED2_OFF(void)//Close LED2
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}
/**
  * @brief  反转LED2的电平
  * @param  无
  * @retval 无
  */
void LED2_Turn()
{
	
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2) == 1)
	{
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	}
	else
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
	}
}

