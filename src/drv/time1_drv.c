#include "time1_drv.h"


typedef void (*time1_isr)(void)  ;
static  time1_isr time1_isr_array[1];

void time1_cfg(unsigned int t1_clk)
{
	AUXR |= 0x40;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = (65536 - SYSCLOCK/(2*t1_clk)) & 0xFF;			//���ö�ʱ��ֵ
	TH1 = (65536 - SYSCLOCK/(2*t1_clk)) >> 8;			//���ö�ʱ��ֵ
	TF1 = 0;			//���TF0��־	
	ET1 = 1;			//��ʱ��0����ж�����λ
	//EA = 1;
	//TR0 = 1;			//��ʱ��0��ʼ��ʱ
}

void time1_isr_register(time1_isr fp)
{
	time1_isr_array[0] = fp;
}

void tm1_isr() interrupt 3 using 3
{
	time1_isr_array[0]();
}

