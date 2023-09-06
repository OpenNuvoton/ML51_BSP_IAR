/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"


BIT  int1flag;
/* External pin interrupt INT0 subroutine */
#pragma vector=0x13
__interrupt void INT1_ISR(void){
    PUSH_SFRS;
    clr_TCON_IE1;                        //clr int flag wait next falling edge
    int1flag=1;
    POP_SFRS;
}

void main (void) 
{

    Enable_UART0_VCOM_printf();
    printf("\n\r  P24 INT1 external interrupt initial!!");


/* INT1 initial */
    MFP_P24_INT1;
    P24_QUASI_MODE;                      //setting INT0 pin P2.4 as Quasi mode with internal pull high  
    P24 = 1;
    INT1_LOW_LEVEL_TRIG;                 //setting trig condition level or edge
    ENABLE_INT1_INTERRUPT;               //INT1_Enable;
    ENABLE_GLOBAL_INTERRUPT;             //Global interrupt enable
    while(!int1flag);


    PUSH_SFRS;
    SFRS = 0;
    printf("\n\r  INT1 interrupt !");
    POP_SFRS;

    while(1);
}



