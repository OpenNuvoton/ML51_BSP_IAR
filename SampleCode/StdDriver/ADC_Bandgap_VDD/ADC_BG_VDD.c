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
//  File Function: ML51 ADC / Bandgap VDD demo code
//***********************************************************************************************************
#include "ML51_IAR.h"


/*****************  The Following is in define in Fucntion_define.h  ****************************/
/****** Always include Function_define.h call the define you want, detail see main(void) ********/
/************************************************************************************************/
double  Bandgap_Voltage,VDD_Voltage,Bandgap_Value;      //please always use "double" mode for this
unsigned char __xdata ADCdataH, ADCdataL;

/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void) 
{
    unsigned int ADC_BG_Result;

  /* ADC bandgap initial*/
      ADC_Open(ADC_SINGLE,VBG);
      ADC_SamplingTime(3,7);

  /*start bandgap ADC */
      clr_ADCCON0_ADCF;
      set_ADCCON0_ADCS;
      while(!(ADCCON0&SET_BIT7));
  /* to convert VDD value */
      ADC_BG_Result = (ADCRH<<4) + ADCRL;

///*                  VDD  Now                         READ_BANDGAP() VALUE              */
///*    ------------------------------------- = ----------------------------------       */
///*    3072mV(Storage value test condition)      NOW ADC Bandgap convert reuslt         */
      VDD_Voltage = ((float)READ_BANDGAP()/(float)ADC_BG_Result)*3.072;

///*            Bandgap real voltage                    READ_BANDGAP() VALUE             */
///*    ------------------------------------- = ----------------------------------       */
///*    3072mV(Storage value test condition)              4096(12bit ADC)                */
      Bandgap_Voltage = ((float)READ_BANDGAP()*3/4/1000);



    while(1);

}


