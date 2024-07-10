/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gd32f10x.h"
#include "gd32f10x_gpio.h"

void GPIO_TogglePin(uint32_t gpio_periph, uint32_t pin);


//********看门狗*********************
#define DogFeed_Pin GPIO_PIN_8
#define DogFeed_GPIO_Port GPIOA
#define DogSet0_Pin GPIO_PIN_14
#define DogSet0_GPIO_Port GPIOB
#define DogSet1_Pin GPIO_PIN_12
#define DogSet1_GPIO_Port GPIOB
#define DogSet2_Pin GPIO_PIN_13
#define DogSet2_GPIO_Port GPIOB
//*******EEPROM***********************
#define EESAD_Pin GPIO_PIN_11
#define EESAD_GPIO_Port GPIOB
#define EESCL_Pin GPIO_PIN_10
#define EESCL_GPIO_Port GPIOB
//********拨码开关号*******************
#define K8_SW1_Pin GPIO_PIN_6
#define K8_SW1_GPIO_Port GPIOC
#define K4_SW1_Pin GPIO_PIN_7
#define K4_SW1_GPIO_Port GPIOC
#define K2_SW1_Pin GPIO_PIN_8
#define K2_SW1_GPIO_Port GPIOC
#define K1_SW1_Pin GPIO_PIN_9
#define K1_SW1_GPIO_Port GPIOC
//*******6Q 复位**************
#define M6QRST_Pin GPIO_PIN_15
#define M6QRST_GPIO_Port GPIOB
//*******按键检测*******************
#define Key_Pin GPIO_PIN_13
#define Key_GPIO_Port GPIOC
//********电磁阀********************
#define RelayCheck_Pin GPIO_PIN_5
#define RelayCheck_GPIO_Port GPIOA
#define RelayCtrl_Pin GPIO_PIN_3
#define RelayCtrl_GPIO_Port GPIOA
#define RelayAD_Pin GPIO_PIN_7
#define RelayAD_GPIO_Port GPIOA
//*********反馈阀AD********************
#define FeedBackAD_Pin GPIO_PIN_0
#define FeedBackAD_GPIO_Port GPIOB
//***********LED指示灯******************
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_5
#define LED3_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_6
#define LED4_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_7
#define LED5_GPIO_Port GPIOB
#define LED6_Pin GPIO_PIN_8
#define LED6_GPIO_Port GPIOB
#define LED7_Pin GPIO_PIN_9
#define LED7_GPIO_Port GPIOB
//********CAN短路检测***********************
#define CANShort_Pin GPIO_PIN_15
#define CANShort_GPIO_Port GPIOC
//*******主电****************************
#define MainPower_Pin GPIO_PIN_0
#define MainPower_GPIO_Port GPIOA
//*******备电****************************
#define BackPower_Pin GPIO_PIN_3
#define BackPower_GPIO_Port GPIOE
//********电源检测*************************
#define PowerOpen_Pin GPIO_PIN_2
#define PowerOpen_GPIO_Port GPIOE

#define PowerShort_Pin GPIO_PIN_1
#define PowerShort_GPIO_Port GPIOA

#define PowerAD_Pin GPIO_PIN_2
#define PowerAD_GPIO_Port GPIOA

//****超级电容充电使能控制*************************

#define ChargEn_Pin GPIO_PIN_15
#define ChargEn_GPIO_Port GPIOA


//******************************************************************************************
//******************************************************************************************
//******************************************************************************************
#define DogFeed_H gpio_bit_write(DogFeed_GPIO_Port,DogFeed_Pin,SET);
#define DogFeed_L gpio_bit_write(DogFeed_GPIO_Port,DogFeed_Pin,RESET);
#define DogFeedV  GPIO_TogglePin(DogFeed_GPIO_Port,DogFeed_Pin);

#define DogSet0_H gpio_bit_write(DogSet0_GPIO_Port,DogSet0_Pin,SET);
#define DogSet0_L gpio_bit_write(DogSet0_GPIO_Port,DogSet0_Pin,RESET);

#define DogSet1_H gpio_bit_write(DogSet1_GPIO_Port,DogSet1_Pin,SET);
#define DogSet1_L gpio_bit_write(DogSet1_GPIO_Port,DogSet1_Pin,RESET);

#define DogSet2_H gpio_bit_write(DogSet2_GPIO_Port,DogSet2_Pin,SET);
#define DogSet2_L gpio_bit_write(DogSet2_GPIO_Port,DogSet2_Pin,RESET);

#define EESAD_H gpio_bit_write(EESAD_GPIO_Port,EESAD_Pin,SET);
#define EESAD_L gpio_bit_write(EESAD_GPIO_Port,EESAD_Pin,RESET);

