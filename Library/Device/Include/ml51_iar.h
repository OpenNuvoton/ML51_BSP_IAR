/*--------------------------------------------------------------------------
ml51_iar.h

Header file for Nuvoton ML51 Series
--------------------------------------------------------------------------*/

/******************************************************************************/
/*                         Macro define header files                          */
/******************************************************************************/
#include "sfr_macro_ml51_iar.h"

/* ML51 SFR BYTE page 0  */
__sfr __no_init volatile union
{
  unsigned char P0; /* Port 0 */
  struct /* Port 0 */
  { 
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
    
  } P0_bit;
} @ 0x80;
__sfr __no_init volatile unsigned char   SP                         @ 0x81;
__sfr __no_init volatile unsigned char   DPL                        @ 0x82;
__sfr __no_init volatile unsigned char   DPH                        @ 0x83;
__sfr __no_init volatile unsigned char   RCTRIM0                    @ 0x84;
__sfr __no_init volatile unsigned char   RCTRIM1                    @ 0x85;
__sfr __no_init volatile unsigned char   RWKL                       @ 0x86;
__sfr __no_init volatile unsigned char   PCON                       @ 0x87;

__sfr __no_init volatile union
{
  unsigned char TCON; /* Timer Control */
  struct /* Timer Control */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
    
  } TCON_bit;
} @ 0x88;
__sfr __no_init volatile unsigned char   TMOD                       @ 0x89;
__sfr __no_init volatile unsigned char   TL0                        @ 0x8A;
__sfr __no_init volatile unsigned char   TL1                        @ 0x8B;
__sfr __no_init volatile unsigned char   TH0                        @ 0x8C;
__sfr __no_init volatile unsigned char   TH1                        @ 0x8D;
__sfr __no_init volatile unsigned char   CKCON                      @ 0x8E;
__sfr __no_init volatile unsigned char   WKCON                      @ 0x8F;

__sfr __no_init volatile union
{
  unsigned char P1; /* Port 1 */
  struct /* Port 1 */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;    
  } P1_bit;
} @ 0x90;
__sfr __no_init volatile unsigned char   SFRS                       @ 0x91;
__sfr __no_init volatile unsigned char   DMA0CR0                    @ 0x92;
__sfr __no_init volatile unsigned char   DMA0MAL                    @ 0x93;
__sfr __no_init volatile unsigned char   DMA0CNT                    @ 0x94;
__sfr __no_init volatile unsigned char   DMA0CCNT                   @ 0x95;
__sfr __no_init volatile unsigned char   CKSWT                      @ 0x96;
__sfr __no_init volatile unsigned char   CKEN                       @ 0x97;

__sfr __no_init volatile union
{
  unsigned char SCON; /* Serial Control */
  struct /* Serial Control */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } SCON_bit;
} @ 0x98;
__sfr __no_init volatile unsigned char   SBUF                       @ 0x99;
__sfr __no_init volatile unsigned char   SBUF1                      @ 0x9A;
__sfr __no_init volatile unsigned char   EIE0                       @ 0x9B;
__sfr __no_init volatile unsigned char   EIE1                       @ 0x9C;
__sfr __no_init volatile unsigned char   RSR                        @ 0x9D;
__sfr __no_init volatile unsigned char   CHPCON                     @ 0x9F;

__sfr __no_init volatile union
{
  unsigned char P2; /* Port 2 */
  struct /* Port 2 */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } P2_bit;
} @ 0xA0;
__sfr __no_init volatile unsigned char   ADCCON0                    @ 0xA1;
__sfr __no_init volatile unsigned char   AUXR0                      @ 0xA2;
__sfr __no_init volatile unsigned char   BODCON0                    @ 0xA3;
__sfr __no_init volatile unsigned char   IAPTRG                     @ 0xA4;
__sfr __no_init volatile unsigned char   IAPUEN                     @ 0xA5;
__sfr __no_init volatile unsigned char   IAPAL                      @ 0xA6;
__sfr __no_init volatile unsigned char   IAPAH                      @ 0xA7;

__sfr __no_init volatile union
{
  unsigned char IE; /* Interrupt Enable */
  struct /* Interrupt Enable */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } IE_bit;
} @ 0xA8;
__sfr __no_init volatile unsigned char   SADDR                      @ 0xA9;
__sfr __no_init volatile unsigned char   WDCON                      @ 0xAA;
__sfr __no_init volatile unsigned char   BODCON1                    @ 0xAB;
__sfr __no_init volatile unsigned char   EIP2                       @ 0xAC;
__sfr __no_init volatile unsigned char   EIPH2                      @ 0xAD;
__sfr __no_init volatile unsigned char   IAPFD                      @ 0xAE;
__sfr __no_init volatile unsigned char   IAPCN                      @ 0xAF;

