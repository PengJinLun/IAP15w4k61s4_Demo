#include "inner_eeprom_drv.h"

#define u8 unsigned  char
#define u16 unsigned int

#define CMD_IDLE    0		 //空闲模式
#define CMD_READ    1		 //IAP字节读命令
#define CMD_PROGRAM 2		 //IAP字节编程命令
#define CMD_ERASE   3		 //IAP字节擦除命令

//#define ENABLE_IAP  0X80     //if SYSCLK<30MHz
#define ENABLE_IAP  0X81     //if SYSCLK<24MHz
//#define ENABLE_IAP  0X82     //if SYSCLK<20MHz
//#define ENABLE_IAP  0X83     //if SYSCLK<12MHz
//#define ENABLE_IAP  0X84     //if SYSCLK<6MHz
//#define ENABLE_IAP  0X85     //if SYSCLK<3MHz
//#define ENABLE_IAP  0X86     //if SYSCLK<2MHz
//#define ENABLE_IAP  0X87     //if SYSCLK<1MHz


//测试地址
//#define IAP_ADDRESS 0X2048	 
//从手册上可以看出 iap15wk61S4的EEPROM地址是0x0000- 0xF3FF	



/*----------------------------------
延时函数
----------------------------------*/
static void delay(u8 n)
{
 while(n--);
}



/*----------------------------------
关闭IAP	
----------------------------------*/
void IapIdle()
{
  IAP_CONTR=0;		 //关闭IAP功能
  IAP_CMD  =0;		 //清除命令寄存器
  IAP_TRIG =0;		 //清楚触发寄存器
  IAP_ADDRH=0X80;	 //将地址设置到非IAP区域
  IAP_ADDRL=0;
}


/*----------------------------------
从ISP/IAP/EEPROM区域读取一个字节	
----------------------------------*/
u8 IapReadByte(u16 addr)
{
 unsigned char dat;				 //数据缓冲区
 IAP_CONTR=ENABLE_IAP;	 //使能IAP	   同时设置等待时间
 IAP_CMD=CMD_READ;		 //设置IAP命令
 IAP_ADDRL=addr;		 //设置IAP低地址
 IAP_ADDRH=addr>>8;		 //设置IAP高地址
 IAP_TRIG=0X5a;			 //写触发命令（0x5a）	 写触摸命令以后  命令才会生效 手册713页
 IAP_TRIG=0Xa5;			 //写触发命令（0xa5）
 delay(10);				 //等待ISP/IAP/EEPROM操作完成
 dat=IAP_DATA;			 //读ISP/IAP/EEPROM数据
 IapIdle();				 //关闭IAP功能

 return dat;			 //返回
}


/*----------------------------------
写一个字节数据到ISP/IAP/EEPROM区域	
----------------------------------*/
void IapProgramByte(u16 addr,u8 dat)
{
 IAP_CONTR=ENABLE_IAP;	 //使能IAP	   同时设置等待时间
 IAP_CMD=CMD_PROGRAM;	 //设置IAP命令
 IAP_ADDRL=addr;		 //设置IAP低地址
 IAP_ADDRH=addr>>8;		 //设置IAP高地址
 IAP_DATA=dat;			 //写ISP/IAP/EEPROM数据
 IAP_TRIG=0X5a;			 //写触发命令（0x5a）    写触摸命令以后  命令才会生效 手册713页
 IAP_TRIG=0Xa5;			 //写触发命令（0xa5）
 delay(10);				 //等待ISP/IAP/EEPROM操作完成
 IapIdle();				 //关闭IAP功能  
}


/*----------------------------------
扇区擦除
----------------------------------*/
void IapEraseSector(u16 addr)
{
 IAP_CONTR=ENABLE_IAP;	 //使能IAP	 同时设置等待时间
 IAP_CMD=CMD_ERASE;	     //设置IAP命令
 IAP_ADDRL=addr;		 //设置IAP低地址
 IAP_ADDRH=addr>>8;		 //设置IAP高地址
 IAP_TRIG=0X5a;			 //写触发命令（0x5a）	 写触摸命令以后  命令才会生效 手册713页
 IAP_TRIG=0Xa5;			 //写触发命令（0xa5）
 delay(10);				 //等待ISP/IAP/EEPROM操作完成
 IapIdle();				 //关闭IAP功能 
}