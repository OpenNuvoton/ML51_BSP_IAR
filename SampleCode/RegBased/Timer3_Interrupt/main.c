/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

/************************************************************************************************************/
/*    TIMER 3 interrupt subroutine                                                                          */
/************************************************************************************************************/
#pragma vector=0x83
__interrupt void Timer3_ISR(void){
    PUSH_SFRS;
  
    clr_T3CON_TF3;
    GPIO_LED ^= 1;
  
    POP_SFRS;
}	

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
    
    MFP_P32_GPIO;
    GPIO_LED_QUASI_MODE;

    TIMER3_DIV_16;

    SFRS = 0;
    RH3 = 0x20;
    RL3 = 0x00;
    clr_T3CON_TF3;

    ENABLE_TIMER3_INTERRUPT;
    ENABLE_GLOBAL_INTERRUPT;                    //enable global interrupts
    set_T3CON_TR3;                              //Timer3 run

    while(1);
}

