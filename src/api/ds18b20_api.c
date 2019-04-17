#include "ds18b20_api.h"
#include "ds18b20_drv.h"

/*----------------------------------
-	function: 初始化DS18B20	
----------------------------------*/
void Init_Ds18b20(void)
{
	ds18b20_init();
}

 
/*----------------------------------
-	function: 读出温度函数
-   output  : 温度值为short变量 有正负	
----------------------------------*/
short Read_Temp()	  //short可以表示-32768~+32767
{
  unsigned char TL,TH;
  unsigned char temp;
  short t;
  ow_reset();                  //总线复位
  ds18B20_check();			   //等待DS应答
  write_byte(0xcc);            //发命令
  write_byte(0x44);            //发转换命令
  ow_reset();				   //复位
  ds18B20_check();			   //等待DS应答
  write_byte(0xcc);            //发命令
  write_byte(0xbe);			   //发送读温度命令
  TL=read_byte();    //读温度值的低字节
  TH=read_byte();    //读温度值的高字节
  t=TH;

  if(TH>7)
  {
    TH=~TH;
    TL=~TL; 
    temp=0;//温度为负   
  }else temp=1;
  t<<=8;             
  t+=TL;             // 两字节合成一个整型变量。
  t=(float)t*0.625;  //0.0625为12位温度采集的分辨率	   t为采集的数值  这里扩大10倍提取小数点后一位
  if(temp)return t;
  else return -t;
}
