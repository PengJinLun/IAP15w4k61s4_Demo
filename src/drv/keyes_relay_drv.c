#include "keyes_relay_drv.h"
	

sbit S=P1^0;			//�̵���ģ����ƹܽ�

void keyes_relay_init(void)
{
	S = 1;	//Ĭ�Ϲرռ̵���
}

void keyes_relay_enable(void)
{
	S = 0;
}


void keyes_relay_disable(void)
{
	S = 1;
}
