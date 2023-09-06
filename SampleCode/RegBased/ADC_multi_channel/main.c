/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

unsigned int __xdata ADCdataAIN5;
unsigned int __xdata ADCdataVBG;

/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void) 
{
    unsigned char i;

  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf("\n\r  Test start ...");

  /*Enable channel 5 */ 
      ENABLE_ADC_CH5;
      ADCCON1|=0X30;            /* clock divider */
      ADCCON2|=0X0E;            /* AQT time */
      clr_ADCCON0_ADCF;
      set_ADCCON0_ADCS;
      while(!(ADCCON0&SET_BIT7)); 
      ADCdataAIN5 = ADCRH<<4;
      ADCdataAIN5 |= (ADCRL&0x0F);
      DISABLE_ADC;
 #ifdef print_function
  /*printf must in SFR page 0 */
     PUSH_SFRS;
     SFRS = 0;
     printf("\n\r  ADC channel 5 = %d", ADCdataAIN5);
    POP_SFRS;
#endif

  /*Enable Bandgap */
      ENABLE_ADC_BANDGAP;
  /* IMPORTANT !!! multi channel convert must delay for ADC maocro ready */ 
      for (i=0;i<10;i++)
      _delay_();
      ADCCON1|=0X30;            /* clock divider */
      ADCCON2|=0X0E;            /* AQT time */
      clr_ADCCON0_ADCF;
      set_ADCCON0_ADCS;
      while(!(ADCCON0&SET_BIT7)); 
      ADCdataVBG = ADCRH<<4;
      ADCdataVBG |= ADCRL&0x0F;
#ifdef print_function
  /*printf must in SFR page 0 */
     PUSH_SFRS;
     SFRS = 0;
     printf("\n\r  ADC channel bandgap = %d", ADCdataVBG);
    POP_SFRS;
#endif

    while(1);
}