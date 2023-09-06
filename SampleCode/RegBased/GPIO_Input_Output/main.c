/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

__data __no_init unsigned char temp  @ 0x08 ;
__idata __no_init unsigned char itemp @ 0x90;
__xdata __no_init unsigned char  xtemp @ 0x80;

//----------------------------------------------------------------------------------------------//
void main (void)
{
/* As defaut all multi function define as GPIO */ 
  ALL_GPIO_QUASI_MODE;
  P60_PUSHPULL_MODE;
  P61_INPUT_MODE;

  while(1)
  {
    P1 = ~P1;
    P4 = ~P4;
    SFRS=0; set_P5_3;          /* or P5 |= SET_BIT3;  for none bit-addressable port */
    SFRS=2; P6 |= SET_BIT0;    /* or set_P6_0; for none bit-addressable port */
    if (!(P6&SET_BIT1))        /* if P6.1 == 0 , for none bit-addressable port */
    {
      _nop_();
    }
    Timer2_Delay(24000000,4,2,1000);

    SFRS=0; clr_P5_3;          /* or P5 &= CLR_BIT3;  for none bit-addressable port */
    SFRS=2; P6 &= CLR_BIT0;    /* or clr_P6_0;   for none bit-addressable port */
    if (P6&SET_BIT1)           /* if P6.1 == 1  for none bit-addressable port*/
    {
      _nop_();
    }
    Timer2_Delay(24000000,4,2,1000);
  }

}

