/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2019 Nuvoton Technology Corp. All rights reserved.       */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************/
/* Website: http://www.nuvoton.com                                                                         */
/*  E-Mail : MicroC-8bit@nuvoton.com                                                                       */
/*  Date   : Jan/21/2019                                                                                   */
/***********************************************************************************************************/

//***********************************************************************************************************
//  File Function: MS51 locate data in APROM simple demo 
//***********************************************************************************************************
#include "ML51_IAR.h"

unsigned char  SPTEMP=1;

int SPROM_CODE (void) 
{
  SPTEMP++;
  return 0;
}

void main (void) 
{
    set_IAPUEN_SPMEN;             //Enable SPROM memory mapping only for check SPROM in memory window
    MFP_P31_UART0_TXD;          // Define in Function_define.h
    P31_QUASI_MODE;
    UART_Open(24000000,UART0_Timer1,115200);
    ENABLE_UART0_PRINTF;
    while(1)
    {
      SPROM_CODE();
      printf_UART("\n SPTEMP= 0x%x", SPTEMP);
      Timer0_Delay(24000000,300,1000);
    }

}