__sfr __no_init volatile union
{
  unsigned char P3; /* Port 3 */
  struct /* Port 3 */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } P3_bit;
} @ 0xB0;
__sfr __no_init volatile unsigned char   P5                         @ 0xB1;
__sfr __no_init volatile unsigned char   I2C1ADDR0                  @ 0xB2;
__sfr __no_init volatile unsigned char   I2C1DAT                    @ 0xB3;
__sfr __no_init volatile unsigned char   I2C1STAT                   @ 0xB4;
__sfr __no_init volatile unsigned char   I2C1CLK                    @ 0xB5;
__sfr __no_init volatile unsigned char   I2C1TOC                    @ 0xB6;
__sfr __no_init volatile unsigned char   IPH                        @ 0xB7;

__sfr __no_init volatile union
{
  unsigned char IP; /* IP  */
  struct /* IP  */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
  } IP_bit;
} @ 0xB8;
__sfr __no_init volatile unsigned char   SADEN                      @ 0xB9;
__sfr __no_init volatile unsigned char   SADEN1                     @ 0xBA;
__sfr __no_init volatile unsigned char   SADDR1                     @ 0xBB;
__sfr __no_init volatile unsigned char   I2C0DAT                    @ 0xBC;
__sfr __no_init volatile unsigned char   I2C0STAT                   @ 0xBD;
__sfr __no_init volatile unsigned char   I2C0CLK                    @ 0xBE;
__sfr __no_init volatile unsigned char   I2C0TOC                    @ 0xBF;

__sfr __no_init volatile union
{
  unsigned char I2C0CON; /* I2C0CON  */
  struct /* I2C0CON  */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } I2C0CON_bit;
} @ 0xC0;
__sfr __no_init volatile unsigned char   I2C0ADDR0                  @ 0xC1;
__sfr __no_init volatile unsigned char   ADCRL                      @ 0xC2;
__sfr __no_init volatile unsigned char   ADCRH                      @ 0xC3;
__sfr __no_init volatile unsigned char   T3CON                      @ 0xC4;
__sfr __no_init volatile unsigned char   RL3                        @ 0xC5;
__sfr __no_init volatile unsigned char   RH3                        @ 0xC6;
__sfr __no_init volatile unsigned char   TA                         @ 0xC7;

__sfr __no_init volatile union
{
  unsigned char T2CON; /* Timer 2 Control */
  struct /* Timer 2 Control */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT7 : 1;
  } T2CON_bit;
} @ 0xC8;
__sfr __no_init volatile unsigned char   T2MOD                      @ 0xC9;
__sfr __no_init volatile unsigned char   PIF                        @ 0xCA;
__sfr __no_init volatile unsigned char   ADCBAL                     @ 0xCB;
__sfr __no_init volatile unsigned char   TL2                        @ 0xCC;
__sfr __no_init volatile unsigned char   TH2                        @ 0xCD;
__sfr __no_init volatile unsigned char   ADCMPL                     @ 0xCE;
__sfr __no_init volatile unsigned char   ADCMPH                     @ 0xCF;

__sfr __no_init volatile union
{
  unsigned char PSW; /* Program Status Word */
  struct /* Program Status Word */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;    
  } PSW_bit;
} @ 0xD0;
__sfr __no_init volatile unsigned char   PWM0CON0                   @ 0xD1;
__sfr __no_init volatile unsigned char   ACMPCR0                    @ 0xD2;
__sfr __no_init volatile unsigned char   ACMPCR1                    @ 0xD3;
__sfr __no_init volatile unsigned char   ACMPSR                     @ 0xD4;
__sfr __no_init volatile unsigned char   ACMPVREF                   @ 0xD5;
__sfr __no_init volatile unsigned char   SC0CR0                     @ 0xD6;
__sfr __no_init volatile unsigned char   SC0CR1                     @ 0xD7;

__sfr __no_init volatile union
{
  unsigned char P4; /* Port 4 */
  struct /* Port 4 */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;    
  } P4_bit;
} @ 0xD8;
__sfr __no_init volatile unsigned char   SC0DR                      @ 0xD9;
__sfr __no_init volatile unsigned char   SC0EGT                     @ 0xDA;
__sfr __no_init volatile unsigned char   SC0ETURD0                  @ 0xDB;
__sfr __no_init volatile unsigned char   SC0ETURD1                  @ 0xDC;
__sfr __no_init volatile unsigned char   SC0IE                      @ 0xDD;
__sfr __no_init volatile unsigned char   SC0IS                      @ 0xDE;
__sfr __no_init volatile unsigned char   SC0TSR                     @ 0xDF;

__sfr __no_init volatile union
{
  unsigned char ACC; /* Accumulator */
  struct /* Accumulator */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;    
  } ACC_bit;
} @ 0xE0;
__sfr __no_init volatile unsigned char   ADCCON1                    @ 0xE1;
__sfr __no_init volatile unsigned char   ADCCON2                    @ 0xE2;
__sfr __no_init volatile unsigned char   ADCDLY                     @ 0xE3;
__sfr __no_init volatile unsigned char   ADCBAH                     @ 0xE4;
__sfr __no_init volatile unsigned char   ADCSN                      @ 0xE5;
__sfr __no_init volatile unsigned char   ADCCN                      @ 0xE6;
__sfr __no_init volatile unsigned char   ADCSR                      @ 0xE7;

