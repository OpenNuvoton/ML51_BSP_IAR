/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************/
/*  Website: http://www.nuvoton.com                                                                        */
/*  E-Mail : MicroC-8bit@nuvoton.com                                                                       */
/*  Date   : Apr/29/2020                                                                                   */
/***********************************************************************************************************/

//***********************************************************************************************************
//  File Function: ML51 series ADC continuous mode demo code
//***********************************************************************************************************

#include "ML51_IAR.h"

/* IMPORTANT !! This define for printf code only. Disable this define to reduce code size. */
#define print_function

__xdata  __no_init char ResultTable[256] @ 0x300;
BIT ADC_CONT_FINAL_FLAG;

/**
 * @brief       ADC Interrupt Subroutine
 * @param       None
 * @return      None
 * @details     Set ADC continus finished flag.
 */
#pragma vector=0x5B
__interrupt void ADC_ISR (void){
    _push_(SFRS);
  
    clr_ADCCON0_ADCF;
    ADC_CONT_FINAL_FLAG = 1;

    _pop_(SFRS);
}

/**
 * @brief       ADC continus mode main loop
 * @param       None
 * @return      None
 * @details     None
 */
void main (void) 
{
    unsigned char i;
    unsigned int temp;
    
#ifdef print_function
  /* UART0 initial setting
  ** include uart.c in Library for UART initial setting
  **UART0 define P3.1 TXD multi function setting
  **/
  Enable_UART0_VCOM_printf();
#endif

/* ADC continus mode setting . 
   *include adc.c for ADC initial setting
*/
    ADC_Open(ADC_CONTINUOUS,0);                        // Opend ADC as continous mode, and input from AIN0 P2.5
    ADC_InitialContinous(0x300,128,ADCHighSpeed);      // Define data restore in RAM start address and ADC total sample number 
    ADC_SamplingTime(2,7);                             // ADC clock = Fsys/4, sampling timer select longest value is 7
    ADC_Interrupt(Enable,ADC_INT_CONTDONE);            // Enable ADC interrupt when sampling total byte is done.
    ENABLE_GLOBAL_INTERRUPT;
    set_ADCCON0_ADCS;                                  // Trig ADCS bit to start ADC 

/* ADC finished and print the result from XRAM. */
    while(!ADC_CONT_FINAL_FLAG);
    ADC_Close();
    ADC_Interrupt(Disable,0);
    ENABLE_UART0_PRINTF;
    for(i=0;i<128;i++)
    {
      temp=(ResultTable[i]<<4)+(ResultTable[i/2+128]&0x0F);

#ifdef print_function
  /*printf must in SFR page 0 */
      _push_(SFRS);
      SFRS = 0;
      printf_UART("\n ADC No.%d",i);
      printf_UART(" = 0x%02x ", temp);
      _pop_(SFRS);
#endif

      i++;
      temp=(ResultTable[i]<<4)+((ResultTable[(i-1)/2+128]>>4)&0x0F);
#ifdef print_function
  /*printf must in SFR page 0 */
      _push_(SFRS);
      SFRS = 0;
      printf_UART("\n ADC No.%d",i);
      printf_UART(" = 0x%02x ", temp);
      _pop_(SFRS);
#endif
      if(i==127)
      ADC_CONT_FINAL_FLAG=0;
    }
    
    while(1);
}
