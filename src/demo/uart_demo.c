#include "uart_demo.h"
#include "printf.h"

static void delay_ms(unsigned int n)		//@24.000MHz
{
	unsigned char i, j;

	i = 24;
	j = 85;

	for(; n > 0; n--)
	for(i = 24; i > 0; i--)
	for(j = 85; j > 0; j--);
}


void uart_demo(void)
{
	char c ;
	uart0_Init(9600);
//	c = getchar();
//	putc(c);
	while(1){
		
		puts("HEllo Stc!!!");
		//my_printf_test();
		
		delay_ms(1000);
	}
	
}
