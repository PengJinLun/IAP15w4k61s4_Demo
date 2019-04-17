#include "delay.h"
#include "intrins.h"

/*----------------------------------
- 1us软件延时	//@24.000MHz
----------------------------------*/
void delay5us(unsigned int u)		
{
	unsigned char i;
	for(;u > 0; u--){
	  	_nop_();
		_nop_();
		i = 27;
		while (--i);
	}

}

/*----------------------------------
- 1ms软件延时	//@24.000MHz
----------------------------------*/
void delay_ms(unsigned int n)		//@24.000MHz
{
	unsigned char i, j;

	i = 24;
	j = 85;

	for(; n > 0; n--)
	for(i = 24; i > 0; i--)
	for(j = 85; j > 0; j--);
}

