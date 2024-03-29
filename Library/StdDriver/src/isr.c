/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"

#if 0
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x03
__interrupt void INT0_ISR(void){
    PUSH_SFRS;
 
     clr_TCON_IE0;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x0B
__interrupt void Timer0_ISR(void){
    PUSH_SFRS;
 
    clr_TCON_TF0;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x13
__interrupt void INT1_ISR(void){
    PUSH_SFRS;
 
    clr_TCON_IE1;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x1B
__interrupt void Timer1_ISR(void){
    PUSH_SFRS;
 
    clr_TCON_TF1;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x23
__interrupt void UART0_ISR(void){
    PUSH_SFRS;
 
    clr_SCON_RI;
    clr_SCON_TI;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x2B
__interrupt void Timer2_ISR(void){
    PUSH_SFRS;
 
    clr_T2CON_TF2;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x33
__interrupt void I2C0_ISR(void){
    PUSH_SFRS;
 
    clr_I2C0TOC_I2TOF;
    clr_I2C0CON_SI;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x3B
__interrupt void Pin_INT_ISR(void){
    PUSH_SFRS;
 
    PIF = 0;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x43
__interrupt void BOD_ISR(void){
    PUSH_SFRS;
 
    clr_BODCON0_BOF;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x4B
__interrupt void SPI_ISR(void){
    PUSH_SFRS;
 
    clr_SPI0SR_SPIF;
    clr_SPI0SR_MODF;
    clr_SPI0SR_SPIOVF;
    SPI0SR &= 0x4F;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x53
__interrupt void WDT_ISR (void){
    PUSH_SFRS;
 
    clr_WDCON_WDTF;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x5B
__interrupt void ADC_ISR (void){
    PUSH_SFRS;
 
    clr_ADCCON0_ADCF;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x63
__interrupt void Capture_ISR (void){
    PUSH_SFRS;
 
    clr_CAPCON0_CAPF0;
    clr_CAPCON0_CAPF1;
    clr_CAPCON0_CAPF2;
    CAPCON0 &= 0xFC;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x6B
__interrupt void PWM_ISR (void){
    PUSH_SFRS;
 
    clr_PWM0CON0_PWMF;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x73
__interrupt void PWM_Brake_ISR(void){
    PUSH_SFRS;
 
    clr_PWM0FBD_FBF;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x7B
__interrupt void UART1_ISR(void){
    PUSH_SFRS;
 
    clr_S1CON_RI_1;
    clr_S1CON_TI_1;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x83
__interrupt void Timer3_ISR(void){
    PUSH_SFRS;
 
    clr_T3CON_TF3;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x8B
__interrupt void WKT_ISR(void){
    PUSH_SFRS;
 
    clr_WKCON_WKTF;

    POP_SFRS;
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x93
__interrupt void CPU_HARDFAULT(void){
    PUSH_SFRS;
 
    clr_AUXR0_HFIF;

    POP_SFRS;
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0x9B
__interrupt void SMC0_ISR(void){
    PUSH_SFRS;
 
    clr_SC0IS_RDAIF;
    clr_SC0IS_TBEIF;
    clr_SC0IS_TERRIF;
    clr_SC0IS_BGTIF;
    clr_SC0IS_ACERRIF;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xA3
__interrupt void PDMA0_ISR(void){
    PUSH_SFRS;
 
  clr_DMA0TSR_HDONE;
  clr_DMA0TSR_FDONE;

    POP_SFRS;
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xAB
__interrupt void PDMA1_ISR(void){
    PUSH_SFRS;
 
    clr_DMA1TSR_HDONE;
    clr_DMA1TSR_FDONE;

    POP_SFRS;
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xB3
__interrupt void SPI1_ISR(void){
    PUSH_SFRS;
 
    clr_SPI1SR_SPIF;
    clr_SPI1SR_MODF;
    clr_SPI1SR_SPIOVF;
    SPI1SR &= 0x4F;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xBB
__interrupt void ACMP_ISR(void){
    PUSH_SFRS;
 
    clr_ACMPSR_ACMP0IF;
    clr_ACMPSR_ACMP1IF;
    ACMPSR &=0xFA;

    POP_SFRS;
}

//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xC3
__interrupt void I2C1_HARDFAULT(void){
    PUSH_SFRS;
 
    clr_I2C1TOC_I2TOF;
    clr_I2C1CON_SI;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xCB
__interrupt void PWM1_ISR(void){
    PUSH_SFRS;
 
    clr_PWM1CON0_PWMF;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xD3
__interrupt void TK_ISR(void){
    PUSH_SFRS;
 
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

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xDB
__interrupt void SMC1_ISR(void){
    PUSH_SFRS;
  
    clr_SC1IS_RDAIF;
    clr_SC1IS_TBEIF;
    clr_SC1IS_TERRIF;
    clr_SC1IS_BGTIF;
    clr_SC1IS_ACERRIF;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xE3
__interrupt void PDMA2_ISR(void){
    PUSH_SFRS;
 
    clr_DMA2TSR_HDONE;
    clr_DMA2TSR_FDONE;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xEB
__interrupt void PDMA3_ISR(void){
    PUSH_SFRS;
 
    clr_DMA3TSR_HDONE;
    clr_DMA3TSR_FDONE;

    POP_SFRS;
}
//-----------------------------------------------------------------------------------------------------------
#pragma vector=0xF3
__interrupt void RTC_ISR(void){
    PUSH_SFRS;
 
    clr_RTCINTSTS_ALMIF;
    clr_RTCINTSTS_TICKIF;

    POP_SFRS;
}

#pragma vector=0xFB
__interrupt void LCD_ISR(void){
    PUSH_SFRS;
 
    POP_SFRS;
}
#endif 

/**
  * @brief This API configures Interrupt level
  * @param[in] u8InterruptSource . Valid values are the interrupt name:
  *                       - \ref INT_INT0       
  *                       - \ref INT_BOD        
  *                       - \ref INT_WDT        
  *                       - \ref INT_Timer0     
  *                       - \ref INT_I2C0       
  *                       - \ref INT_ADC        
  *                       - \ref INT_INT1       
  *                       - \ref INT_PIT        
  *                       - \ref INT_Timer1     
  *                       - \ref INT_UART0      
  *                       - \ref INT_PWM0_Brake 
  *                       - \ref INT_SPI0       
  *                       - \ref INT_Timer2     
  *                       - \ref INT_Capture    
  *                       - \ref INT_PWM0       
  *                       - \ref INT_UART1      
  *                       - \ref INT_Timer3           
  *                       - \ref INT_WKT        
  *                       - \ref INT_SMC0      
  *                       - \ref INT_PDMA0      
  *                       - \ref INT_PDMA1      
  *                       - \ref INT_SPI1       
  *                       - \ref INT_ACMP       
  *                       - \ref INT_I2C1       
  *                       - \ref INT_PWM123     
  *                       - \ref INT_SMC1       
  *                       - \ref INT_PDMA2      
  *                       - \ref INT_PDMA3      
  *                       - \ref INT_RTC      
  * @note      u8u8InterruptPriorityLevel.Valid values are the interrupt level number:
  *                       - \ref 0~3            :
  * @exmaple : Set_Interrupt_Priority_Level(INT_ADC, 1);
*/
void Set_Interrupt_Priority_Level( unsigned char u8InterruptSource, unsigned char u8u8InterruptPriorityLevel)
{
   switch (u8InterruptSource)
   {
        case INT_INT0        :
          switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_IP_PX0; clr_IPH_PX0H; break;
            case 1:  clr_IP_PX0; set_IPH_PX0H; break;
            case 2:  set_IP_PX0; clr_IPH_PX0H; break;
            case 3:  set_IP_PX0; set_IPH_PX0H; break;
          }
        case INT_BOD          :
                switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_IP_PBOD; clr_IPH_PBODH; break;
            case 1:  clr_IP_PBOD; set_IPH_PBODH; break;
            case 2:  set_IP_PBOD; clr_IPH_PBODH; break;
            case 3:  set_IP_PBOD; set_IPH_PBODH; break;
          }
        case INT_WDT           :
               switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_EIP0_PWDT; clr_EIPH0_PWDTH; break;
            case 1:  clr_EIP0_PWDT; set_EIPH0_PWDTH; break;
            case 2:  set_EIP0_PWDT; clr_EIPH0_PWDTH; break;
            case 3:  set_EIP0_PWDT; set_EIPH0_PWDTH; break;
          }        
        case INT_Timer0        :
                switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_IP_PT0; clr_IPH_PT0H; break;
            case 1:  clr_IP_PT0; set_IPH_PT0H; break;
            case 2:  set_IP_PT0; clr_IPH_PT0H; break;
            case 3:  set_IP_PT0; set_IPH_PT0H; break;
          }
        case INT_I2C0          :
                switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_EIP0_PI2C0; clr_EIPH0_PI2C0H; break;
            case 1:  clr_EIP0_PI2C0; set_EIPH0_PI2C0H; break;
            case 2:  set_EIP0_PI2C0; clr_EIPH0_PI2C0H; break;
            case 3:  set_EIP0_PI2C0; set_EIPH0_PI2C0H; break;
          }
        case INT_ADC           :
                switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_IP_PADC; clr_IPH_PADCH; break;
            case 1:  clr_IP_PADC; set_IPH_PADCH; break;
            case 2:  set_IP_PADC; clr_IPH_PADCH; break;
            case 3:  set_IP_PADC; set_IPH_PADCH; break;
          }        
        case INT_INT1        :
          switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_IP_PX1; clr_IPH_PX1H; break;
            case 1:  clr_IP_PX1; set_IPH_PX1H; break;
            case 2:  set_IP_PX1; clr_IPH_PX1H; break;
            case 3:  set_IP_PX1; set_IPH_PX1H; break;
          }
        case INT_PIT           :
                switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_EIP0_PPI; clr_EIPH0_PPIH; break;
            case 1:  clr_EIP0_PPI; set_EIPH0_PPIH; break;
            case 2:  set_EIP0_PPI; clr_EIPH0_PPIH; break;
            case 3:  set_EIP0_PPI; set_EIPH0_PPIH; break;
          }        
        case INT_Timer1        :
                switch (u8u8InterruptPriorityLevel)
          {
            case 0:  clr_IP_PT1; clr_IPH_PT1H; break;
            case 1:  clr_IP_PT1; set_IPH_PT1H; break;
            case 2:  set_IP_PT1; clr_IPH_PT1H; break;
            case 3:  set_IP_PT1; set_IPH_PT1H; break;
          }
        case INT_UART0         :
              switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_IP_PS; clr_IPH_PSH; break;
            case 1:  clr_IP_PS; set_IPH_PSH; break;
            case 2:  set_IP_PS; clr_IPH_PSH; break;
            case 3:  set_IP_PS; set_IPH_PSH; break;
          }        
        case INT_PWM0_Brake :
              switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP0_PFB; clr_EIPH0_PFBH; break;
            case 1:  clr_EIP0_PFB; set_EIPH0_PFBH; break;
            case 2:  set_EIP0_PFB; clr_EIPH0_PFBH; break;
            case 3:  set_EIP0_PFB; set_EIPH0_PFBH; break;
          }
        case INT_SPI0          :
              switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP0_PSPI; clr_EIPH0_PSPIH; break;
            case 1:  clr_EIP0_PSPI; set_EIPH0_PSPIH; break;
            case 2:  set_EIP0_PSPI; clr_EIPH0_PSPIH; break;
            case 3:  set_EIP0_PSPI; set_EIPH0_PSPIH; break;
          }        
        case INT_Timer2        :
              switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP0_PT2; clr_EIPH0_PT2H; break;
            case 1:  clr_EIP0_PT2; set_EIPH0_PT2H; break;
            case 2:  set_EIP0_PT2; clr_EIPH0_PT2H; break;
            case 3:  set_EIP0_PT2; set_EIPH0_PT2H; break;
          }         
        case INT_Capture       :
              switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP0_PCAP; clr_EIPH0_PCAPH; break;
            case 1:  clr_EIP0_PCAP; set_EIPH0_PCAPH; break;
            case 2:  set_EIP0_PCAP; clr_EIPH0_PCAPH; break;
            case 3:  set_EIP0_PCAP; set_EIPH0_PCAPH; break;
          }
        case INT_PWM0          :
              switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP0_PPWM0; clr_EIPH0_PPWM0H; break;
            case 1:  clr_EIP0_PPWM0; set_EIPH0_PPWM0H; break;
            case 2:  set_EIP0_PPWM0; clr_EIPH0_PPWM0H; break;
            case 3:  set_EIP0_PPWM0; set_EIPH0_PPWM0H; break;
          }
        case INT_UART1         :
             switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP1_PS1; clr_EIPH1_PS1H; break;
            case 1:  clr_EIP1_PS1; set_EIPH1_PS1H; break;
            case 2:  set_EIP1_PS1; clr_EIPH1_PS1H; break;
            case 3:  set_EIP1_PS1; set_EIPH1_PS1H; break;
          }        
        case INT_Timer3        :        
            switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP1_PT3; clr_EIPH1_PT3H; break;
            case 1:  clr_EIP1_PT3; set_EIPH1_PT3H; break;
            case 2:  set_EIP1_PT3; clr_EIPH1_PT3H; break;
            case 3:  set_EIP1_PT3; set_EIPH1_PT3H; break;
          } 
        case INT_WKT           :
            switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP1_PWKT; clr_EIPH1_PWKTH; break;
            case 1:  clr_EIP1_PWKT; set_EIPH1_PWKTH; break;
            case 2:  set_EIP1_PWKT; clr_EIPH1_PWKTH; break;
            case 3:  set_EIP1_PWKT; set_EIPH1_PWKTH; break;
          }           
        case INT_SMC0          :                  
            switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP1_PSMC0; clr_EIPH1_PSMC0H; break;
            case 1:  clr_EIP1_PSMC0; set_EIPH1_PSMC0H; break;
            case 2:  set_EIP1_PSMC0; clr_EIPH1_PSMC0H; break;
            case 3:  set_EIP1_PSMC0; set_EIPH1_PSMC0H; break;
          }
        case INT_PDMA0         :
            switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP1_PDMA0; clr_EIPH1_PDMA0H; break;
            case 1:  clr_EIP1_PDMA0; set_EIPH1_PDMA0H; break;
            case 2:  set_EIP1_PDMA0; clr_EIPH1_PDMA0H; break;
            case 3:  set_EIP1_PDMA0; set_EIPH1_PDMA0H; break;
          }
        case INT_PDMA1         :
            switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP1_PDMA1; clr_EIPH1_PDMA1H; break;
            case 1:  clr_EIP1_PDMA1; set_EIPH1_PDMA1H; break;
            case 2:  set_EIP1_PDMA1; clr_EIPH1_PDMA1H; break;
            case 3:  set_EIP1_PDMA1; set_EIPH1_PDMA1H; break;
          }    
        case INT_SPI1          :
            switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP1_PSPI1; clr_EIPH1_PSPI1H; break;
            case 1:  clr_EIP1_PSPI1; set_EIPH1_PSPI1H; break;
            case 2:  set_EIP1_PSPI1; clr_EIPH1_PSPI1H; break;
            case 3:  set_EIP1_PSPI1; set_EIPH1_PSPI1H; break;
          }
        case INT_ACMP          :
            switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP2_PACMP; clr_EIPH2_PACMPH; break;
            case 1:  clr_EIP2_PACMP; set_EIPH2_PACMPH; break;
            case 2:  set_EIP2_PACMP; clr_EIPH2_PACMPH; break;
            case 3:  set_EIP2_PACMP; set_EIPH2_PACMPH; break;
          }        
        case INT_I2C1          :
            switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP2_PI2C1; clr_EIPH2_PI2C1H; break;
            case 1:  clr_EIP2_PI2C1; set_EIPH2_PI2C1H; break;
            case 2:  set_EIP2_PI2C1; clr_EIPH2_PI2C1H; break;
            case 3:  set_EIP2_PI2C1; set_EIPH2_PI2C1H; break;
          } 
        case INT_PWM123        :
           switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP2_PPWM1; clr_EIPH2_PPWM1H; break;
            case 1:  clr_EIP2_PPWM1; set_EIPH2_PPWM1H; break;
            case 2:  set_EIP2_PPWM1; clr_EIPH2_PPWM1H; break;
            case 3:  set_EIP2_PPWM1; set_EIPH2_PPWM1H; break;
          }
        case INT_SMC1          :
           switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP2_PSMC1; clr_EIPH2_PSMC1H; break;
            case 1:  clr_EIP2_PSMC1; set_EIPH2_PSMC1H; break;
            case 2:  set_EIP2_PSMC1; clr_EIPH2_PSMC1H; break;
            case 3:  set_EIP2_PSMC1; set_EIPH2_PSMC1H; break;
          }
        case INT_PDMA2         :
           switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP2_PPDMA2; clr_EIPH2_PPDMA2H; break;
            case 1:  clr_EIP2_PPDMA2; set_EIPH2_PPDMA2H; break;
            case 2:  set_EIP2_PPDMA2; clr_EIPH2_PPDMA2H; break;
            case 3:  set_EIP2_PPDMA2; set_EIPH2_PPDMA2H; break;
          }
        case INT_PDMA3         :
           switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP2_PPDMA3; clr_EIPH2_PPDMA3H; break;
            case 1:  clr_EIP2_PPDMA3; set_EIPH2_PPDMA3H; break;
            case 2:  set_EIP2_PPDMA3; clr_EIPH2_PPDMA3H; break;
            case 3:  set_EIP2_PPDMA3; set_EIPH2_PPDMA3H; break;
          }
        case INT_RTC         :
           switch (u8u8InterruptPriorityLevel)
          {          
            case 0:  clr_EIP2_PRTC; clr_EIPH2_PRTCH; break;
            case 1:  clr_EIP2_PRTC; set_EIPH2_PRTCH; break;
            case 2:  set_EIP2_PRTC; clr_EIPH2_PRTCH; break;
            case 3:  set_EIP2_PRTC; set_EIPH2_PRTCH; break;
          }
        
          break;
   }
 }