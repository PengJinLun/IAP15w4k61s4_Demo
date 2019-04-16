#include "uart_api.h"

void uart_init(unsigned char uart_num, unsigned int baud)
{
	if(uart_num == UART0){
		uart0_Init(baud);
	}
}

/*--------------------
·¢ËÍ×Ö·û´®
--------------------*/
void puts(const char *s)
{
	while(*s)
	{
		putc(*s++);	
	}
		
}
