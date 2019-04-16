#include "adc_demo.h"
#include "uart_api.h"
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



void adc_demo(void)
{
	unsigned int n = 0;
	uart_init(UART0, 9600);
	//Init_ADC(ADC0, ADC_SPEED_LL);

	while(1)
	{
		n = GetADCResult(ADC0);
		n = (float)n*5*100/1024;
		printf("%d\r\n", n);
		P35 = !P35;
		delay_ms(500);

	}
}