__sfr __no_init volatile union
{
  unsigned char I2C1CON; /* I2C1CON  */
  struct /* I2C1CON  */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } I2C1CON_bit;
} @ 0xE8;
__sfr __no_init volatile unsigned char   DMA0TSR                    @ 0xE9;
__sfr __no_init volatile unsigned char   MTM0DAL                     @ 0xEA;
__sfr __no_init volatile unsigned char   DMA1CR0                    @ 0xEB;
__sfr __no_init volatile unsigned char   DMA1MAL                    @ 0xEC;
__sfr __no_init volatile unsigned char   DMA1CNT                    @ 0xED;
__sfr __no_init volatile unsigned char   DMA1CCNT                   @ 0xEE;
__sfr __no_init volatile unsigned char   EIP0                       @ 0xEF;

__sfr __no_init volatile union
{
  unsigned char B; /* B Register */
  struct /* B Register */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } B_bit;
} @ 0xF0;
__sfr __no_init volatile unsigned char   DMA1TSR                    @ 0xF1;
__sfr __no_init volatile unsigned char   MTM1DAL                     @ 0xF2;
__sfr __no_init volatile unsigned char   SPI0CR0                    @ 0xF3;
__sfr __no_init volatile unsigned char   SPI0SR                     @ 0xF4;
__sfr __no_init volatile unsigned char   SPI0DR                     @ 0xF5;
__sfr __no_init volatile unsigned char   DMA0BAH                    @ 0xF6;
__sfr __no_init volatile unsigned char   EIPH0                      @ 0xF7;

__sfr __no_init volatile union
{
  unsigned char S1CON ; /* S1CON  Register */
  struct /* S1CON  Register */
  {
    unsigned char BIT0 : 1;
    unsigned char BIT1 : 1;
    unsigned char BIT2 : 1;
    unsigned char BIT3 : 1;
    unsigned char BIT4 : 1;
    unsigned char BIT5 : 1;
    unsigned char BIT6 : 1;
    unsigned char BIT7 : 1;
  } S1CON_bit;
} @ 0xF8;
__sfr __no_init volatile unsigned char   SPI1CR0                    @ 0xF9;
__sfr __no_init volatile unsigned char   SPI1CR1                    @ 0xFA;
__sfr __no_init volatile unsigned char   SPI1SR                     @ 0xFB;
__sfr __no_init volatile unsigned char   SPI1DR                     @ 0xFC;
__sfr __no_init volatile unsigned char   DMA1BAH                    @ 0xFD;
__sfr __no_init volatile unsigned char   EIP1                       @ 0xFE;
__sfr __no_init volatile unsigned char   EIPH1                      @ 0xFF;

/* ML56 SFR BYTE page 1  */
__sfr __no_init volatile unsigned char   LIRCTRIM                   @ 0x84;
__sfr __no_init volatile unsigned char   XLTCON                     @ 0x85;
__sfr __no_init volatile unsigned char   CWKL                       @ 0x86;

__sfr __no_init volatile unsigned char   P0DW                       @ 0x8A;
__sfr __no_init volatile unsigned char   P1DW                       @ 0x8B;
__sfr __no_init volatile unsigned char   P2DW                       @ 0x8C;
__sfr __no_init volatile unsigned char   P3DW                       @ 0x8D;
__sfr __no_init volatile unsigned char   P4DW                       @ 0x8E;
__sfr __no_init volatile unsigned char   P5DW                       @ 0x8F;

__sfr __no_init volatile unsigned char   P0UP                       @ 0x92;
__sfr __no_init volatile unsigned char   P1UP                       @ 0x93;
__sfr __no_init volatile unsigned char   P2UP                       @ 0x94;
__sfr __no_init volatile unsigned char   P3UP                       @ 0x95;
__sfr __no_init volatile unsigned char   P4UP                       @ 0x96;
__sfr __no_init volatile unsigned char   P5UP                       @ 0x97;

__sfr __no_init volatile unsigned char   P0S                        @ 0x99;
__sfr __no_init volatile unsigned char   P0SR                       @ 0x9A;
__sfr __no_init volatile unsigned char   P1S                        @ 0x9B;
__sfr __no_init volatile unsigned char   P1SR                       @ 0x9C;
__sfr __no_init volatile unsigned char   P2S                        @ 0x9D;
__sfr __no_init volatile unsigned char   P2SR                       @ 0x9E;

__sfr __no_init volatile unsigned char   PIPS0                      @ 0xA1;
__sfr __no_init volatile unsigned char   PIPS1                      @ 0xA2;
__sfr __no_init volatile unsigned char   PIPS2                      @ 0xA3;
__sfr __no_init volatile unsigned char   PIPS3                      @ 0xA4;
__sfr __no_init volatile unsigned char   PIPS4                      @ 0xA5;
__sfr __no_init volatile unsigned char   PIPS5                      @ 0xA6;
__sfr __no_init volatile unsigned char   PIPS6                      @ 0xA7;

