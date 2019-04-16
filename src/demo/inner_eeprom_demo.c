#include "inner_eeprom_demo.h"
#include "printf.h"
#include "uart_api.h"

#define IAP_ADDRESS 0X2048

static void delay_ms(unsigned int n)		//@24.000MHz
{
	unsigned char i, j;

	i = 24;
	j = 85;

	for(; n > 0; n--)
	for(i = 24; i > 0; i--)
	for(j = 85; j > 0; j--);
}

void inner_eeprom_demo(void)
{
	char buff[512] = {0};
	int i;

	uart_init(UART0, 9600);

	inner_eeprom_erase(IAP_ADDRESS);

	for(i = 0; i < 512; i++){
		buff[i] = i;	
	}
	inner_eeprom_write(IAP_ADDRESS, buff, 512);

	for(i = 0; i < 512; i++){
		buff[i] = 0;	
	}
	inner_eeprom_read(IAP_ADDRESS, buff, 512);
	for(i = 0; i < 512; i++){
		putc(buff[i]);
	}

	while(1){
		P35 = !P35;
		delay_ms(500);
	}


}

