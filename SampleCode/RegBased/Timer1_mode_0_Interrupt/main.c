/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

/* if define TIMER1_FSYS_DIV12, timer = (0x1FFF-0x1000)*12/24MHz = 4.086ms */
/* if define TIMER1_FSYS, timer = (0x1FFF-0x0010)/24MHz = 340us */
#define TH1_INIT        0x00 
#define TL1_INIT        0x10

/************************************************************************************************************
*    TIMER 0 interrupt subroutine
************************************************************************************************************/
#pragma vector=0x1B
__interrupt void Timer1_ISR(void){
    PUSH_SFRS;

    SFRS = 0;  
    TH1 = TH1_INIT;
    TL1 = TL1_INIT;    
    TF1 = 0 ;
    GPIO_LED ^= 1;                              // GPIO toggle when interrupt}
  
    POP_SFRS;
}

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{

    MFP_P32_GPIO;
    P32_PUSHPULL_MODE;
  
    ENABLE_TIMER1_MODE0;                           //Timer 0 mode configuration
    TIMER1_FSYS_DIV12;
      
    TH1 = TH1_INIT;
    TL1 = TL1_INIT;
    
    ENABLE_TIMER1_INTERRUPT;                       //enable Timer0 interrupt
    ENABLE_GLOBAL_INTERRUPT;                       //enable interrupts
  
    set_TCON_TR1;                                  //Timer0 run

  while(1);

}
