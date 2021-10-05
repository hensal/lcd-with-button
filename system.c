/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
*******************************************************************************/

/*******************************************************************************
* File Name    : system.c
* Version      : Applilet EZ PL for RL78
* Device(s)    : R5F1056A,R5F1057A,R5F1058A
* Tool-Chain   : CC-RL
* Description  : This file implements main function.
* Creation Date: 2016/09/14
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#include "sfr.h"
#include "common.h"
#include "config.h"
#include "system.h"

/*******************************************************************************
Macro definitions
*******************************************************************************/

/*******************************************************************************
Typedef definitions
*******************************************************************************/

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/

/*******************************************************************************
Private variables and functions
*******************************************************************************/

/*******************************************************************************
* Function Name: Clock_Init
* Description  : This function initializes the clock generator.
* Arguments    : none
* Return Value : none
********************************************************************************/
void Clock_Init( void )
{
	UCHAR	ucsysclocksrc;
	UCHAR	ucsysclockfreq;
	UCHAR	uccmcinitval;

	ucsysclocksrc = SYS_CLOCK_SRC;
	if( (ucsysclocksrc == CLOCK_SRC_X1) || (ucsysclocksrc == CLOCK_SRC_EXTERNAL) ) {
		uccmcinitval = 0x00;
		if(ucsysclocksrc == CLOCK_SRC_X1) {
			uccmcinitval = CMC_MODE_X1;
			ucsysclockfreq = SYS_CLOCK_FREQ;
			if(ucsysclockfreq > 10) {
				uccmcinitval |= CMC_SYS_CLOCK_OVER_10MHZ;
			}
			else {
				uccmcinitval |= CMC_SYS_CLOCK_UNDER_10MHZ;
			}
		}
		else {
			uccmcinitval = CMC_MODE_EXTCLOCK;
		}
		CMC = uccmcinitval;

		/* CSC register setting */
		CSC = CSC_INVALID_VAL;

		if(ucsysclocksrc == CLOCK_SRC_X1) {
			while(OSTC != 0xFF);
		}

		MCM0 = 1;
		while (MCS != 1)		/* Wait Main Clock to be set. */
		{
			NOP();
		}
		HIOSTOP  = 1;			/* HOCO operation stop */
	}
	else if( ucsysclocksrc == CLOCK_SRC_MIDDLESPEED ) {
		
		switch (SYS_CLOCK_FREQ)
		{
			case 4:
				/* clock is set to 4MHz. */
				//MOCODIV = 0x00;
				
				break;
				
			case 2:
				/* clock is set to 2MHz. */
				//MOCODIV = 0x01;
				
				break;
				
			case 1:
				/* clock is set to 1MHz. */
				//MOCODIV = 0x02;
				
				break;
				
			default:
				break;
		}
		
		/* Clock changing: change to MOCO. */
		//MIOEN = 1;					/* MOCO operation start */
		//MCM1 = 1;					/* Set fOCO to MOCO. */
		while ( 1)			/* Wait fOCO to be set to MOCO. */
		{
			NOP();
		}
		HIOSTOP  = 1;				/* HOCO operation stop */
	}
}
