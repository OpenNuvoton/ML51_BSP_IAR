#define  GPIO_LED               P32    /* the NuMaker board GPIO LED pin define */
#define  MFP_LED_GPIO           MFP_P32_GPIO
#define  GPIO_LED_QUASI_MODE    P32_QUASI_MODE
#define  GPIO_PRINTF            P31

#define  BOOT_APROM     0
#define  BOOT_LDROM     2

extern BIT BIT_TMP;
extern unsigned char __data  TA_REG_TMP,SFRS_TMP,BYTE_TMP;

unsigned char Read_APROM_BYTE(unsigned int __code *u16_addr);
void Software_Reset(unsigned char u8Bootarea);
void PowerDown_Mode(unsigned char PDStatus);
void Global_Interrupt(unsigned char u8IntStatus);