__sfr __no_init volatile unsigned char   VRFCON                     @ 0xA9;
__sfr __no_init volatile unsigned char   VRFTRIM                    @ 0xAA;
__sfr __no_init volatile unsigned char   ACMPCR2                    @ 0xAB;
__sfr __no_init volatile unsigned char   P3S                        @ 0xAC;
__sfr __no_init volatile unsigned char   P3SR                       @ 0xAD;
__sfr __no_init volatile unsigned char   P5SR                       @ 0xAE;
__sfr __no_init volatile unsigned char   PIPS7                      @ 0xAF;

__sfr __no_init volatile unsigned char   P0M1                       @ 0xB1;
__sfr __no_init volatile unsigned char   P0M2                       @ 0xB2;
__sfr __no_init volatile unsigned char   P1M1                       @ 0xB3;
__sfr __no_init volatile unsigned char   P1M2                       @ 0xB4;
__sfr __no_init volatile unsigned char   P2M1                       @ 0xB5;
__sfr __no_init volatile unsigned char   P2M2                       @ 0xB6;
__sfr __no_init volatile unsigned char   PWM0INTC                   @ 0xB7;

__sfr __no_init volatile unsigned char   P4M1                       @ 0xB9;
__sfr __no_init volatile unsigned char   P4M2                       @ 0xBA;
__sfr __no_init volatile unsigned char   P4S                        @ 0xBB;
__sfr __no_init volatile unsigned char   P4SR                       @ 0xBC;
__sfr __no_init volatile unsigned char   P5M1                       @ 0xBD;
__sfr __no_init volatile unsigned char   P5M2                       @ 0xBE;
__sfr __no_init volatile unsigned char   P5S                        @ 0xBF;

__sfr __no_init volatile unsigned char   CKDIV                      @ 0xC1;
__sfr __no_init volatile unsigned char   P3M1                       @ 0xC2;
__sfr __no_init volatile unsigned char   P3M2                       @ 0xC3;
__sfr __no_init volatile unsigned char   PWM0C4H                    @ 0xC4;
__sfr __no_init volatile unsigned char   PWM0C5H                    @ 0xC5;
__sfr __no_init volatile unsigned char   PORDIS                     @ 0xC6;

__sfr __no_init volatile unsigned char   AUXR1                      @ 0xC9;
__sfr __no_init volatile unsigned char   RCMP2L                     @ 0xCA;
__sfr __no_init volatile unsigned char   RCMP2H                     @ 0xCB;
__sfr __no_init volatile unsigned char   PWM0C4L                    @ 0xCC;
__sfr __no_init volatile unsigned char   PWM0C5L                    @ 0xCD;
__sfr __no_init volatile unsigned char   AINDIDS0                   @ 0xCE;

__sfr __no_init volatile unsigned char   PWM0PH                     @ 0xD1;
__sfr __no_init volatile unsigned char   PWM0C0H                    @ 0xD2;
__sfr __no_init volatile unsigned char   PWM0C1H                    @ 0xD3;
__sfr __no_init volatile unsigned char   PWM0C2H                    @ 0xD4;
__sfr __no_init volatile unsigned char   PWM0C3H                    @ 0xD5;
__sfr __no_init volatile unsigned char   PWM0NP                     @ 0xD6;
__sfr __no_init volatile unsigned char   PWM0FBD                    @ 0xD7;

__sfr __no_init volatile unsigned char   PWM0PL                     @ 0xD9;
__sfr __no_init volatile unsigned char   PWM0C0L                    @ 0xDA;
__sfr __no_init volatile unsigned char   PWM0C1L                    @ 0xDB;
__sfr __no_init volatile unsigned char   PWM0C2L                    @ 0xDC;
__sfr __no_init volatile unsigned char   PWM0C3L                    @ 0xDD;
__sfr __no_init volatile unsigned char   PWM0CON1                   @ 0xDF;

__sfr __no_init volatile unsigned char   CAPCON0                    @ 0xE1;
__sfr __no_init volatile unsigned char   CAPCON1                    @ 0xE2;
__sfr __no_init volatile unsigned char   CAPCON2                    @ 0xE3;
__sfr __no_init volatile unsigned char   C0L                        @ 0xE4;
__sfr __no_init volatile unsigned char   C0H                        @ 0xE5;
__sfr __no_init volatile unsigned char   C1L                        @ 0xE6;
__sfr __no_init volatile unsigned char   C1H                        @ 0xE7;

__sfr __no_init volatile unsigned char   PICON                      @ 0xE9;
__sfr __no_init volatile unsigned char   PINEN                      @ 0xEA;
__sfr __no_init volatile unsigned char   PIPEN                      @ 0xEB;
__sfr __no_init volatile unsigned char   C2L                        @ 0xED;
__sfr __no_init volatile unsigned char   C2H                        @ 0xEE;
__sfr __no_init volatile unsigned char   LDOTRIM                    @ 0xEF;

__sfr __no_init volatile unsigned char   SPI0CR1                    @ 0xF3;

