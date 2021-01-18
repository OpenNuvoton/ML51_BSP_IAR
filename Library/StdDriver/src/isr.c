/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: ML51 Interrupt demo code
//***********************************************************************************************************

#include "ML51_IAR.h"

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x03
__interrupt void INT0_ISR(void){
    _push_(SFRS);
 
     clr_TCON_IE0;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x0B
__interrupt void Timer0_ISR(void){
    _push_(SFRS);
 
    clr_TCON_TF0;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x13
__interrupt void INT1_ISR(void){
    _push_(SFRS);
 
    clr_TCON_IE1;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x1B
__interrupt void Timer1_ISR(void){
    _push_(SFRS);
 
    clr_TCON_TF1;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x23
__interrupt void UART0_ISR(void){
    _push_(SFRS);
 
    clr_SCON_RI;
    clr_SCON_TI;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x2B
__interrupt void Timer2_ISR(void){
    _push_(SFRS);
 
    clr_T2CON_TF2;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x33
__interrupt void I2C0_ISR(void){
    _push_(SFRS);
 
    clr_I2C0TOC_I2TOF;
    clr_I2C0CON_SI;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x3B
__interrupt void Pin_INT_ISR(void){
    _push_(SFRS);
 
    PIF = 0;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x43
__interrupt void BOD_ISR(void){
    _push_(SFRS);
 
    clr_BODCON0_BOF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x4B
__interrupt void SPI_ISR(void){
    _push_(SFRS);
 
    clr_SPI0SR_SPIF;
    clr_SPI0SR_MODF;
    clr_SPI0SR_SPIOVF;
    SPI0SR &= 0x4F;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x53
__interrupt void WDT_ISR (void){
    _push_(SFRS);
 
    clr_WDCON_WDTF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x5B
__interrupt void ADC_ISR (void){
    _push_(SFRS);
 
    clr_ADCCON0_ADCF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x63
__interrupt void Capture_ISR (void){
    _push_(SFRS);
 
    clr_CAPCON0_CAPF0;
    clr_CAPCON0_CAPF1;
    clr_CAPCON0_CAPF2;
    CAPCON0 &= 0xFC;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x6B
__interrupt void PWM_ISR (void){
    _push_(SFRS);
 
    clr_PWM0CON0_PWMF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x73
__interrupt void PWM_Brake_ISR(void){
    _push_(SFRS);
 
    clr_PWM0FBD_FBF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x7B
__interrupt void UART1_ISR(void){
    _push_(SFRS);
 
    clr_S1CON_RI_1;
    clr_S1CON_TI_1;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x83
__interrupt void Timer3_ISR(void){
    _push_(SFRS);
 
    clr_T3CON_TF3;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x8B
__interrupt void WKT_ISR(void){
    _push_(SFRS);
 
    clr_WKCON_WKTF;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x93
__interrupt void CPU_HARDFAULT(void){
    _push_(SFRS);
 
    clr_AUXR0_HFIF;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x9B
__interrupt void SMC0_ISR(void){
    _push_(SFRS);
 
    clr_SC0IS_RDAIF;
    clr_SC0IS_TBEIF;
    clr_SC0IS_TERRIF;
    clr_SC0IS_BGTIF;
    clr_SC0IS_ACERRIF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xA3
__interrupt void PDMA0_ISR(void){
    _push_(SFRS);
 
  clr_DMA0TSR_HDONE;
  clr_DMA0TSR_FDONE;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xAB
__interrupt void PDMA1_ISR(void){
    _push_(SFRS);
 
    clr_DMA1TSR_HDONE;
    clr_DMA1TSR_FDONE;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xB3
__interrupt void SPI1_ISR(void){
    _push_(SFRS);
 
    clr_SPI1SR_SPIF;
    clr_SPI1SR_MODF;
    clr_SPI1SR_SPIOVF;
    SPI1SR &= 0x4F;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xBB
__interrupt void ACMP_ISR(void){
    _push_(SFRS);
 
    clr_ACMPSR_ACMP0IF;
    clr_ACMPSR_ACMP1IF;
    ACMPSR &=0xFA;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xC3
__interrupt void I2C1_HARDFAULT(void){
    _push_(SFRS);
 
    clr_I2C1TOC_I2TOF;
    clr_I2C1CON_SI;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xCB
__interrupt void PWM1_ISR(void){
    _push_(SFRS);
 
    clr_PWM1CON0_PWMF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xD3
__interrupt void TK_ISR(void){
    _push_(SFRS);
 
    clr_TKSTA0_TKSCIF;
    clr_TKSTA0_TKIF;
    clr_TKSTA0_TKIF_ALL;
    clr_TKSTA1_TKIF0;
    clr_TKSTA1_TKIF1;
    clr_TKSTA1_TKIF2;
    clr_TKSTA1_TKIF3;
    clr_TKSTA1_TKIF4;
    clr_TKSTA1_TKIF5;
    clr_TKSTA1_TKIF6;
    clr_TKSTA1_TKIF7;
    clr_TKSTA2_TKIF8;
    clr_TKSTA2_TKIF8;
    clr_TKSTA2_TKIF9;
    clr_TKSTA2_TKIF10;
    clr_TKSTA2_TKIF11;
    clr_TKSTA2_TKIF12;
    clr_TKSTA2_TKIF13;
    clr_TKSTA2_TKIF14; 

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xDB
__interrupt void SMC1_ISR(void){
    _push_(SFRS);
  
    clr_SC1IS_RDAIF;
    clr_SC1IS_TBEIF;
    clr_SC1IS_TERRIF;
    clr_SC1IS_BGTIF;
    clr_SC1IS_ACERRIF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xE3
__interrupt void PDMA2_ISR(void){
    _push_(SFRS);
 
    clr_DMA2TSR_HDONE;
    clr_DMA2TSR_FDONE;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xEB
__interrupt void PDMA3_ISR(void){
    _push_(SFRS);
 
    clr_DMA3TSR_HDONE;
    clr_DMA3TSR_FDONE;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xF3
__interrupt void RTC_ISR(void){
    _push_(SFRS);
 
    clr_RTCINTSTS_ALMIF;
    clr_RTCINTSTS_TICKIF;

    _pop_(SFRS);
}

