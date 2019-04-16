#include "time_api.h"


/*
 *   function:
 	 intput:
		tx	 : TIME0 TIME1
 */
void time_init(unsigned char tx, unsigned int tclk)
{
	if(tx == 0){
		time0_cfg(tclk);
	}else{
	    time1_cfg(tclk);
	}
}


void time_enable(unsigned char tx)
{
	if(tx == 0){
		time0_enable;
	}else{
	    time1_enable;
	}
}

void time_disable(unsigned char tx)
{
	if(tx == 0){
		time0_disable;
	}else{
		time1_disable;
	}
}

void time_isr_register(unsigned char tx, time_isr fp)
{
	if(tx == 0){
		time0_isr_register(fp);
	}else{
		time1_isr_register(fp);
	}

}

