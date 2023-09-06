/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

unsigned char PinIntVector;

/******************************************************************************
Pin interrupt subroutine.
******************************************************************************/
#pragma vector=0x3B
__interrupt void PIT_ISR(void){	
PUSH_SFRS;

    SFRS = 0;
    switch(PIF)
    {
      case (SET_BIT0): PinIntVector = SET_BIT0; PIF&=CLR_BIT0; break;
      case (SET_BIT1): PinIntVector = SET_BIT1; PIF&=CLR_BIT1; break;
      case (SET_BIT2): PinIntVector = SET_BIT2; PIF&=CLR_BIT2; break;
      default: break;
    }

POP_SFRS;
}
/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void) 
{
  /* UART0 initial for printf */
    Enable_UART0_VCOM_printf();
    printf("\n\r  PIT test start!");
  /* Disable BOD for power down current */
    BOD_DISABLE;

  /* PIT initial setting */
    MFP_P17_GPIO;
    MFP_P65_GPIO;

    GPIO_SetMode(Port1,SET_BIT7,GPIO_MODE_INPUT);
    GPIO_SetMode(Port6,SET_BIT5,GPIO_MODE_INPUT);
    GPIO_Pull_Enable(Port1,SET_BIT7,PULLUP);
    GPIO_Pull_Enable(Port6,SET_BIT5,PULLDOWN);
    GPIO_EnableInt(PIT0,BOTH,EDGE,Port1,7);
    GPIO_EnableInt(PIT1,HIGH,LEVEL,Port6,5);

    ENABLE_GLOBAL_INTERRUPT;
    PinIntVector = 0;
  /* mail loop in power down and wakeup check flag to print */
    while(1)
    {
       set_PCON_PD;
       _nop_();
       _nop_();

      switch(PinIntVector)
      {
        case (SET_BIT0): printf("\n\r  PIT0 interrupt!"); PinIntVector&=CLR_BIT0; break;
        case (SET_BIT1): printf("\n\r  PIT1 interrupt!"); PinIntVector&=CLR_BIT1; break;
        case (SET_BIT2): printf("\n\r  PIT2 interrupt!"); PinIntVector&=CLR_BIT2; break;
        default: break;
      }
    }
}


