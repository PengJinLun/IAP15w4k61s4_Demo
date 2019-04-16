#ifndef __TIME1_DRV_H__
#define __TIME1_DRV_H__

#include "iapw4k61s4.h"


#define SYSCLOCK 24000000L
//typedef void (*time1_isr)(void);

void time1_cfg(unsigned int t1_clk);
void time1_isr_register(void (*fp)(void) );

#define time1_enable \
{ 					 \
   EA = 1;			 \
   TR1 = 1; 		 \
}

#define time1_disable \
{					  \
   TR1 = 0;           \
}

#endif