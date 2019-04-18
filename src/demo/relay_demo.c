#include "relay_api.h"
#include "delay.h"
#include "iapw4k61s4.h"
#include "uart_api.h"
 
void Relay_Demo(void)
{
	uart_init(UART0, 9600);
	Init_Relay();
	Relay_disable();
	while(1)
	{
		P35 = !P35;
		//Relay_enable();
		delay_ms(1000);
		P35 = !P35;
		//Relay_disable();
		delay_ms(1000);
	}

}
