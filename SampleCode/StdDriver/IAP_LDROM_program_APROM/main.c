/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

void main (void) 
{
    unsigned char count;

  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf("\n\r  Test start ...");
    
    GPIO_LED_QUASI_MODE;
    while(GPIO_LED);                              //loop here while P32 = 1;
  
    for(count=0;count<128;count++)          // define buffer data
    {
      IAPDataBuf[count]=count;
    }
        
/** IAP program APROM, this code only run in LDROM.
   * include IAP.c in Library for IAP function
   * @note  now maxima buffer size for program is 128 byte. buffer is locate in XRAM please check in "iap.h" IAPDataBuf[128] define.
*/
    APROM_Erase(0x1000,128);
    APROM_Blank_Check(0x1000,128);
    APROM_Program(0x1000,128);
    APROM_Read_Verify(0x1000,128);
    printf("\n\r  Test pass !");
    while(1);
}



