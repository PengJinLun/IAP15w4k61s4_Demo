#include "uart0_drv.h"

 bit t_busy;
 bit r_busy;

/*----------------------------------
-	function: uart0 初始化
-	9600bps@24.000MHz
----------------------------------*/
void uart0_Init(unsigned int baud)	//9600bps@24.000MHz
{
	SCON = 0x50;	//8位数据,可变波特率
	AUXR |= 0x01;	//串口1选择定时器2为波特率发生器
	AUXR |= 0x04;	//定时器2时钟为Fosc,即1T
	T2L = (65536 - (FOSC/4/baud));		//设定定时初值
	T2H = (65536 - (FOSC/4/baud)) >> 8;	//设定定时初值
	//T2L = 0x8F;
	//T2H = 0xFD;
	AUXR |= 0x10;	//启动定时器2
	EA = 1;
	ES = 1;
}


/*--------------------
 UART0 中断服务函数 
--------------------*/
void uart0_isr() interrupt 4 using 1
{
   static unsigned int rx_count = 0;
   if(RI)
   {
   	 RI = 0;	//清除RI位
	 r_busy = 0;
   }
   if(TI)
   {
	 TI = 0;
	 t_busy = 0;
   }
}

/*--------------------
发送单字节数据 
--------------------*/
void putc(char dat)
{
	while(t_busy);
	t_busy = 1;
	SBUF = dat;
}

/*--------------------
接收单字节数据 
--------------------*/
int getchar(void)
{
	r_busy = 1;
	while (r_busy);
	return SBUF;
}


