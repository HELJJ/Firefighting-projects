
/* Includes ------------------------------------------------------------------*/
#include "tim.h"
#include "App.h"
#include "main.h"



void timer_config(void)
{
    /* ---------------------------------------------------------------------------
    TIMER6CLK = systemcoreclock / 6000=20K,
    CH1 update rate = TIMER6 counter clock / CH6VAL = 20000/4000 = 5 Hz
    ----------------------------------------------------------------------------*/
    timer_parameter_struct timer_initpara;
    nvic_irq_enable(TIMER6_IRQn, 0, 1);
    rcu_periph_clock_enable(RCU_TIMER6);
    timer_deinit(TIMER6);
    /* TIMER1 configuration */
    timer_initpara.prescaler         = 54000;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 1000;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER6,&timer_initpara);
//    /* auto-reload preload enable */
//    timer_auto_reload_shadow_enable(TIMER6);
    /* TIMER6 channel control update interrupt enable */
    timer_interrupt_enable(TIMER6,TIMER_INT_UP);
    /* TIMER6 counter enable */
    timer_enable(TIMER6);

}

