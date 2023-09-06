/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

BIT rtc_alarm_flag;

void main (void) 
{
/*As Default all GPIO multi function is GPIO mode */ 
/*Quasi mode better for power down power comsuption */
    ALL_GPIO_QUASI_MODE;
    P0=0;
    P1=0;
    P2=0;
    P3=0;
    P4=0;
    P5=0;
    SFRS=2;P6=0;SFRS=0;
    P00 =1;          /* NuMaker LEDG2 disable */ 
/* clock only for reference, real chip please don't output clock*/  
    ENABLE_CLOCK_OUT;
/*MUST DISABLE BOD to low power */
    BOD_DISABLE;              //BOD enable power down current please check datasheet DC charactor.

/* into power down mode  */
    POWERDOWN_MODE_ENABLE;
    while(1);
  
}


