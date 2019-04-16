#include "adc_drv.h"
#include "uart_api.h"


static unsigned int adc_value;
/*----------------------------------
- 	function: �����ʱ	
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
- 	function: ��ʼ��ADC0
-	input	: channel =>ADCͨ��(ADC0-ADC7)
-			: speed	=> ADCת���ٶ�	
----------------------------------*/
void adc_init(unsigned char channel, unsigned char speed)
{
	//P1ASF |=  1 << channel; //ADCͨ��ѡ��
	P1ASF = 0xff;
	ADC_RES = 0;	//�������Ĵ���
	ADC_CONTR	= ADC_POWER | speed | ADC_START | channel;
	delay(2);  //��ʱ��ֵ֤��д��ADC_CONTR�Ĵ��� 
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

    ADC_CONTR &= ~ADC_FLAG;               //Close ADC ����־λ����ȴ��´�Ӳ����1
                                         //Ҳ����д�� ADC_CONTR= ADC_CONTR & ( ~ADC_FLAG)
    vo=(ADC_RES<<2)+ADC_RESL; 			 //��10λAD�ɼ�����   �����8λAD Vo=ADC_RESL ����
                                         //10λAD�ɼ� ��2��10�η� ��ֵΪ1024 ������1024��ʾ5���ĵ�ѹ 
										 //8λAD�ɼ� �� 2��8�η�  ��ֵΪ256  ��256��ʾ5��
    return vo;
} 






