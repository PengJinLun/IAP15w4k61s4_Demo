#include "time0_drv.h"

static time0_isr time_isr_array[1];


void time0_cfg(unsigned int t0_clk)
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	INT_CLKO=0X01;	 //使能定时器0的时钟输出功能
	TL0 = (65536 - SYSCLOCK/(2*t0_clk)) & 0xFF;			//设置定时初值
	TH0 = (65536 - SYSCLOCK/(2*t0_clk)) >> 8;			//设置定时初值
	TF0 = 0;			//清除TF0标志	
	ET0 = 1;			//定时器0溢出中断允许位
	//EA = 1;
	//TR0 = 1;			//定时器0开始计时
}



void time0_isr_register(time0_isr fp)
{
	time_isr_array[0] = fp;
}

void tm0_isr() interrupt 1 using 1
{
	time_isr_array[0]();
}

