#include "keyes_relay_drv.h"
	

sbit S=P1^0;			//继电器模块控制管脚

void keyes_relay_init(void)
{
	S = 1;	//默认关闭继电器
}

void keyes_relay_enable(void)
{
	S = 0;
}


void keyes_relay_disable(void)
{
	S = 1;
}
