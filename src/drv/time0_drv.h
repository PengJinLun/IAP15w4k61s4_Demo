#ifndef __TIME0_DRV_H__
#define __TIME0_DRV_H__

#include "iapw4k61s4.h"


#define SYSCLOCK 24000000L
typedef void (*time0_isr)(void);


void time0_cfg(unsigned int t0_clk);
void time0_isr_register(time0_isr fp);

#define time0_enable \
{ 					 \
   EA = 1;			 \
   TR0 = 1; 		 \
}

#define time0_disable \
{					  \
   TR0 = 0;           \
}

#endif