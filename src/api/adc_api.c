#include "adc_api.h"


/*----------------------------------
- 	function: ��ʼ��ADC
-	input	: channel =>ADCͨ��(ADC0-ADC7)
-			: speed	=> ADCת���ٶ�	
----------------------------------*/
void Init_ADC(unsigned char channel, unsigned char speed)
{
	adc_init(channel, speed);
}

