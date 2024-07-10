#include "usart.h"

#include "stdio.h"
#include "stdarg.h"
#include <string.h>
#include <stdint.h>

uint8_t aRxBuffer;						//接收中断缓冲
uint8_t Uart1_RxBuff[256];		//接收缓冲
uint8_t Uart1_Rx_Cnt = 0;			//接收缓冲计数
uint8_t Uart1_Rxflg = 0;			//接收标志
uint8_t Uart1_timeout=0;//接收超时
/*!
    \brief      configure COM port
    \param[in]  com: COM on the board
      \arg        EVAL_COM0: COM0 on the board
      \arg        EVAL_COM1: COM1 on the board
    \param[out] none
    \retval     none
*/
void gd_eval_com0_init(void)
{
    /* USART interrupt configuration */
//    nvic_irq_enable(USART0_IRQn, 0, 0);
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);

    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART0);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_9);

    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ,GPIO_PIN_10);

    /* USART configure */
    usart_deinit(USART0);
    usart_baudrate_set(USART0, 115200U);

    usart_word_length_set(USART0, USART_WL_8BIT);
    usart_stop_bit_set(USART0, USART_STB_1BIT);
    usart_parity_config(USART0, USART_PM_NONE);
    usart_hardware_flow_rts_config(USART0, USART_RTS_DISABLE);
    usart_hardware_flow_cts_config(USART0, USART_CTS_DISABLE);
//    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
    usart_enable(USART0);
    //开启接收中断**********
//    usart_interrupt_enable(USART0, USART_INT_RBNE);
}
/* USER CODE BEGIN 1 */

/* retarget the C library printf function to the LPUART */
int fputc(int ch, FILE* f)
{
    usart_data_transmit(USART0, (uint8_t)ch);
    while (RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}

//==================================================================================================================================================================
void gd_eval_com2_init(void)
{
    /* USART interrupt configuration */
    nvic_irq_enable(USART2_IRQn, 0, 0);
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_AF);
    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART2);
    /* connect port to USARTx_Tx */
    gpio_init(GPIOC, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_10);
    /* connect port to USARTx_Rx */
    gpio_init(GPIOC, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ,GPIO_PIN_11);
    //*******端口重映射*********************************
    gpio_pin_remap_config(GPIO_USART2_PARTIAL_REMAP,ENABLE);
    /* USART configure */
    usart_deinit(USART2);
    usart_baudrate_set(USART2, 115200U);
    usart_word_length_set(USART2, USART_WL_8BIT);
    usart_stop_bit_set(USART2, USART_STB_1BIT);
    usart_parity_config(USART2, USART_PM_NONE);
    usart_hardware_flow_rts_config(USART2, USART_RTS_DISABLE);
    usart_hardware_flow_cts_config(USART2, USART_CTS_DISABLE);
    usart_receive_config(USART2, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART2, USART_TRANSMIT_ENABLE);
    usart_enable(USART2);
    //开启接收中断**********
    usart_interrupt_enable(USART2, USART_INT_RBNE);
}

//*************************************************************************************
void UART_send_byte(uint8_t byte) //
{
    usart_data_transmit(USART2, byte);
    while (RESET == usart_flag_get(USART2, USART_FLAG_TBE));
}

void UART_Send_Nbytes(uint8_t *Buffer,uint16_t len)
{
    while(len>0)
    {
        UART_send_byte(*Buffer);
        Buffer++;
        len--;
    }
}

void UartSendString(uint8_t *p)
{
    while ((*p)!='\0')
    {
        UART_send_byte(*p);
        p++;
    }
}


void UartSend_Fmt(char* fmt,...)									//指定位置显示任意格式化字符串
{
    char buf[200];																//临时缓存
    uint8_t mm=0;
    va_list ap;
    va_start(ap,fmt);
    vsprintf(buf,fmt,ap);													//将可变参数格式化
    va_end(ap);
    mm=strlen(buf);
    UART_Send_Nbytes((uint8_t *)buf,mm);
}


void ResetUsart(void)
{
    Uart1_Rx_Cnt = 0;			//接收缓冲计数
    Uart1_Rxflg = 0;			//接收标志
    Uart1_timeout=0;//接收超时
//    memset(Uart1_RxBuff,0x00,sizeof(Uart1_RxBuff));

}




/* USER CODE END 1 */
