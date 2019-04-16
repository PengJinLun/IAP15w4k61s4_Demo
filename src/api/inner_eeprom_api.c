#include "inner_eeprom_api.h"


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


bit inner_eeprom_erase(unsigned int addr)
{
	int i;
	char buff[512] = {0};
	IapEraseSector(addr);
	for(i = 0; i < 512; i++){
		if(iapReadByte(addr + i) != 0xff)
			return 1;
	}
}

