/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

void rcu_config(void);
void gpio_config(void);
void adc_config(void);
uint16_t adc_channel_sample(uint8_t channel);

void GetADC5(void);


#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */

