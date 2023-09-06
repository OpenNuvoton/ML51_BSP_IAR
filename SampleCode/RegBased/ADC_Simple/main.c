/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
unsigned int ADCdataAIN;

void main (void) 
{

  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf("\n\r  Test start ...");

    ENABLE_ADC_CH4;
    ADCCON1|=0x30;                     /* clock divider */
    ADCCON2|=0x0E;                     /* AQT time */
    clr_ADCCON0_ADCF;
    set_ADCCON0_ADCS;                  // ADC start trig signal
    while(!(ADCCON0&SET_BIT7));
    ADCdataAIN = ADCRH<<4;
    ADCdataAIN |= ADCRL;
  
      PUSH_SFRS;
      SFRS = 0;
      printf("\n\r  ADC result = 0x%x",ADCdataAIN);
      POP_SFRS;

    while(1);
}


