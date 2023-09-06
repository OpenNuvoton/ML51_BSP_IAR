/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_iar.h"
#include "sprom.h"

/* SPROM area address define in .xcl file */
/* "SPROM_C" define in lnk51ew_ml51.xcl */
unsigned char SPROM_FUNC(unsigned char unused)  @ "SPROM_C"
{
  GPIO_LED ^= 1;
  SPTEMP++;
  return SPTEMP;
}
