/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************/
/* Website: http://www.nuvoton.com                                                                         */
/*  E-Mail : MicroC-8bit@nuvoton.com                                                                       */
/*  Date   : Apr/29/2020                                                                                   */
/***********************************************************************************************************/

/************************************************************************************************************/
/*  File Function: ML51 use UART0 as printf function output demo                                            */
/************************************************************************************************************/
#include "ML51_IAR.h"


void main (void) 
{

/* 
   For UART0 P3.1 as TXD output setting   
   include uart.c in Library Folder for UART0 
*/
    Enable_UART0_VCOM_printf();
    printf_UART("\n Hello world!");
    while(1);

}