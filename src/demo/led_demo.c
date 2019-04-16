#include "led_demo.h"

static void delay_ms(unsigned int n)		//@24.000MHz
{
	unsigned char i, j;

	i = 24;
	j = 85;

	for(; n > 0; n--)
	for(i = 24; i > 0; i--)
	for(j = 85; j > 0; j--);
}


void led_demo(void)
{
	led_on();
	delay_ms(1000);
	led_off();
	delay_ms(1000);
}