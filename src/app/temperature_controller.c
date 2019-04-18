#include "temperature_controller.h"
#include "ds18b20_api.h"
#include "uart_api.h"
#include "relay_api.h"


static unsigned char T_upper;

void Init_Tprt_Ctlr(void)
{
	uart_init(UART0, 9600);
	if(Init_Ds18b20())
	{
	  puts("ds18b20 init err...\r\n");
	  return;
	}
	puts("ds18b20 init ok...\r\n");
}

void Set_Tprt_Ctlr_temperature(unsigned char value)
{
	puts("Input the T upper(25¡æ-35¡æ): ");
	getchar();
	T_upper
}



