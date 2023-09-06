/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

__xdata __no_init unsigned char  RxDatabuffer[100] @ 0x100;
unsigned char ct; 

/**
 * @brief       Low power run mode UART TX or receive demo
 * @param       None
 * @return      None
 * @details     
 */

#pragma vector=0xA3
__interrupt void PDMA0_ISR(void){
/* if need check with XRAM PDMA value, should enable following part */
  PDMA_Close(PDMA0);
  SFRS=0;DMA0TSR=0;

}
    
void main (void) 
{

#if 1  
    MFP_P46_CLKO;
    P46_QUASI_MODE;
    set_CKCON_CLOEN;
  
    MFP_P54_UART2_TXD;
    P54_QUASI_MODE;
    LowPower_LIRC_UART2_4800_init();
  
/*Enable Low power run mode */  
    FsysSelect(FSYS_LIRC);
    set_PCON_LPR;
  
    while(1)
    {
      LowPower_UART2_Send_Data(0x55);
      _delay_();
    }
#else 
    All_GPIO_QUASI_MODE;
    MFP_P14_GPIO;
    
/* Enable UART2 RX */      
    MFP_P55_UART2_RXD;
    P55_INPUT_MODE;
    LowPower_LIRC_UART2_4800_init();
  
/* Clear XRAM base address area to 00h */
    for(ct=0;ct<10;ct++)
    {
      RxDatabuffer[ct]=0;
    }
/* Define PMDA function as UART RX to memory, define base address and PDMA receive length */    
    PDMA_Open(PDMA0,SMCRX,0x100,5);
/* Define interrupt after full transfer */
    PDMA_Interrupt_Enable(PDMA0,PDMAFULLINT);
/* Global interrupt enable */
    ENABLE_GLOBAL_INTERRUPT;
/* Start PDMA transfer */
    PDMA_Run(PDMA0);
    
/*Enable Low power run mode */  
    FsysSelect(FSYS_LIRC);
    set_PCON_LPR;
  
    while(1);
#endif    

}



