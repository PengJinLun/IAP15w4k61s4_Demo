#ifndef __UART_API_H__
#define __UART_API_H__

#include "uart0_drv.h"

enum{
	UART0 = 0,
	UART1,
};

void uart_init(unsigned char uart_num, unsigned int baud);
void puts(const char *s);

#endif