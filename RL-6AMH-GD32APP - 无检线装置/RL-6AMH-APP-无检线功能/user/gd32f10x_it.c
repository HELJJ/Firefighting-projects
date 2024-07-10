/*!
    \file    gd32f10x_it.c
    \brief   interrupt service routines

    \version 2024-01-05, V2.3.0, firmware for GD32F10x
*/

/*
    Copyright (c) 2024, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/
#include "gd32f10x_it.h"
#include "main.h"
#include "systick.h"
#include "App.h"
#include "usart.h"

/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void)
{
    /* if NMI exception occurs, go to infinite loop */
    while(1) {
    }
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler(void)
{
    /* if Hard Fault exception occurs, go to infinite loop */
    while(1) {
    }
}

/*!
    \brief      this function handles MemManage exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void MemManage_Handler(void)
{
    /* if Memory Manage exception occurs, go to infinite loop */
    while(1) {
    }
}

/*!
    \brief      this function handles BusFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BusFault_Handler(void)
{
    /* if Bus Fault exception occurs, go to infinite loop */
    while(1) {
    }
}

/*!
    \brief      this function handles UsageFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void UsageFault_Handler(void)
{
    /* if Usage Fault exception occurs, go to infinite loop */
    while(1) {
    }
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler(void)
{
    /* if SVC exception occurs, go to infinite loop */
    while(1) {
    }
}

/*!
    \brief      this function handles DebugMon exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DebugMon_Handler(void)
{
    /* if DebugMon exception occurs, go to infinite loop */
    while(1) {
    }
}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler(void)
{
    /* if PendSV exception occurs, go to infinite loop */
    while(1) {
    }
}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
//***********1ms定时器*****************************
void SysTick_Handler(void)
{

    Systime++;
    //***********复位按键*****************
    if(Key_in==SET)//按键按下
    {
        ResButton.ButtonTime++;
        ResButton.But_now=1;
    }
    else
    {
        ResButton.But_now=0;
    }
		if(ResButton.ButtonTime>5000)
		{
			LED1_On;LED2_On;LED3_On;LED4_On;LED5_On;LED6_On;LED7_On;
		}
    //*******按键按下或释放****************
    if(ResButton.But_old!=ResButton.But_now)
    {
        if(ResButton.But_now==0)//释放按键
        {
            //按键释放判断长短按
            if(ResButton.ButtonTime>5000)//3S以上长按
            {
                ResButton.ButtonTime=6000;
                ResButton.ButtonFlg=3;//
                //***********************************************
                //***测试用记得删除*************
//                M6QRST_L;
//                LED7_On;
//                delay_ms(100);
//                M6QRST_H;
//                LED7_Off;
//                ResButton.ButtonFlg=0;
//                ResButton.ButtonTime=0;
            }
            else if(ResButton.ButtonTime>100)//3S以下短按
            {
                ResButton.ButtonFlg=2;//短按
            }
            ResButton.ButtonTime=0;
        }
        else
        {
            ResButton.ButtonTime=0;
        }
    }
    ResButton.But_old=ResButton.But_now;
    if(ResButton.ButtonTime>6000)
    {
        ResButton.ButtonTime=6000;
    }
    //************************************************
}
//************电源线短路状态检测*************************
void  EXTI1_IRQHandler(void)
{
    if(RESET != exti_interrupt_flag_get(EXTI_1))
    {
        delay_ms(50);
        if(PowerShort_in==RESET)
        {
            //*********短路处理*****************
            MainPower_Off;
            BackPower_Off;
            PowerLine.LineShort=1;
            SysDate.MBpower=0x00;
            SysDate.Powerflg=3;
        }
        exti_interrupt_flag_clear(EXTI_1);
    }
}
//************CAN短路状态检测***************************
void EXTI10_15_IRQHandler(void)
{
    if(RESET != exti_interrupt_flag_get(EXTI_15))
    {
        if(CANShort_in==RESET)
        {
            SysDate.CanCount++;
            if(SysDate.CanCount>=250)
            {
                SysDate.CanCount=250;
            }
        }
        exti_interrupt_flag_clear(EXTI_15);
    }
}

//*****************************************************
void USART2_IRQHandler(void)
{
    if(RESET != usart_interrupt_flag_get(USART2, USART_INT_FLAG_RBNE))
    {
        Uart1_RxBuff[Uart1_Rx_Cnt] = usart_data_receive(USART2);
        if(Uart1_Rx_Cnt==0)
        {
            if(Uart1_RxBuff[Uart1_Rx_Cnt]==0xA5)
            {
                Uart1_Rx_Cnt++;
            }
        }
        else
        {
            Uart1_Rx_Cnt++;
        }
        if(Uart1_Rx_Cnt >= 16)
        {
            Uart1_Rxflg=1;//接收到数据
            Uart1_Rx_Cnt=15;
        }
    }
    else
    {
        usart_data_receive(USART2);
    }
//    if(RESET != usart_interrupt_flag_get(USART0, USART_INT_FLAG_TBE)){
//        /* transmit data */
//        usart_data_transmit(USART0, txbuffer[txcount++]);
//        if(txcount == tx_size){
//            usart_interrupt_disable(USART0, USART_INT_TBE);
//        }
//    }
}


void TIMER6_IRQHandler(void)
{

    if(SET == timer_interrupt_flag_get(TIMER6,TIMER_INT_FLAG_UP))
    {
        timer_interrupt_flag_clear(TIMER6,TIMER_INT_FLAG_UP);
			if((ResButton.ButtonTime<5000)&&(ResButton.ButtonFlg!=3))
			{
        LED1V;
        if(Q6State.NorMalflg==1)//收到一次正常的开始计时
        {
            Q6State.Q6timeOut++;
        }
        if(SysDate.A6_state==1)
        {
            LED2V;
        }
        else
        {
            LED2_Off;
        }
			}
    }
}















