#ifndef __ADC_DRV_H__
#define __ADC_DRV_H__

#include "iapw4k61s4.h"

enum{
	ADC0 = 	0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
};

#define ADC_POWER	0x80	//ADC电源控制位
#define ADC_FLAG	0x10	//ADC完成标志
#define ADC_START	0x08	//ADC起始控制位

#define ADC_SPEED_LL  0x00  //540个时钟
#define ADC_SPEED_L   0x20	//360个时钟
#define ADC_SPEED_H   0x40	//180个时钟
#define ADC_SPEED_HH  0x60	//90个时钟


void adc_init(unsigned char channel, unsigned char speed);
unsigned int  GetADCResult(unsigned char channel);

#endif
