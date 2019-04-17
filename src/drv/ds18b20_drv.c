#include "ds18b20_drv.h"
#include "delay.h"


sbit DQ=P1^3;       //ds18b20 �˿�

/*----------------------------------
- function:DS18B20��λ����	
----------------------------------*/
void ow_reset(void)
{

    DQ=1;                //�Ӹ�������
    DQ=0;
    delay5us(100);    //>480 us	  �͵�ƽ��λ�ź�
    DQ=1;
    delay5us(4);      //>15us ��������	 15-60us�ߵ�ƽ��  ��60-240us ��Ӧ���ź�
}



/*----------------------------------
-	function:	�ȴ�DS18B20�Ļ�Ӧ
-	output	:	����1:δ��⵽DS18B20�Ĵ���
-				����0:����
----------------------------------*/
unsigned char ds18B20_check(void) 	   
{   
	unsigned char retry=0;	 //���������
    while (DQ&&retry<40)
	{
		retry++;
		delay5us(1);		//���5us
	}; 
	retry=0;	 
    while (!DQ&&retry<45)	//����240us����ʱ ��������ĸ�λ����
	{
		retry++;
		delay5us(1);		//���5us
	};
	if(retry>=45)return 1;	    //û�нӵ�DS18B20Ӧ��
	return 0;					//�ӵ�Ӧ��
}



//

/*--------------------------------------------------
-	function:	��ʼ��DS18B20  ͬʱ���DS�Ĵ���
-   output	:	����1:������
-				����0:���� 
--------------------------------------------------*/  
unsigned char ds18b20_init(void)
{
  unsigned char m;
  ow_reset();         //��λ����
  m=ds18B20_check();  //�ȵ�dsӦ��
  return m;
}


//

/*----------------------------------
-	function:  DS18B20д�����
-			   ��1-WIRE ������д1���ֽ�
-	input   :  val Ҫд���ֽ�		  
----------------------------------*/
void write_byte(unsigned char val)
{
 unsigned char i,testb;
 for(i=8;i>0;i--)
 { 
   testb=val&0x01;            //���λ�Ƴ�
   val=val>>1;
   if(testb)				  //д1
   {
   	 DQ=0;
	 delay5us(1);			  //4us
	 DQ=1;
	 delay5us(12);			  //60us
   }
   else						  //д0
   {
     DQ=0;
	 delay5us(12);			  //60us
	 DQ=1;
	 delay5us(1);			  //4us
   }
 }
}


/*----------------------------------------------------------
-	function: DS18B20��1�ֽں���
-	output	: ����ֵΪ��ȡ�ֽ�ֵ
-	note	: һ��1bit�Ķ�ȡ������Ҫ60us
			  ���ζ�ȡ֮����Ҫ����1us�Ļָ�ʱ��
    		  ���ζ�ȡ1bit�������Ͳ��ܳ���15us Ȼ����������		
----------------------------------------------------------*/
unsigned char read_byte(void)
{
 unsigned char i;
 unsigned char value=0;
 for(i=8;i>0;i--)
 {
  DQ=1;
  value>>=1;   //value=value>>1
  DQ=0;                                  
  delay2us(1);							 //����2us 
  DQ=1;                                  //����
  delay5us(1);							 //����10us	 ׼���������ߵ�ǰ����
  if(DQ)value|=0x80;					 //����ǰ����ֵ������ʱ����
  delay5us(8);                          //50 us��ʱ  ���һ�ζ�ȡ����ʱ��һ�ζ�ȡ����60us������1us�Ļָ�ʱ��
 }
 DQ=1;
 return(value);
}






