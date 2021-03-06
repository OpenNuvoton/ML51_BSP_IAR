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
//  File Function: ML51 GPIO toggle demo code
//***********************************************************************************************************
#include "ML51_IAR.h"



//----------------------------------------------------------------------------------------------//
void main (void)
{
/* As defaut all multi function define as GPIO */ 
  ALL_GPIO_QUASI_MODE;
  while(1)
  {
    P0 = ~P0;
    P1 = ~P1;
    P2 = ~P2;
    P3 = ~P3;
    P4 = ~P4;
    P5 = ~P5;
    SFRS = 2;
    P6 = ~P6;
    SFRS = 0;
    Timer2_Delay(24000000,4,200,1000);
  }
}



