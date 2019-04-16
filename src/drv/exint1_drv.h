#ifndef __EXINT1_DRV_H__
#define __EXINT1_DRV_H__

#include "iapw4k61s4.h"

typedef void (*exint1_isr_fun)(void);

void exint1_init(bit int_mode);
void exint1_isr_register(exint1_isr_fun fp);

#endif