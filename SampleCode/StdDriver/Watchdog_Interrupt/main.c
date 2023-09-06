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
#pragma vector=0x53                             /* interrupt 10 */
__interrupt void WDT_ISR(void){
  
  PUSH_SFRS;
    clr_WDCON_WDTF;
    GPIO_LED ^= 1;
  POP_SFRS;
}

/************************************************************************************************************
*    Main function 
*
* Warning:
* Pleaes always check CONFIG WDT disable first
* only when WDT reset disable, WDT use as pure timer
* Since WDT reset issue can't be debug.
************************************************************************************************************/
void main (void)
{
/* Note WDT timer base is LIRC 38.4Khz*/
    GPIO_LED_QUASI_MODE;

    ENABLE_P17_PULLDOWN;
    WDT_Open(1024);
    WDT_Interrupt(Enable);
    ENABLE_GLOBAL_INTERRUPT;
    while (P17)
    {
      set_WDCON_WDCLR;
    }

}
