/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"


/* define table data in the APROM */
/*table loacation is defined by keil compiler */
__code const unsigned char IMAGE_DATA[16] = {
    0x02, 0x02, 0x01, 0x11, 0x12, 0x12, 0x22, 0x22, 
    0x66, 0x69, 0x69, 0x59, 0x58, 0x99, 0x99, 0x88, 
};

//=========================================================================================================
void main(void)
{

    unsigned char readtemp ;
  
    ALL_GPIO_QUASI_MODE;
  
  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf("\n\r  Test start ...");
  
    printf("\n\r  Table Value = ");  

    for(readtemp=0;readtemp<0x10;readtemp++)
    {
      printf(" 0x%x ",IMAGE_DATA[readtemp]); 
    }
    while(1);
}