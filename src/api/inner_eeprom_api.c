#include "inner_eeprom_api.h"
//#include "uart_api.h"

void  inner_eeprom_read(unsigned int addr, 
			  unsigned char *buffer, unsigned int cnt)
{
	int i;
	for(i = 0; i < cnt; i++){
	  buffer[i] = IapReadByte(addr + i);
	}
}

void  inner_eeprom_write (unsigned int addr,
			  unsigned char *buffer, unsigned int cnt)
{
	int i;
	for(i = 0; i < cnt; i++){
	  IapProgramByte(addr + i,buffer[i]);
	}
	
}

 
/*----------------------------------
- 	function:����ָ����ַ������
-	input :	addr  Ҫ������ַ������
-	output: 0:���������ɹ�
----------------------------------*/
bit inner_eeprom_erase(unsigned int addr)
{
	int i;
	char c;
	IapEraseSector(addr);
	for(i = 0; i < 512; i++){
	  // putc(IapReadByte(addr + i))  ;  		
	   if(IapReadByte(addr + i) != 0xFF)
	   	return 1;
	}
	return 0;
	
}

