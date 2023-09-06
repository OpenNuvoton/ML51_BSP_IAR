/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 TIMER 2 Capture function demo
//***********************************************************************************************************
#include "ml51_iar.h"

BIT t2captureflag;
unsigned char captemph,captempl;

/**
 * @brief       Timer2 interrupt subroutine
 */
#pragma vector=0x63
__interrupt void Capture_ISR(void){
  
PUSH_SFRS;

    SFRS = 1;
    if (CAPCON0&SET_BIT0)
    {
       captemph = C0H;
       captempl = C0L;
       clr_CAPCON0_CAPF0;
    }
    else if (CAPCON0&SET_BIT2)
    {
       captemph = C2H;
       captempl = C2L;
       clr_CAPCON0_CAPF2;
    }
    t2captureflag = 1;

    DISABLE_TIMER2_CAP0;

POP_SFRS;
}


void main (void) 
{

    Enable_UART0_VCOM_printf();
    printf("\n\r  ML51 series capture demo." );

/* Setting Multi function pin setting for GPIO toggle */ 
    MFP_P33_IC0;
    P33_INPUT_MODE;                          //Define P33 as IC0 input pin.
    ENABLE_P33_PULLDOWN;                       //Since check falling edge enalbe internal pull high function.
    TIMER2_Capture(IC0,CaptureRising,2);

    MFP_P11_IC2;
    P11_INPUT_MODE;                          //Define P11 as IC2 input pin.
    ENABLE_P11_PULLUP;                       //Since check falling edge enalbe internal pull high function.
    TIMER2_Capture(IC2,CaptureEither,7);;

    TIMER2_Capture_Interrupt(Enable);
    Global_Interrupt(Enable);

    while(1)
    {
      if (t2captureflag)
      {
          t2captureflag = 0;
          SFRS=0; 
          printf("\n\r  capture high byte = 0x%x", captemph);
          printf("\n\r  capture low byte = 0x%x", captempl);
      }
    }
}



