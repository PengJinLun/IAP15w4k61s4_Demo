#include "time1_drv.h"


typedef void (*time1_isr)(void)  ;
static  time1_isr time1_isr_array[1];

void time1_cfg(unsigned int t1_clk)
{
	AUXR |= 0x40;		//定时器时钟1T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = (65536 - SYSCLOCK/(2*t1_clk)) & 0xFF;			//设置定时初值
	TH1 = (65536 - SYSCLOCK/(2*t1_clk)) >> 8;			//设置定时初值
	TF1 = 0;			//清除TF0标志	
	ET1 = 1;			//定时器0溢出中断允许位
	//EA = 1;
	//TR0 = 1;			//定时器0开始计时
}

void time1_isr_register(time1_isr fp)
{
	time1_isr_array[0] = fp;
}

void tm1_isr() interrupt 3 using 3
{
	time1_isr_array[0]();
}

