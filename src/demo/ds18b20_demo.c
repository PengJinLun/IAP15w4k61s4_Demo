#include "ds18b20_demo.h"
#include "ds18b20_api.h"
#include "uart_api.h"
#include "delay.h"


void DS18b20_Demo(void)
{
	short temperature;
	char buf[8] = {0};
	
	uart_init(UART0, 9600);
	Init_Ds18b20();
	while(1)
	{
		temperature = Read_Temp();
		if(temperature < 0)
			buf[0] = '-';
		else
			buf[0] = ' ';
		buf[1] = temperature/100%10+'0' ;
		buf[2] = temperature/10%10+'0' ;
		buf[3] = '.';
		buf[4] = temperature%10+'0' ;
		buf[5] = '\r';
		buf[6] = '\n';
		puts(buf);
		P35 = !P35;
		delay_ms(500);
		
	}
}