__sfr __no_init volatile unsigned char   PWM0DTEN                   @ 0xF9;
__sfr __no_init volatile unsigned char   PWM0DTCNT                  @ 0xFA;
__sfr __no_init volatile unsigned char   PWM0MEN                    @ 0xFB;
__sfr __no_init volatile unsigned char   PWM0MD                     @ 0xFC;
__sfr __no_init volatile unsigned char   LVRFLTEN                   @ 0xFD;
__sfr __no_init volatile unsigned char   LVRDIS                     @ 0xFF;

/* ML56 SFR BYTE page 2  */
__sfr __no_init volatile unsigned char   P6M1                       @ 0x84;
__sfr __no_init volatile unsigned char   P6M2                       @ 0x85;
__sfr __no_init volatile unsigned char   PWM1PH                     @ 0x86;

__sfr __no_init volatile unsigned char   PWM1C0H                    @ 0x8A;
__sfr __no_init volatile unsigned char   PWM1C1H                    @ 0x8B;
__sfr __no_init volatile unsigned char   PWM1MD                     @ 0x8C;
__sfr __no_init volatile unsigned char   PWM1MEN                    @ 0x8D;
__sfr __no_init volatile unsigned char   P6SR                       @ 0x8E;
__sfr __no_init volatile unsigned char   P6DW                       @ 0x8F;

__sfr __no_init volatile unsigned char   P6MF10                     @ 0x92;
__sfr __no_init volatile unsigned char   P6MF32                     @ 0x93;
__sfr __no_init volatile unsigned char   P6MF54                     @ 0x94;
__sfr __no_init volatile unsigned char   P6MF76                     @ 0x95;
__sfr __no_init volatile unsigned char   P6S                        @ 0x96;
__sfr __no_init volatile unsigned char   P6UP                       @ 0x97;

__sfr __no_init volatile unsigned char   PWM1PL                     @ 0x99;
__sfr __no_init volatile unsigned char   PWM1C0L                    @ 0x9A;
__sfr __no_init volatile unsigned char   PWM1C1L                    @ 0x9B;
__sfr __no_init volatile unsigned char   PWM1CON0                   @ 0x9C;
__sfr __no_init volatile unsigned char   PWM1CON1                   @ 0x9D;
__sfr __no_init volatile unsigned char   PWM1INTC                   @ 0x9E;

__sfr __no_init volatile unsigned char   I2C0ADDR1                  @ 0xA1;
__sfr __no_init volatile unsigned char   I2C0ADDR2                  @ 0xA2;
__sfr __no_init volatile unsigned char   I2C0ADDR3                  @ 0xA3;
__sfr __no_init volatile unsigned char   I2C1ADDR1                  @ 0xA4;
__sfr __no_init volatile unsigned char   I2C1ADDR2                  @ 0xA5;
__sfr __no_init volatile unsigned char   I2C1ADDR3                  @ 0xA6;
__sfr __no_init volatile unsigned char   P6                         @ 0xA7;

__sfr __no_init volatile unsigned char   DMA3TSR                    @ 0xA9;
__sfr __no_init volatile unsigned char   DMA3BAH                    @ 0xAA;
__sfr __no_init volatile unsigned char   DMA3CR0                    @ 0xAB;
__sfr __no_init volatile unsigned char   DMA3MAL                    @ 0xAC;
__sfr __no_init volatile unsigned char   DMA3CNT                    @ 0xAD;
__sfr __no_init volatile unsigned char   DMA3CCNT                   @ 0xAE;
__sfr __no_init volatile unsigned char   MTM3DAL                    @ 0xAF;

__sfr __no_init volatile unsigned char   DMA2TSR                    @ 0xB1;
__sfr __no_init volatile unsigned char   DMA2BAH                    @ 0xB2;
__sfr __no_init volatile unsigned char   DMA2CR0                    @ 0xB3;
__sfr __no_init volatile unsigned char   DMA2MAL                    @ 0xB4;
__sfr __no_init volatile unsigned char   DMA2CNT                    @ 0xB5;
__sfr __no_init volatile unsigned char   DMA2CCNT                   @ 0xB6;
__sfr __no_init volatile unsigned char   MTM2DAL                    @ 0xB7;

__sfr __no_init volatile unsigned char   PWM2PH                     @ 0xB9;
__sfr __no_init volatile unsigned char   PWM2C0H                    @ 0xBA;
__sfr __no_init volatile unsigned char   PWM2C1H                    @ 0xBB;
__sfr __no_init volatile unsigned char   PWM2MD                     @ 0xBC;
__sfr __no_init volatile unsigned char   PWM2MEN                    @ 0xBD;
__sfr __no_init volatile unsigned char   CWKH                       @ 0xBE;
__sfr __no_init volatile unsigned char   RWKH                       @ 0xBF;

