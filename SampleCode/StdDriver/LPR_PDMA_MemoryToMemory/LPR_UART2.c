/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: ML51 simple GPIO toggle out demo code
//***********************************************************************************************************

#include "ML51_IAR.h"


/**
 * @brief       Low power run mode Memory to memory function demo
 * @param       None
 * @return      None
 * @details     
 */

__xdata __no_init unsigned char RxDatabuffer[100] @ 0x100;
__xdata __no_init unsigned char finalbuffer @ 0x263;
unsigned char i;

#pragma vector=0xAB
__interrupt void PDMA1_ISR(void){
  PDMA_Close(PDMA1);
  clr_DMA1TSR_FDONE;
  clr_DMA1TSR_HDONE;
}

void main (void) 
{
    ALL_GPIO_QUASI_MODE;

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
    
    FsysSelect(FSYS_LIRC);
    set_PCON_LPR;
    PDMA_Run(PDMA1);

    while(1);
}



