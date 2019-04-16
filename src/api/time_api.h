#ifndef __TIME0_API_H__
#define __TIME0_API_H__

#include "time0_drv.h"
#include "time1_drv.h"

enum{
  TIME0 = 0,
  TIME1,
};

typedef void (*time_isr)(void);

void time_init(unsigned char tx, unsigned int tclk);
void time_enable(unsigned char tx);
void time_disable(unsigned char tx);
void time_isr_register(unsigned char tx, time_isr fp);

#endif