__sfr __no_init volatile unsigned char   PWM2PL                     @ 0xC1;
__sfr __no_init volatile unsigned char   PWM2C0L                    @ 0xC2;
__sfr __no_init volatile unsigned char   PWM2C1L                    @ 0xC3;
__sfr __no_init volatile unsigned char   PWM2CON0                   @ 0xC4;
__sfr __no_init volatile unsigned char   PWM2CON1                   @ 0xC5;
__sfr __no_init volatile unsigned char   PWM2INTC                   @ 0xC6;

__sfr __no_init volatile unsigned char   PWM3PH                     @ 0xC9;
__sfr __no_init volatile unsigned char   PWM3C0H                    @ 0xCA;
__sfr __no_init volatile unsigned char   PWM3C1H                    @ 0xCB;
__sfr __no_init volatile unsigned char   PWM3MD                     @ 0xCC;
__sfr __no_init volatile unsigned char   PWM3MEN                    @ 0xCD;
__sfr __no_init volatile unsigned char   AINDIDS1                   @ 0xCE;
__sfr __no_init volatile unsigned char   I2C0ADDRM                  @ 0xCF;

__sfr __no_init volatile unsigned char   PWM3PL                     @ 0xD1;
__sfr __no_init volatile unsigned char   PWM3C0L                    @ 0xD2;
__sfr __no_init volatile unsigned char   PWM3C1L                    @ 0xD3;
__sfr __no_init volatile unsigned char   PWM3CON0                   @ 0xD4;
__sfr __no_init volatile unsigned char   PWM3CON1                   @ 0xD5;
__sfr __no_init volatile unsigned char   PWM3INTC                   @ 0xD6;
__sfr __no_init volatile unsigned char   I2C1ADDRM                  @ 0xD7;

__sfr __no_init volatile unsigned char   SC1DR                      @ 0xD9;
__sfr __no_init volatile unsigned char   SC1EGT                     @ 0xDA;
__sfr __no_init volatile unsigned char   SC1ETURD0                  @ 0xDB;
__sfr __no_init volatile unsigned char   SC1ETURD1                  @ 0xDC;
__sfr __no_init volatile unsigned char   SC1IE                      @ 0xDD;
__sfr __no_init volatile unsigned char   SC1IS                      @ 0xDE;
__sfr __no_init volatile unsigned char   SC1TSR                     @ 0xDF;

__sfr __no_init volatile unsigned char   P5MF32                     @ 0xE1;
__sfr __no_init volatile unsigned char   P5MF54                     @ 0xE2;
__sfr __no_init volatile unsigned char   P5MF76                     @ 0xE3;
__sfr __no_init volatile unsigned char   BRCTRIM                    @ 0xE4;
__sfr __no_init volatile unsigned char   ADCCAL                     @ 0xE5;
__sfr __no_init volatile unsigned char   SC1CR0                     @ 0xE6;
__sfr __no_init volatile unsigned char   SC1CR1                     @ 0xE7;

__sfr __no_init volatile unsigned char   P3MF54                     @ 0xE9;
__sfr __no_init volatile unsigned char   P3MF76                     @ 0xEA;
__sfr __no_init volatile unsigned char   P4MF10                     @ 0xEB;
__sfr __no_init volatile unsigned char   P4MF32                     @ 0xEC;
__sfr __no_init volatile unsigned char   P4MF54                     @ 0xED;
__sfr __no_init volatile unsigned char   P4MF76                     @ 0xEE;
__sfr __no_init volatile unsigned char   P5MF10                     @ 0xEF;

__sfr __no_init volatile unsigned char   P1MF76                     @ 0xF1;
__sfr __no_init volatile unsigned char   P2MF10                     @ 0xF2;
__sfr __no_init volatile unsigned char   P2MF32                     @ 0xF3;
__sfr __no_init volatile unsigned char   P2MF54                     @ 0xF4;
__sfr __no_init volatile unsigned char   P2MF76                     @ 0xF5;
__sfr __no_init volatile unsigned char   P3MF10                     @ 0xF6;
__sfr __no_init volatile unsigned char   P3MF32                     @ 0xF7;

__sfr __no_init volatile unsigned char   P0MF10                     @ 0xF9;
__sfr __no_init volatile unsigned char   P0MF32                     @ 0xFA;
__sfr __no_init volatile unsigned char   P0MF54                     @ 0xFB;
__sfr __no_init volatile unsigned char   P0MF76                     @ 0xFC;
__sfr __no_init volatile unsigned char   P1MF10                     @ 0xFD;
__sfr __no_init volatile unsigned char   P1MF32                     @ 0xFE;
__sfr __no_init volatile unsigned char   P1MF54                     @ 0xFF;

/* ML56 SFR BYTE page 3  */

__sfr __no_init volatile unsigned char   DMA0CR1                    @ 0x8A;
__sfr __no_init volatile unsigned char   DMA1CR1                    @ 0x8B;
__sfr __no_init volatile unsigned char   DMA2CR1                    @ 0x8C;
__sfr __no_init volatile unsigned char   DMA3CR1                    @ 0x8D;

__sfr __no_init volatile unsigned char   DMA0CRC                    @ 0x92;
__sfr __no_init volatile unsigned char   DMA1CRC                    @ 0x93;
__sfr __no_init volatile unsigned char   DMA2CRC                    @ 0x94;
__sfr __no_init volatile unsigned char   DMA3CRC                    @ 0x95;

