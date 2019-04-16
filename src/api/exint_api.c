#include "exint_api.h"

/*----------------------------------
-  function:设置外部中断
-  input:
		exint_num:INT0,INT1,INT2,INT3,INT4
		int_mode :0=>birateral trigger  1=>only falling trigger
----------------------------------*/
void  exint_init(unsigned char exint_num, bit int_mode)
{
   if(exint_num == INT0){
   		
   }
   else if(exint_num == INT1){
   		exint1_init(int_mode);	
   }
}


void exit_isr_register(unsigned char exint_num, exint_isr fp)
{
	if(exint_num == INT0){
		
	}else if(exint_num == INT1){
		exint1_isr_register(fp);
	}

}
