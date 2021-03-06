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
//  File Function: ML51 Table complier in APROM demo code.
//***********************************************************************************************************
#include "ML51_IAR.h"


/* define table data in the APROM */
/*table loacation is defined by keil compiler */
__code const unsigned char IMAGE_DATA[16] = {
    0x02, 0x02, 0x01, 0x11, 0x12, 0x12, 0x22, 0x22, 
    0x66, 0x69, 0x69, 0x59, 0x58, 0x99, 0x99, 0x88, 
};

//=========================================================================================================
void main(void)
{

    unsigned char readtemp = 3;
  
    ALL_GPIO_QUASI_MODE;
  
/* Initial UART0 for printf */
    MFP_P31_UART0_TXD;
    P31_PUSHPULL_MODE;
    UART_Open(24000000,UART0_Timer3,115200);
    ENABLE_UART0_PRINTF;
  
    printf("\n Table Value = ");  
    printf(" %d ",readtemp); 
    for(readtemp=0;readtemp<0x10;readtemp++)
    {
      //printf_UART(" 0x%x ",IMAGE_DATA[readtemp]); 
      printf(" 0x%x ",IMAGE_DATA[readtemp]); 
    }
    while(1);
}