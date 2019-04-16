#ifndef __INNER_EEPROM_API_H__
#define __INNER_EEPROM_API_H__

#include "inner_eeprom_drv.h"

void   inner_eeprom_read(unsigned int addr,unsigned char *buffer, unsigned int cnt);
void   inner_eeprom_write (unsigned int addr,unsigned char *buffer, unsigned int cnt) ;
bit    inner_eeprom_erase(unsigned int addr);

#endif

