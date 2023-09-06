/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"
#include "sprom.h"

__code const char lockdata@0xFFFF = 0xFF;  /* This byte as 0xFF means unlock SPROM. Any other value is lock*/

unsigned char SPTEMP=0;

void main (void) 
{
    unsigned char temp;
  
    set_IAPUEN_SPMEN;             //Enable SPROM memory mapping only for check SPROM in memory window
    Enable_UART0_VCOM_printf();
    SFRS = 0; 
    printf("\n\r  SPROM lock byte = 0x%x ", lockdata);
    GPIO_LED_QUASI_MODE;
    
    while(1)
    {
      temp = SPROM_FUNC(SPTEMP);
      SFRS = 0;
      printf("\n\r  SPTEMP= 0x%x", temp);
      Timer0_Delay(24000000,300,1000);
    }

}
