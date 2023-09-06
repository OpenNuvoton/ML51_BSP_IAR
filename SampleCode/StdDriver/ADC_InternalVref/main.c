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
void main () 
{
  unsigned int ADCRESULT;

    Enable_UART0_VCOM_printf();
    printf("\n\r  Test start ...");
/*
  ADCS to trig ADC convert 
  * include adc.c in Library for ADC initial setting
*/  
    VREF_Open(LEVEL1);
    ADC_Open(ADC_SINGLE,5);
    ADC_SamplingTime(3,7);
  
/* find ADC result in ADC interrupt*/
     set_ADCCON0_ADCS;                           // Software trig adc start
     while(!(ADCCON0&SET_BIT7));;                // wait ADCF = 1;
     ADCRESULT = ADCRH<<4;
     ADCRESULT |= ADCRL;
  /*printf must in SFR page 0 */
      PUSH_SFRS;
      SFRS = 0;
      printf("\n\r  ADC result = 0x%x  ", ADCRESULT);
      POP_SFRS;

    while(1);
  
}