#define EESCL_H gpio_bit_write(EESCL_GPIO_Port,EESCL_Pin,SET);
#define EESCL_L gpio_bit_write(EESCL_GPIO_Port,EESCL_Pin,RESET);

#define K8_SW1_in        gpio_input_bit_get(K8_SW1_GPIO_Port,K8_SW1_Pin)
#define K4_SW1_in        gpio_input_bit_get(K4_SW1_GPIO_Port,K4_SW1_Pin)
#define K2_SW1_in        gpio_input_bit_get(K2_SW1_GPIO_Port,K2_SW1_Pin)
#define K1_SW1_in        gpio_input_bit_get(K1_SW1_GPIO_Port,K1_SW1_Pin)

#define M6QRST_H gpio_bit_write(M6QRST_GPIO_Port,M6QRST_Pin,SET);
#define M6QRST_L gpio_bit_write(M6QRST_GPIO_Port,M6QRST_Pin,RESET);

#define Key_in        gpio_input_bit_get(Key_GPIO_Port,Key_Pin)

#define RelayCheck_On  gpio_bit_write(RelayCheck_GPIO_Port,RelayCheck_Pin,SET);
#define RelayCheck_Off gpio_bit_write(RelayCheck_GPIO_Port,RelayCheck_Pin,RESET);

#define RelayCtrl_On  gpio_bit_write(RelayCtrl_GPIO_Port,RelayCtrl_Pin,SET);
#define RelayCtrl_Off gpio_bit_write(RelayCtrl_GPIO_Port,RelayCtrl_Pin,RESET);

#define LED1_On  gpio_bit_write(LED1_GPIO_Port,LED1_Pin,SET);
#define LED1_Off gpio_bit_write(LED1_GPIO_Port,LED1_Pin,RESET);
#define LED1V  GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);

#define LED2_On  gpio_bit_write(LED2_GPIO_Port,LED2_Pin,SET);
#define LED2_Off gpio_bit_write(LED2_GPIO_Port,LED2_Pin,RESET);
#define LED2V  GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);

#define LED3_On  gpio_bit_write(LED3_GPIO_Port,LED3_Pin,SET);
#define LED3_Off gpio_bit_write(LED3_GPIO_Port,LED3_Pin,RESET);
#define LED3V  GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);

#define LED4_On  gpio_bit_write(LED4_GPIO_Port,LED4_Pin,SET);
#define LED4_Off gpio_bit_write(LED4_GPIO_Port,LED4_Pin,RESET);
#define LED4V  GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);

#define LED5_On  gpio_bit_write(LED5_GPIO_Port,LED5_Pin,SET);
#define LED5_Off gpio_bit_write(LED5_GPIO_Port,LED5_Pin,RESET);
#define LED5V  GPIO_TogglePin(LED5_GPIO_Port,LED5_Pin);

#define LED6_On  gpio_bit_write(LED6_GPIO_Port,LED6_Pin,SET);
#define LED6_Off gpio_bit_write(LED6_GPIO_Port,LED6_Pin,RESET);
#define LED6V  GPIO_TogglePin(LED6_GPIO_Port,LED6_Pin);

#define LED7_On  gpio_bit_write(LED7_GPIO_Port,LED7_Pin,SET);
#define LED7_Off gpio_bit_write(LED7_GPIO_Port,LED7_Pin,RESET);
#define LED7V  GPIO_TogglePin(LED7_GPIO_Port,LED7_Pin);

#define CANShort_in        gpio_input_bit_get(CANShort_GPIO_Port,CANShort_Pin)

#define MainPower_On  gpio_bit_write(MainPower_GPIO_Port,MainPower_Pin,SET);
#define MainPower_Off gpio_bit_write(MainPower_GPIO_Port,MainPower_Pin,RESET);

#define BackPower_On  gpio_bit_write(BackPower_GPIO_Port,BackPower_Pin,SET);
#define BackPower_Off gpio_bit_write(BackPower_GPIO_Port,BackPower_Pin,RESET);


#define ChargEn_On  gpio_bit_write(ChargEn_GPIO_Port,ChargEn_Pin,RESET);
#define ChargEn_Off gpio_bit_write(ChargEn_GPIO_Port,ChargEn_Pin,SET);


#define PowerOpen_in        gpio_input_bit_get(PowerOpen_GPIO_Port,PowerOpen_Pin)

#define PowerShort_in        gpio_input_bit_get(PowerShort_GPIO_Port,PowerShort_Pin)





void MX_GPIO_Init(void);




#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

