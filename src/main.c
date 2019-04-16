#include "iapw4k61s4.h"
#include "demo.h"

int main(void)
{
	#ifdef LED_DEMO_EN
		led_demo();
	#endif

	#ifdef TIME_DEMO_EN
		time_demo();
	#endif

	#ifdef UART_DEMO_EN
		uart_demo();
	#endif

	#ifdef EXINT_DEMO_EN
	   exint_demo();
	#endif

	inner_eeprom_demo();

	while(1){
	}

	return 0;
}




