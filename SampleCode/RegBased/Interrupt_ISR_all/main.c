/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"


/*---------------------------------------------*/
void main(void)
{
    SET_INT_WDT_LEVEL0;
    Set_Interrupt_Priority_Level(INT_ADC, 1);
    while(1);
}

/* Check isr.c for full interrupt vector      */