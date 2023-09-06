/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "ml51_iar.h"

/**
 * @brief       For printf function define  
 *
 * @param       none 
 *
 * @return      none
 *
 * @details     UART0 as printf use "#if 1", UART1 as printf output use "#if 0"
 */
 
 /**
* if use UART0 as printf source, enable following part
*/

#if 1
//char putchar (char c)  {
int putchar (int c)  {
  UART_Send_Data(UART0,c);
  return (c);
}
#else
int putchar (int c)  {
  UART_Send_Data(UART1,c);
  return (c);
}
#endif

/**
* if use UART1 as printf source, enable following part
*/
#if 0
char putchar (char c)
{
    while (!TI_1);  /* wait until transmitter ready */
    TI_1 = 0;
    SBUF1 = c;      /* output character */
    return (c);
}
#endif