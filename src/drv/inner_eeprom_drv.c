#include "inner_eeprom_drv.h"

#define u8 unsigned  char
#define u16 unsigned int

#define CMD_IDLE    0		 //����ģʽ
#define CMD_READ    1		 //IAP�ֽڶ�����
#define CMD_PROGRAM 2		 //IAP�ֽڱ������
#define CMD_ERASE   3		 //IAP�ֽڲ�������

//#define ENABLE_IAP  0X80     //if SYSCLK<30MHz
#define ENABLE_IAP  0X81     //if SYSCLK<24MHz
//#define ENABLE_IAP  0X82     //if SYSCLK<20MHz
//#define ENABLE_IAP  0X83     //if SYSCLK<12MHz
//#define ENABLE_IAP  0X84     //if SYSCLK<6MHz
//#define ENABLE_IAP  0X85     //if SYSCLK<3MHz
//#define ENABLE_IAP  0X86     //if SYSCLK<2MHz
//#define ENABLE_IAP  0X87     //if SYSCLK<1MHz


//���Ե�ַ
//#define IAP_ADDRESS 0X2048	 
//���ֲ��Ͽ��Կ��� iap15wk61S4��EEPROM��ַ��0x0000- 0xF3FF	



/*----------------------------------
��ʱ����
----------------------------------*/
static void delay(u8 n)
{
 while(n--);
}



/*----------------------------------
�ر�IAP	
----------------------------------*/
void IapIdle()
{
  IAP_CONTR=0;		 //�ر�IAP����
  IAP_CMD  =0;		 //�������Ĵ���
  IAP_TRIG =0;		 //��������Ĵ���
  IAP_ADDRH=0X80;	 //����ַ���õ���IAP����
  IAP_ADDRL=0;
}


/*----------------------------------
��ISP/IAP/EEPROM�����ȡһ���ֽ�	
----------------------------------*/
u8 IapReadByte(u16 addr)
{
 unsigned char dat;				 //���ݻ�����
 IAP_CONTR=ENABLE_IAP;	 //ʹ��IAP	   ͬʱ���õȴ�ʱ��
 IAP_CMD=CMD_READ;		 //����IAP����
 IAP_ADDRL=addr;		 //����IAP�͵�ַ
 IAP_ADDRH=addr>>8;		 //����IAP�ߵ�ַ
 IAP_TRIG=0X5a;			 //д�������0x5a��	 д���������Ժ�  ����Ż���Ч �ֲ�713ҳ
 IAP_TRIG=0Xa5;			 //д�������0xa5��
 delay(10);				 //�ȴ�ISP/IAP/EEPROM�������
 dat=IAP_DATA;			 //��ISP/IAP/EEPROM����
 IapIdle();				 //�ر�IAP����

 return dat;			 //����
}


/*----------------------------------
дһ���ֽ����ݵ�ISP/IAP/EEPROM����	
----------------------------------*/
void IapProgramByte(u16 addr,u8 dat)
{
 IAP_CONTR=ENABLE_IAP;	 //ʹ��IAP	   ͬʱ���õȴ�ʱ��
 IAP_CMD=CMD_PROGRAM;	 //����IAP����
 IAP_ADDRL=addr;		 //����IAP�͵�ַ
 IAP_ADDRH=addr>>8;		 //����IAP�ߵ�ַ
 IAP_DATA=dat;			 //дISP/IAP/EEPROM����
 IAP_TRIG=0X5a;			 //д�������0x5a��    д���������Ժ�  ����Ż���Ч �ֲ�713ҳ
 IAP_TRIG=0Xa5;			 //д�������0xa5��
 delay(10);				 //�ȴ�ISP/IAP/EEPROM�������
 IapIdle();				 //�ر�IAP����  
}


/*----------------------------------
��������
----------------------------------*/
void IapEraseSector(u16 addr)
{
 IAP_CONTR=ENABLE_IAP;	 //ʹ��IAP	 ͬʱ���õȴ�ʱ��
 IAP_CMD=CMD_ERASE;	     //����IAP����
 IAP_ADDRL=addr;		 //����IAP�͵�ַ
 IAP_ADDRH=addr>>8;		 //����IAP�ߵ�ַ
 IAP_TRIG=0X5a;			 //д�������0x5a��	 д���������Ժ�  ����Ż���Ч �ֲ�713ҳ
 IAP_TRIG=0Xa5;			 //д�������0xa5��
 delay(10);				 //�ȴ�ISP/IAP/EEPROM�������
 IapIdle();				 //�ر�IAP���� 
}