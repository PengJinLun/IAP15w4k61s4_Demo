#ifndef __UART0_DRV_H__
#define __UART0_DRV_H__

#include "iapw4k61s4.h"
#include "common.h"


void uart0_Init(unsigned int baud);
void putc(char dat);
int getchar(void);

#endif

