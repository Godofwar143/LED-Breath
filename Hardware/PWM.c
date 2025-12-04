#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
//开启RCC时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//选择内部时钟
	TIM_InternalClockConfig(TIM2);
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	//选择分频系数
	TIM_TimeBaseInitStruct.TIM_ClockDivision= TIM_CKD_DIV1;
	//选择计数模式
	TIM_TimeBaseInitStruct.TIM_CounterMode= TIM_CounterMode_Up;
	//ARR自动重装器的值
	TIM_TimeBaseInitStruct.TIM_Period= 100 - 1;
	//PSC预分频器的值
	TIM_TimeBaseInitStruct.TIM_Prescaler= 720 - 1;
	//重复计数器的值
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter= 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	

	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	
	
	
	//启动定时器
	TIM_Cmd(TIM2,ENABLE);

	
}

void PWM_SetCompare1(uint16_t compare)
{
	TIM_SetCompare1(TIM2,compare);
}
