/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/29/2020
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: ML51 Data table special location @0x2C00 and 0x3400 demo
//***********************************************************************************************************
#include "ML51_IAR.h"

//=========================================================================================================
void main(void)
{
    __code const unsigned char *Table_Address_Locate @ 0x2C00;
   // unsigned char __code *Table_Data_Locate;
    unsigned char readtemp;
   
    //Table_Address_Locate = 0x2C00;
    readtemp = ( __code const unsigned char)*Table_Address_Locate;
   
    //Table_Data_Locate = 0x3404;
   // readtemp1 = *Table_Data_Locate;
  
    while(1);
}