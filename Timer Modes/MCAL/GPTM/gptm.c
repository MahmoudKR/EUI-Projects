/*
 * gptm.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mahmoud A. Monaim
 */
#include "MCAL/GPTM/gptm.h"

/******************************************************************************
 * \Syntax          : void GPTM_init_timer (Int32_t timer,Int32_t config)
 * \Description     : Initialize the Timer
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : timer number , configuration mode (16-bit or 32-bit)
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/

void GPTM_init_timer (Int32_t timer,Int32_t config)
{
    Set_bit(SYSCTL_RCGCTIMER_R,timer);
    while(SYSCTL_RCGCTIMER_R&(1<<timer)==0){}


    switch (timer)
    {
    case 0:
        TIMER0_CFG_R |= config;
        break;

    case 1:
        TIMER1_CFG_R |= config;
        break;

    case 2:
        TIMER2_CFG_R |= config;
        break;

    case 3:
        TIMER3_CFG_R |= config;
        break;

    case 4:
        TIMER4_CFG_R |= config;
        break;

    case 5:
        TIMER5_CFG_R |= config;
        break;

    }
}

/******************************************************************************
 * \Syntax          : void GPTM_set_mode (Int32_t timer, Int32_t mode, Int32_t CountDIR)
 * \Description     : Sets the Timers Operation Mode
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Timer Number, Op Mode:(Periodic,Capture Or One-shot), Count Mode:(Up Or Down)
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void GPTM_set_mode (Int32_t timer, Int32_t mode, Int32_t CountDIR)
{
    switch(timer)
    {
    case 0:
        Clear_bit(TIMER0_TAMR_R,0);
        Clear_bit(TIMER0_TAMR_R,1);
        Clear_bit(TIMER0_TAMR_R,4);

        TIMER0_TAMR_R |= mode;
        TIMER0_TAMR_R |= (CountDIR<<4);
        break;

    case 1:
        Clear_bit(TIMER1_TAMR_R,0);
        Clear_bit(TIMER1_TAMR_R,1);
        Clear_bit(TIMER1_TAMR_R,4);

        TIMER1_TAMR_R |= mode;
        TIMER1_TAMR_R |= (CountDIR<<4);
        break;

    case 2:
        Clear_bit(TIMER2_TAMR_R,0);
        Clear_bit(TIMER2_TAMR_R,1);
        Clear_bit(TIMER2_TAMR_R,4);

        TIMER2_TAMR_R |= mode;
        TIMER2_TAMR_R |= (CountDIR<<4);
        break;

    case 3:
        Clear_bit(TIMER3_TAMR_R,0);
        Clear_bit(TIMER3_TAMR_R,1);
        Clear_bit(TIMER3_TAMR_R,4);

        TIMER3_TAMR_R |= mode;
        TIMER3_TAMR_R |= (CountDIR<<4);
        break;

    case 4:
        Clear_bit(TIMER4_TAMR_R,0);
        Clear_bit(TIMER4_TAMR_R,1);
        Clear_bit(TIMER4_TAMR_R,4);

        TIMER4_TAMR_R |= mode;
        TIMER4_TAMR_R |= (CountDIR<<4);
        break;

    case 5:
        Clear_bit(TIMER5_TAMR_R,0);
        Clear_bit(TIMER5_TAMR_R,1);
        Clear_bit(TIMER5_TAMR_R,4);

        TIMER5_TAMR_R |= mode;
        TIMER5_TAMR_R |= (CountDIR<<4);
        break;
    }
}


/******************************************************************************
 * \Syntax          : void GPTM_set_time (Int32_t Timer_Load ,Int32_t time)
 * \Description     : Sets the value in the load register based on time input
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Timer Number, Time in mSec
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void GPTM_set_time (Int32_t Timer_Load ,Int32_t time)
{
    Int32_t value;
    value = time * 16000 -1;

    switch (Timer_Load)
    {
    case 0:
        TIMER0_TAILR_R = value;
        break;

    case 1:
        TIMER1_TAILR_R = value;
        break;

    case 2:
        TIMER2_TAILR_R = value;
        break;

    case 3:
        TIMER3_TAILR_R = value;
        break;

    case 4:
        TIMER4_TAILR_R = value;
        break;

    case 5:
        TIMER5_TAILR_R = value;
        break;
    }
}


/******************************************************************************
 * \Syntax          : void GPTM_start(Int32_t timer)
 * \Description     : Starts counting
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Timer Number
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void GPTM_start(Int32_t timer)
{
    switch (timer)
    {
    case 0:
        Set_bit(TIMER0_CTL_R,0);
        break;

    case 1:
        Set_bit(TIMER0_CTL_R,0);
        break;

    case 2:
        Set_bit(TIMER0_CTL_R,0);
        break;

    case 3:
        Set_bit(TIMER0_CTL_R,0);
        break;

    case 4:
        Set_bit(TIMER0_CTL_R,0);
        break;

    case 5:
        Set_bit(TIMER0_CTL_R,0);
        break;
    }
}


//void GPTM_stop(Int32_t timer)
//{
//    switch (timer)
//    {
//    case 0:
//        Clear_bit(TIMER0_CTL_R,0);
//        break;
//
//    case 1:
//        Clear_bit(TIMER0_CTL_R,0);
//        break;
//
//    case 2:
//        Clear_bit(TIMER0_CTL_R,0);
//        break;
//
//    case 3:
//        Clear_bit(TIMER0_CTL_R,0);
//        break;
//
//    case 4:
//        Clear_bit(TIMER0_CTL_R,0);
//        break;
//
//    case 5:
//        Clear_bit(TIMER0_CTL_R,0);
//        break;
//    }
//}


/******************************************************************************
 * \Syntax          : void GPTM_I_enable(Int32_t timer, Int32_t type)
 * \Description     : Enables interrupt sensing of the timer
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Timer Number, Interupt Type
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void GPTM_I_enable(Int32_t timer, Int32_t type)
{
    switch (timer)
    {
    case 0:
        Set_bit(TIMER0_IMR_R,type);
        Set_bit(NVIC_EN0_R,19);
        break;

    case 1:
        Set_bit(TIMER1_CTL_R,type);
        Set_bit(NVIC_EN0_R,21);
        break;

    case 2:
        Set_bit(TIMER2_CTL_R,type);
        Set_bit(NVIC_EN0_R,23);
        break;

    case 3:
        Set_bit(TIMER3_CTL_R,type);
        Set_bit(NVIC_EN1_R,3);
        break;

    case 4:
        Set_bit(TIMER4_CTL_R,type);
        Set_bit(NVIC_EN3_R,6);
        break;

    case 5:
        Set_bit(TIMER5_CTL_R,type);
        Set_bit(NVIC_EN3_R,28);
        break;
    }

}

/******************************************************************************
 *                      Interrupt Service Routines
 ******************************************************************************/



/******************************************************************************
 * \Syntax          : void GPTM_T0A_Handler(void)
 * \Description     : toggles the white LED
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void GPTM_T0A_Handler(void)
{

    Toggle_bit(GPIO_PORTF_DATA_R,1);
    Toggle_bit(GPIO_PORTF_DATA_R,2);
    Toggle_bit(GPIO_PORTF_DATA_R,3);
    Set_bit(TIMER0_ICR_R,0);
}
