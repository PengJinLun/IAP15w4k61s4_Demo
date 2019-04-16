#include "time_demo.h"

void led_irq_fun(void)
{
 	static unsigned int n = 0;
	n++;
	if(n == 1000){
		n = 0;
		P35 = !P35;
	}
}

void time_pwm(void)
{
	static char flag = 0;
	if(flag)
	{
		TL0 = (65536 - 20000) & 0xFF;			//设置定时初值
		TH0 = (65536 - 20000) >> 8;			//设置定时初值
	}
	else 
	{
		TL0 = (65536 - 40000) & 0xFF;			//设置定时初值
		TH0 = (65536 - 40000) >> 8;			//设置定时初值
	}	
	flag = !flag;
}

void time_demo(void)
{
   time_init(TIME0, 500);
   time_isr_register(TIME0, time_pwm);
   time_enable(TIME0);
}




