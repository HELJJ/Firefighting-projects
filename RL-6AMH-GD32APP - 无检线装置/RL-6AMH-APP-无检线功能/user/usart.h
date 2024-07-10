#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
extern uint8_t aRxBuffer;						//接收中断缓冲
extern uint8_t Uart1_RxBuff[256];		//接收缓冲
extern uint8_t Uart1_Rx_Cnt;			//接收缓冲计数
extern uint8_t Uart1_Rxflg;			//接收标志
extern uint8_t Uart1_timeout;//接收超时

/* USER CODE END Private defines */

void gd_eval_com0_init(void);
void gd_eval_com2_init(void);
/* USER CODE BEGIN Prototypes */
void UART_send_byte(uint8_t byte);
void UART_Send_Nbytes(uint8_t *Buffer,uint16_t len);
void UartSendString(uint8_t *p);
void UartSend_Fmt(char* fmt,...)	;
void ResetUsart(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