__sfr __no_init volatile unsigned char   WDCONH                     @ 0x99;
__sfr __no_init volatile unsigned char   DMA0SEED                   @ 0x9A;
__sfr __no_init volatile unsigned char   DMA1SEED                   @ 0x9B;
__sfr __no_init volatile unsigned char   DMA2SEED                   @ 0x9C;
__sfr __no_init volatile unsigned char   DMA3SEED                   @ 0x9D;

__sfr __no_init volatile unsigned char   RTCINIT                    @ 0xA1;
__sfr __no_init volatile unsigned char   RTCRWEN                    @ 0xA2;
__sfr __no_init volatile unsigned char   RTCCLKSEL                  @ 0xA3;
__sfr __no_init volatile unsigned char   RTCFREQADJ0                @ 0xA4;
__sfr __no_init volatile unsigned char   RTCFREQADJ1                @ 0xA5;
__sfr __no_init volatile unsigned char   RTCINTEN                   @ 0xA6;
__sfr __no_init volatile unsigned char   RTCINTSTS                  @ 0xA7;

__sfr __no_init volatile unsigned char   RTCTIMESEC                 @ 0xA9;
__sfr __no_init volatile unsigned char   RTCTIMEMIN                 @ 0xAA;
__sfr __no_init volatile unsigned char   RTCTIMEHR                  @ 0xAB;
__sfr __no_init volatile unsigned char   RTCCALDAY                  @ 0xAD;
__sfr __no_init volatile unsigned char   RTCCALMON                  @ 0xAE;
__sfr __no_init volatile unsigned char   RTCCALYEAR                 @ 0xAF;

__sfr __no_init volatile unsigned char   RTCTALMSEC                 @ 0xB1;
__sfr __no_init volatile unsigned char   RTCTALMMIN                 @ 0xB2;
__sfr __no_init volatile unsigned char   RTCTALMHR                  @ 0xB3;
__sfr __no_init volatile unsigned char   RTCTALMHZ                  @ 0xB4;
__sfr __no_init volatile unsigned char   RTCCALMDAY                 @ 0xB5;
__sfr __no_init volatile unsigned char   RTCCALMMON                 @ 0xB6;
__sfr __no_init volatile unsigned char   RTCCALMYEAR                @ 0xB7;

__sfr __no_init volatile unsigned char   RTCCLKFMT                  @ 0xB9;
__sfr __no_init volatile unsigned char   RTCWEEKDAY                 @ 0xBB;
__sfr __no_init volatile unsigned char   RTCLEAPYEAR                @ 0xBC;
__sfr __no_init volatile unsigned char   RTCTICK                    @ 0xBD;
__sfr __no_init volatile unsigned char   RTCTAMSK                   @ 0xBE;
__sfr __no_init volatile unsigned char   RTCCAMSK                   @ 0xBF;

__sfr __no_init volatile unsigned char   PWM0FBS                    @ 0xCE;
__sfr __no_init volatile unsigned char   AUXR3                      @ 0xCF;

__sfr __no_init volatile unsigned char   LCDCPALCT1                 @ 0xE9;
__sfr __no_init volatile unsigned char   LCDCPCT1                   @ 0xEA;

__sfr __no_init volatile unsigned char   LCDCPUMP                   @ 0xF1;
__sfr __no_init volatile unsigned char   LCDCON1                    @ 0xF4;
__sfr __no_init volatile unsigned char   LCDCPALCT0                 @ 0xF5;
__sfr __no_init volatile unsigned char   LCDCPCT0                   @ 0xF6;

__sfr __no_init volatile unsigned char   LCDCON0                    @ 0xF9;
__sfr __no_init volatile unsigned char   LCDCLK                     @ 0xFA;
__sfr __no_init volatile unsigned char   LCDPTR                     @ 0xFB;
__sfr __no_init volatile unsigned char   LCDDAT                     @ 0xFC;
__sfr __no_init volatile unsigned char   LCDPWR                     @ 0xFD;
__sfr __no_init volatile unsigned char   LCDBL                      @ 0xFE;
__sfr __no_init volatile unsigned char   LCDMODE                   @ 0xFF;


/*  BIT Registers  */
/*  P0  */
#define P00        P0_bit.BIT0
#define P01        P0_bit.BIT1
#define P02        P0_bit.BIT2
#define P03        P0_bit.BIT3
#define P04        P0_bit.BIT4
#define P05        P0_bit.BIT5
#define P06        P0_bit.BIT6
#define P07        P0_bit.BIT7

///*  TCON  */
#define TF1         TCON_bit.BIT7
#define TR1         TCON_bit.BIT6
#define TF0         TCON_bit.BIT5
#define TR0         TCON_bit.BIT4
#define IE1         TCON_bit.BIT3
#define IT1         TCON_bit.BIT2
#define IE0         TCON_bit.BIT1
#define IT0         TCON_bit.BIT0
//
///*  P1  */
#define P10         P1_bit.BIT0
#define P11         P1_bit.BIT1
#define P12         P1_bit.BIT2
#define P13         P1_bit.BIT3
#define P14         P1_bit.BIT4
#define P15         P1_bit.BIT5
#define P16         P1_bit.BIT6
#define P17         P1_bit.BIT7

