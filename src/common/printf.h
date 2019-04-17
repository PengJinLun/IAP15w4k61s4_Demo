#ifndef __PRINTF_H__
#define __PRINTF_H__

#include "uart_api.h"
#define  __out_putchar  putc


#define  MAX_NUMBER_BYTES  32

int my_printf_test(void);
int printf(const char *fmt, ...);

#endif /* _MY_PRINTF_H */


