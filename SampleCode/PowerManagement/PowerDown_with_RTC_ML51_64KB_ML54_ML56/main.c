/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

BIT rtc_alarm_flag;

/************************************************************************************************************/
/* FUNCTION_PURPOSE: RTC interrupt Service Routine                                                          */
/************************************************************************************************************/
#pragma vector=0xF3                             /* interrupt 30 */
__interrupt void RTC_ISR(void){
PUSH_SFRS;
    clr_RTCINTSTS_ALMIF;
    rtc_alarm_flag = 1;
POP_SFRS;
}
/************************************************************************************************************/
/* FUNCTION_PURPOSE: Main Loop                                                                              */
/************************************************************************************************************/
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
    P00 =1;
/* clock only for reference, real chip please don't output clock*/  
    set_CKCON_CLOEN;
/*MUST DISABLE BOD to low power */
    BOD_DISABLE;              //BOD enable power down current please check datasheet DC charactor.


    RTC_Clock_Select(LIRC);
/*RTC initial  */
    RTC_Initial_Pause();
    RTC_SetDate(2023,8,11,2);
    RTC_SetTime(23,59,58,RTC_CLOCK_24,0);
/*RTC Alarm timing setting   */
    RTC_SetAlarmDate(2023,8,12);
    RTC_SetAlarmTime(12,00,5,RTC_CLOCK_12,RTC_AM);
/*RTC interrupt setting   */
    RTC_Interrupt_Enable(RTC_ALARM);
    ENABLE_GLOBAL_INTERRUPT;
/*RTC run  */
    RTC_Initial_Run();
/* into power down mode waiting alatm interrupt wakeup */
    set_PCON_PD;
/* Aftr wakeup delay 2s then into power down again*/
    Timer0_Delay(24000000,2000,1000);
    
    POWERDOWN_MODE_ENABLE;
    while(1);
  
}



