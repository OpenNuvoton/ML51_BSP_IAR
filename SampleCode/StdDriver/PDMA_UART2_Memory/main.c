/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"


/**
 * @brief        PDMA receiv from UART2(SC0) RX demo. 
 * @param       None
 * @return      None
 * @details     after PDMA transfer done UART2 RX data in XRAM 0x100 start area.
*/

__xdata __no_init unsigned char RxDatabuffer[100] @ 0x100;
unsigned char ct;
BIT pdmaflag;

/**
 *      PDMA Interrupt Vector 
*/
#pragma vector=0xA3
__interrupt void PDMA0_ISR(void){
  PDMA_Close(PDMA0);
  SFRS=0;DMA0TSR=0;
}

/**
 *      Main loop
*/
void main (void) 
{

  Enable_UART0_VCOM_printf();
  printf("\n\r  PDMA receiv UART2 RX intial...");

    
 /* Enable UART2 RX */      
    MFP_P55_UART2_RXD;
    P55_INPUT_MODE;
    UART_Open(24000000,UART2,115200);
  
 /* Clear XRAM base address area to 00h */
    for(ct=0;ct<10;ct++)
    {
      RxDatabuffer[ct]=0;
    }
 /* Define PMDA function as UART RX to memory, define base address and PDMA receive length */    
    PDMA_Open(PDMA0,SMCRX,0x100,100);
 /* Define interrupt after full transfer */
    PDMA_Interrupt_Enable(PDMA0,PDMAFULLINT);
 /* Global interrupt enable */
    ENABLE_GLOBAL_INTERRUPT;
 /* Start PDMA transfer */
    PDMA_Run(PDMA0);
    
    while(!pdmaflag);
    printf (" \n PDMA receiv UART2 RX finish! " );

    while(1);

}



