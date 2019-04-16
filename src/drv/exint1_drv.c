#include "exint1_drv.h"

static exint1_isr_fun exint_isr_array[1];

/*----------------------------------
-  function:设置外部中断1
-  input:
		int_mode :0=>birateral trigger  1=>only falling trigger
----------------------------------*/
void exint1_init(bit int_mode)
{
	IT1 = int_mode;	//下降沿触发
	EX1 = 1;		//打开INIT1中断
	EA = 1;			//打开总中断

}

void exint1_isr_register(exint1_isr_fun fp)
{
	exint_isr_array[0] = fp;
}

void exint1_isr(void) interrupt 2 
{
	exint_isr_array[0]();
}


