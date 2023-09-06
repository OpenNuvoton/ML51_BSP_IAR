/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"
 
/************************************************************************************************************
*    WDT interrupt sub-routine
************************************************************************************************************/
#pragma vector=0x53
__interrupt void WDT_ISR(void){
  PUSH_SFRS;
    clr_WDCON_WDTF;
    set_WDCON_WDCLR;
    while((WDCON|~SET_BIT6)==0xFF);
    GPIO_LED ^= 1;
  POP_SFRS;
}

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
/* Note
  WDT timer base is LIRC 10Khz
*/
    GPIO_LED_QUASI_MODE;
//--------------------------------------------------------
//Warning:
//Pleaes always check CONFIG WDT disable first 
//only when WDT reset disable, WDT use as pure timer
//--------------------------------------------------------
    TA=0xAA;TA=0x55;WDCON=0x07;          //Setting WDT prescale 
    set_WDCON_WIDPD;                     //WDT run in POWER DOWM mode setting if needed
    ENABLE_WDT_INTERRUPT;
    ENABLE_GLOBAL_INTERRUPT;
    set_WDCON_WDTR;                      //WDT run
    set_WDCON_WDCLR;                     //Clear WDT timer
    while((WDCON|~SET_BIT6)==0xFF);

    while (1)
    {
      set_PCON_PD;
    }

}
