#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "OLED.h"
#include "PWM.h"

uint16_t i;
int main(void)
{
	OLED_Init();
	PWM_Init();
	OLED_ShowString(1,1,"Hello World!!");
	

	while(1)
	{
	    //LED灯变化更快
		for(i = 0;i <= 1000;i++)
		{
			PWM_SetCompare1(i);
			Delay_ms(5);
		}
		//LED灯变化减慢
		for(i = 100;i > 0;i--)
		{
			PWM_SetCompare1(i);
			Delay_ms(50);
		}
	}
}