/*  SCON  */
#define SM0         SCON_bit.BIT7
#define FE          SCON_bit.BIT7
#define SM1         SCON_bit.BIT6
#define SM2         SCON_bit.BIT5
#define REN         SCON_bit.BIT4
#define TB8         SCON_bit.BIT3
#define RB8         SCON_bit.BIT2
#define TI          SCON_bit.BIT1
#define RI          SCON_bit.BIT0

/*  P2  */
#define P20         P2_bit.BIT0
#define P21         P2_bit.BIT1
#define P22         P2_bit.BIT2
#define P23         P2_bit.BIT3
#define P24         P2_bit.BIT4
#define P25         P2_bit.BIT5
#define P26         P2_bit.BIT6
#define P27         P2_bit.BIT7

/*  IE  */
#define EA          IE_bit.BIT7
#define EADC        IE_bit.BIT6
#define EBOD        IE_bit.BIT5
#define ES          IE_bit.BIT4
#define ET1         IE_bit.BIT3
#define EX1         IE_bit.BIT2
#define ET0         IE_bit.BIT1
#define EX0         IE_bit.BIT0

/*  P3  */
#define P30         P3_bit.BIT0
#define P31         P3_bit.BIT1
#define P32         P3_bit.BIT2
#define P33         P3_bit.BIT3
#define P34         P3_bit.BIT4
#define P35         P3_bit.BIT5
#define P36         P3_bit.BIT6
#define P37         P3_bit.BIT7

/*  IP  */
#define PADC        IP_bit.BIT6
#define PBOD        IP_bit.BIT5
#define PS          IP_bit.BIT4
#define PT1         IP_bit.BIT3
#define PX1         IP_bit.BIT2
#define PT0         IP_bit.BIT1
#define PX0         IP_bit.BIT0

/*  I2C0CON  */
#define I2CEN0      I2C0CON_bit.BIT6
#define STA0        I2C0CON_bit.BIT5
#define STO0        I2C0CON_bit.BIT4
#define SI0         I2C0CON_bit.BIT3
#define AA0         I2C0CON_bit.BIT2
#define I2C0PX      I2C0CON_bit.BIT0

/*  I2C1CON  */
#define I2CEN1       I2C1CON_bit.BIT6
#define STA1         I2C1CON_bit.BIT5
#define STO1         I2C1CON_bit.BIT4
#define SI1          I2C1CON_bit.BIT3
#define AA1          I2C1CON_bit.BIT2
#define I2CPX1       I2C1CON_bit.BIT0

/*  T2CON  */
#define TF2         T2CON_bit.BIT7
#define TR2         T2CON_bit.BIT2
#define CM_RL2      T2CON_bit.BIT0

/*  PSW */
#define CY          PSW_bit.BIT7
#define AC          PSW_bit.BIT6
#define F0          PSW_bit.BIT5
#define RS1         PSW_bit.BIT4
#define RS0         PSW_bit.BIT3
#define OV          PSW_bit.BIT2
#define P           PSW_bit.BIT0

/*  P4  */
#define P40         P4_bit.BIT0
#define P41         P4_bit.BIT1
#define P42         P4_bit.BIT2
#define P43         P4_bit.BIT3
#define P44         P4_bit.BIT4
#define P45         P4_bit.BIT5
#define P46         P4_bit.BIT6
#define P47         P4_bit.BIT7


/*  SCON_1  */
#define SM0_1       S1CON_bit.BIT7
#define FE_1        S1CON_bit.BIT7
#define SM1_1       S1CON_bit.BIT6
#define SM2_1       S1CON_bit.BIT5
#define REN_1       S1CON_bit.BIT4
#define TB8_1       S1CON_bit.BIT3
#define RB8_1       S1CON_bit.BIT2
#define TI_1        S1CON_bit.BIT1
#define RI_1        S1CON_bit.BIT0


// /*  Other Pin Name  */
#define AIN0        P2_bit.BIT5
#define AIN1        P2_bit.BIT4
#define AIN2        P2_bit.BIT3
#define AIN3        P2_bit.BIT2
#define AIN4        P2_bit.BIT1
#define AIN5        P2_bit.BIT0
#define AIN6        P3_bit.BIT1
#define AIN7        P3_bit.BIT2

#define ACMP_P0     P2_bit.BIT5
#define ACMP_P1     P2_bit.BIT3
#define ACMP_P2     P2_bit.BIT1
#define ACMP_P3     P3_bit.BIT0

#define ACMP0_N0    P2_bit.BIT4
#define ACMP0_N1    P2_bit.BIT0
#define ACMP1_N0    P2_bit.BIT2
#define ACMP1_N1    P3_bit.BIT1

