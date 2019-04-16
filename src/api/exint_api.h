#ifndef __EXINT_API_H__
#define __EXINT_API_H__

#include "exint1_drv.h"

typedef void (*exint_isr)(void);

enum{
	INT0 = 0,
	INT1,

};

enum{
	BIRATERAL = 0,
	FALLING ,
	
};


void exint_init(unsigned char exint_num, bit int_mode);
void exit_isr_register(unsigned char exint_num, exint_isr fp);

#endif