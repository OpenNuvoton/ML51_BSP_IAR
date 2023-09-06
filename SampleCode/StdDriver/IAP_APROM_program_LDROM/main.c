/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "ml51_iar.h"

/**
 * @brief       IAP program LDROM sample 
 * @param       None
 * @return      None
 * @details     include erase whole LDROM area -> erase verify check blank -> program 128 byte in LDROM from 0x0000 -> verify programed data.
 * @note         PLEASE CONFIRM ENABLE CONFIG AREA FIRST BERFORE PROGRAM LDROM.
 * @note        BOD reset maybe cause IAP process error. Disable BOD reset function and enable BOD interrupt to check and reset. 
 */

void main (void) 
{
    unsigned char datatemp,count;

    /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf("\n\r  Enable LDROM by CONFIG setting first...");
    
    GPIO_LED_QUASI_MODE;
    while(GPIO_LED);                              //loop here while P32= 1;
  
    for(count=0;count<128;count++)          // define buffer data
    {
      IAPDataBuf[count]=count;
    }

/** IAP program LDROM, this code only run in APROM.
   * include IAP.c in Library for IAP function
   * @note  now maxima buffer size for program is 128 byte. buffer is locate in XRAM please check iap.h IAPDataBuf[128] define.
*/
    LDROM_Erase(0x0000,128);
    LDROM_Blank_Check(0x0000,2048);
    LDROM_Program(0x0000,128);
    LDROM_Read_Verify(0x0000,128);
      
/*flash read byte can't read LDROM area, following can't read LDROM data.*/
/* use ICP tool to read LDROM area, and always keep P46 = 1 except want to erase LDROM */
    datatemp = Read_APROM_BYTE((unsigned int __code *)0x7802);
    printf("\n\r  datatemp =0x%x", datatemp);
    
    while(1);
}



