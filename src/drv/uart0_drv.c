#include "uart0_drv.h"

 bit t_busy;
 bit r_busy;

/*----------------------------------
-	function: uart0 ��ʼ��
-	9600bps@24.000MHz
----------------------------------*/
void uart0_Init(unsigned int baud)	//9600bps@24.000MHz
{
	SCON = 0x50;	//8λ����,�ɱ䲨����
	AUXR |= 0x01;	//����1ѡ��ʱ��2Ϊ�����ʷ�����
	AUXR |= 0x04;	//��ʱ��2ʱ��ΪFosc,��1T
	T2L = (65536 - (FOSC/4/baud));		//�趨��ʱ��ֵ
	T2H = (65536 - (FOSC/4/baud)) >> 8;	//�趨��ʱ��ֵ
	//T2L = 0x8F;
	//T2H = 0xFD;
	AUXR |= 0x10;	//������ʱ��2
	EA = 1;
	ES = 1;
}


/*--------------------
 UART0 �жϷ����� 
--------------------*/
void uart0_isr() interrupt 4 using 1
{
   static unsigned int rx_count = 0;
   if(RI)
   {
   	 RI = 0;	//���RIλ
	 r_busy = 0;
   }
   if(TI)
   {
	 TI = 0;
	 t_busy = 0;
   }
}

/*--------------------
���͵��ֽ����� 
--------------------*/
void putc(char dat)
{
	while(t_busy);
	t_busy = 1;
	SBUF = dat;
}

/*--------------------
���յ��ֽ����� 
--------------------*/
int getchar(void)
{
	r_busy = 1;
	while (r_busy);
	return SBUF;
}


