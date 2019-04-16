#ifndef __INNER_EERPROM_DRV_H__
#define __INNER_EERPROM_DRV_H__

#include "iapw4k61s4.h"

void IapIdle();
unsigned char IapReadByte(unsigned int addr);
void IapProgramByte(unsigned int addr,unsigned char dat);
void IapEraseSector(unsigned int addr);

#endif
