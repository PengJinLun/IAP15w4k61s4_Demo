#include "adc_api.h"


/*----------------------------------
- 	function: 初始化ADC
-	input	: channel =>ADC通道(ADC0-ADC7)
-			: speed	=> ADC转换速度	
----------------------------------*/
void Init_ADC(unsigned char channel, unsigned char speed)
{
	adc_init(channel, speed);
}

