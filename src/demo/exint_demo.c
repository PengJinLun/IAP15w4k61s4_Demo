#include "exint_demo.h"

void exint1isr1(void)
{
	P35 = !P35;
}

void exint_demo(void)
{
	exint_init(INT1, BIRATERAL);
	exit_isr_register(INT1, exint1isr1);
}
