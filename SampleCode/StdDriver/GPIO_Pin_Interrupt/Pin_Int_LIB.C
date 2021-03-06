/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/29/2020
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: ML51 Pin interrupt demo
//***********************************************************************************************************
#include "ML51_IAR.h"

/* IMPORTANT !! This define for printf code only. Disable this define to reduce code size. */
#define print_function 
/******************************************************************************
Pin interrupt subroutine.
******************************************************************************/
#pragma vector=0x3B
__interrupt void Pin_INT_ISR(void){
    _push_(SFRS);
  
    SFRS = 0;
    switch(PIF)
    {
      case 0x01: printf_UART("\n PIT0 interrupt!"); break;
      case 0x02: printf_UART("\n PIT1 interrupt!"); break;
      case 0x04: printf_UART("\n PIT2 interrupt!"); break;
      default: break;
    }
    PIF = 0; 
  
    _pop_(SFRS);
}
/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void) 
{
#ifdef print_function
  /* UART0 initial setting
  ** include uart.c in Library for UART initial setting
  **UART0 define P3.1 TXD multi function setting
  **/
  Enable_UART0_VCOM_printf();
#endif

//----------------------------------------------------
//  P1.3 set as highlevel trig pin interrupt function
//  otherwise, MCU into idle mode.
//----------------------------------------------------

    MFP_P17_GPIO;
    MFP_P65_GPIO;

    P17_INPUT_MODE;
    P25_INPUT_MODE;

     ENABLE_P17_PULLUP;
     ENABLE_P25_PULLDOWN;

    ENABLE_PIT0_P17_FALLINGEDGE; 
    ENABLE_PIT1_P17_RISINGEDGE; 
    ENABLE_PIT2_P65_HIGHLEVEL;


    ENABLE_GLOBAL_INTERRUPT;                // global enable bit
    while(1);


}


