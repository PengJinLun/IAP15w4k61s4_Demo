#include "adc_drv.h"
#include "uart_api.h"


static unsigned int adc_value;
/*----------------------------------
- 	function: 软件延时	
----------------------------------*/
static void delay(unsigned int n)
{
	unsigned int x;
	while(n--){
	   x = 5000;
	   while(x--);
	}
}

/*----------------------------------
- 	function: 初始化ADC0
-	input	: channel =>ADC通道(ADC0-ADC7)
-			: speed	=> ADC转换速度	
----------------------------------*/
void adc_init(unsigned char channel, unsigned char speed)
{
	//P1ASF |=  1 << channel; //ADC通道选择
	P1ASF = 0xff;
	ADC_RES = 0;	//清除结果寄存器
	ADC_CONTR	= ADC_POWER | speed | ADC_START | channel;
	delay(2);  //延时保证值被写入ADC_CONTR寄存器 
//	EADC = 1;
//	EA = 1;
}



/*---------------------------- 
Get ADC result 
----------------------------*/ 
unsigned int GetADCResult(unsigned char channel)                             
{ 
    unsigned int  vo;
    P1ASF = 1 << channel;                                        
    ADC_CONTR = ADC_POWER | ADC_SPEED_LL | channel | ADC_START;
    delay(2)  ;

    while (!(ADC_CONTR & ADC_FLAG));     //Wait complete flag 

    ADC_CONTR &= ~ADC_FLAG;               //Close ADC 将标志位清零等待下次硬件置1
                                         //也可以写成 ADC_CONTR= ADC_CONTR & ( ~ADC_FLAG)
    vo=(ADC_RES<<2)+ADC_RESL; 			 //打开10位AD采集功能   如果用8位AD Vo=ADC_RESL 即可
                                         //10位AD采集 即2的10次方 满值为1024 这里用1024表示5伏的电压 
										 //8位AD采集 即 2的8次方  满值为256  用256表示5伏
    return vo;
} 






