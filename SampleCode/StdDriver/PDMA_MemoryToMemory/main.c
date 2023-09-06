/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "ml51_iar.h"

/**
 * @brief        I2C0 master demo. 
 * @param       None
 * @return      None
 * @details     please confirm enable LXT and check work stable if use LXT as WKT clock source.
*/

__xdata __no_init unsigned char RxDatabuffer[100] @ 0x100;
__xdata __no_init unsigned charfinalbuffer @ 0x263;
unsigned char i;
BIT pdmaflag ;

#pragma vector=0xAB
__interrupt void PDMA1_ISR(void){
  PDMA_Close(PDMA1);
  clr_DMA1TSR_FDONE;
  clr_DMA1TSR_HDONE;
  pdmaflag = 1;
}

void main (void) 
{

  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf("\n\r  Test start ...");

    for(i=0;i<100;i++)
    {
      RxDatabuffer[i]=i;
    }
/* Define PMDA function as memory to memory, and setting base address */    
    PDMA_Open(PDMA1,XRAM_XRAM,0x100,0x80);
/* Define destination memory address */    
    PDMA_MTM_DestinationAddress(PDMA1,0x200);
/* Define interrupt after full transfer */    
    PDMA_Interrupt_Enable(PDMA1,PDMAFULLINT);
    ENABLE_GLOBAL_INTERRUPT;
    PDMA_Run(PDMA1);

    while(!pdmaflag);

    printf (" \n PDMA Tranfer Finish! ");

    while(1);
}



