#ifndef __TK_DEMO_H__
#define __TK_DEMO_H__

#define OPT_SLIDER
//#define UART1_DBG                                     /* Trace code with UART1 message */

//TK_Param.c
int8_t TK_LoadPara(uint32_t* pu32ChanelMsk);
int8_t TK_SavePara(void);

//TK_Led.c
void InitLEDIO(void);
void TK_lightLED(uint8_t onOff, int chanN);

//TK_MultPinFunctions.c
void SetTkMultiFun(uint16_t u16TkMsk);

void FMC_Open(void);
signed char FMC_Erase(unsigned int u16Addr);
signed char FMC_Write(unsigned int u32Addr, unsigned long u32Data);

void UART0_Init(void);
void UART1_Init(void);

void Init_SysTick(void);
char TickSetTickEvent(unsigned long uTimeTick, void* pvFun);
void TickClearTickEvent(uint8_t u8TimeEventID);

/* TK_UartCmd.c */
void UART_SetCalibrationDone(void);

#endif /* __TK_DEMO_H__ */


