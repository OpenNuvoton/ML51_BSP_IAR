/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "ML51_IAR.h"

__data unsigned char BIT_TMP;
__data unsigned char TA_REG_TMP,SFRS_TMP,BYTE_TMP;

/**
 * @brief       Read Dataflash
 * @param       Dataflash start address
 * @return      Dataflash Value
 * @details     None
 */

unsigned char Read_APROM_BYTE(unsigned int __code *u16_addr)
{
    unsigned int rdata;
    rdata = *u16_addr;
    return rdata;
}

