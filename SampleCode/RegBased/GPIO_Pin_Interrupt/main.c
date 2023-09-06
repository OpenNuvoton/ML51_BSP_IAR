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
    printf("\n\r  Test start!");
  /* Disable BOD for power down current */
    BOD_DISABLE;

  /* PIT initial setting */
    MFP_P17_GPIO;
    P17_INPUT_MODE;
    ENABLE_P17_PULLUP;

    MFP_P25_GPIO;
    P25_INPUT_MODE;
    ENABLE_P25_PULLUP;
    
    MFP_P35_GPIO;
    P35_INPUT_MODE;

    SFRS = 0;
    PIF = 0;
    ENABLE_PIT0_P17_LOWLEVEL;
    ENABLE_PIT1_P25_FALLINGEDGE;
    ENABLE_PIT2_P35_BOTHEDGE;
    ENABLE_PIN_INTERRUPT;                   // Enable pin interrupt
    ENABLE_GLOBAL_INTERRUPT;                // global enable bit

  /* mail loop in power down and wakeup check flag to print */
    PinIntVector = 0;
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


