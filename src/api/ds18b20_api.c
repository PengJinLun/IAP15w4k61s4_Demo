#include "ds18b20_api.h"
#include "ds18b20_drv.h"

/*----------------------------------
-	function: ��ʼ��DS18B20	
----------------------------------*/
void Init_Ds18b20(void)
{
	ds18b20_init();
}

 
/*----------------------------------
-	function: �����¶Ⱥ���
-   output  : �¶�ֵΪshort���� ������	
----------------------------------*/
short Read_Temp()	  //short���Ա�ʾ-32768~+32767
{
  unsigned char TL,TH;
  unsigned char temp;
  short t;
  ow_reset();                  //���߸�λ
  ds18B20_check();			   //�ȴ�DSӦ��
  write_byte(0xcc);            //������
  write_byte(0x44);            //��ת������
  ow_reset();				   //��λ
  ds18B20_check();			   //�ȴ�DSӦ��
  write_byte(0xcc);            //������
  write_byte(0xbe);			   //���Ͷ��¶�����
  TL=read_byte();    //���¶�ֵ�ĵ��ֽ�
  TH=read_byte();    //���¶�ֵ�ĸ��ֽ�
  t=TH;

  if(TH>7)
  {
    TH=~TH;
    TL=~TL; 
    temp=0;//�¶�Ϊ��   
  }else temp=1;
  t<<=8;             
  t+=TL;             // ���ֽںϳ�һ�����ͱ�����
  t=(float)t*0.625;  //0.0625Ϊ12λ�¶Ȳɼ��ķֱ���	   tΪ�ɼ�����ֵ  ��������10����ȡС�����һλ
  if(temp)return t;
  else return -t;
}
