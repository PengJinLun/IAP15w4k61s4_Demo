#include "time0_drv.h"

static time0_isr time_isr_array[1];


void time0_cfg(unsigned int t0_clk)
{
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	INT_CLKO=0X01;	 //ʹ�ܶ�ʱ��0��ʱ���������
	TL0 = (65536 - SYSCLOCK/(2*t0_clk)) & 0xFF;			//���ö�ʱ��ֵ
	TH0 = (65536 - SYSCLOCK/(2*t0_clk)) >> 8;			//���ö�ʱ��ֵ
	TF0 = 0;			//���TF0��־	
	ET0 = 1;			//��ʱ��0����ж�����λ
	//EA = 1;
	//TR0 = 1;			//��ʱ��0��ʼ��ʱ
}



void time0_isr_register(time0_isr fp)
{
	time_isr_array[0] = fp;
}

void tm0_isr() interrupt 1 using 1
{
	time_isr_array[0]();
}

