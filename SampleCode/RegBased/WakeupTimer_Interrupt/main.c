/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

#pragma vector=0x8B
__interrupt void WKT_ISR(void){
    PUSH_SFRS;

    clr_WKCON_WKTF;                                   //clear interrupt flag
    set_WKCON_WKTR;
    GPIO_LED ^= 1;
    
    POP_SFRS;
}


/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
   
    GPIO_LED_QUASI_MODE;

//-----------------------------------------------------
//  WKT initial   
//-----------------------------------------------------  
    SFRS = 0;
    WKCON = 0x02;                     //timer base 10k, Pre-scale = 1/16
    SFRS = 2;
    RWKH = 0xFC;
    SFRS = 0;
    RWKL = 0X00;                      //  if prescale is 0x00, never set RWK = 0xff
    ENABLE_WKT_INTERRUPT;             // enable WKT interrupt
    ENABLE_GLOBAL_INTERRUPT;
    set_WKCON_WKTR;                   // Wake-up timer run 

    while(1)
    {
      GPIO_LED ^= 1;
      _delay_();
    }
}

