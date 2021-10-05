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
* File Name    : timer.c
* Version      : Applilet EZ PL for RL78
* Device(s)    : R5F1056A,R5F1057A,R5F1058A
* Tool-Chain   : CC-RL
* Description  : This file implements main function.
* Creation Date: 2016/09/14
*******************************************************************************/

/*******************************************************************************
Includes <System Includes> , "Project Includes"
*******************************************************************************/
#ifdef __CCRL__
#include "sfr.h"
#include "common.h"
#include "config.h"
#include "timer.h"
#pragma interrupt	MD_INTTM00(vect=INTTM00)

#else
#error "undefined compiler"
#endif

/*******************************************************************************
Macro definitions
*******************************************************************************/
#define	TM_10MS		40				/* Standard timer interrupt(250us) x 40 times */
#define	TM_50MS		5				/* 10ms x 5 times */
#define	TM_1MS		4				/* 250us x 4 times */
#define	TM_1S		20				/* 50ms x 20 times */

#define	TM_250US_1250K	312			/* 250us = 1/1.25MHz * 312 */
#define	TM_250US_2500K	625			/* 250us = 1/2.5MHz  * 625 */

/*******************************************************************************
Typedef definitions
*******************************************************************************/

/*******************************************************************************
Imported global variables and functions (from other files)
*******************************************************************************/
#ifdef PULSE_USED
extern UCHAR	ucgPULSE_Tm;
#endif /* end of defined PULSE_USED */

/*******************************************************************************
Exported global variables and functions (to be accessed by other files)
*******************************************************************************/
#ifdef __CCRL__
__saddr UCHAR	SysTm10ms;				/* 10ms Timer for making */
__saddr UCHAR	SysTm50ms;				/* 50ms Timer for making */
__saddr UCHAR	SysTm1s;				/*   1s Timer for making */

#else
#error "undefined compiler"
#endif

/*******************************************************************************
* Function Name: __interrupt MD_INTTM00
* Description  : Interrupt processing of standard cycle
* Arguments    : none
* Return Value : none
********************************************************************************/
#ifdef __CCRL__
void MD_INTTM00( void )
#else
#error "undefined compiler"
#endif
{
	SysTm10ms++;				/* System timer processing */
	if(SysTm10ms >= TM_10MS){
		SysTm10ms = 0;
		fTm10ms = 1;
	}

#ifdef PULSE_USED
	/* Pulse output processing */
	ucgPULSE_Tm++;
#endif /* end of defined PULSE_USED */
}

#if !defined PWM_USED
/*******************************************************************************
* Function Name: TM00_Init
* Description  : This function initializes TM00_module.
* Arguments    : none
* Return Value : none
********************************************************************************/
void TM00_Init( void )
{
	TAU0EN = 1;	/* enables input clock supply */
	
	TMMK00 = 1;
	TMIF00 = 0;

	/* 16bit TIMER */
	TPS0 =0x0000;
	TT0  = 0x0001;			/* TT00 = 1(timer stop) */
	TMR00 = 0x0000;

	TDR00 = SYS_CLOCK_FREQ * 250 - 1;	/* 0.25ms */

	TO0  &= ~0x0001;		/* TO00  = 1 */
	TOE0 &= ~0x0001;		/* TOE00 = 1 */

	TMIF00 = 0;
	TMMK00 = 0;
	TS0 |= 0x0001;			/* TS00   = 1(timer start) */
}

/*******************************************************************************
* Function Name: TM_10ms
* Description  : 10ms count Processing.
* Arguments    : none
* Return Value : status
********************************************************************************/
UCHAR TM_10ms( void )
{
	/* Timer trigger generation */
	fTrg10ms = 0;
	fTrg50ms = 0;
	fTrg1s = 0;
	
	if(fTm10ms == 1){
		fTrg10ms = 1;
		SysTm50ms++;
		if(SysTm50ms >= TM_50MS){
			SysTm50ms = 0;
			fTrg50ms = 1;

			SysTm1s++;
			if(SysTm1s >= TM_1S){
				SysTm1s = 0;
				fTrg1s = 1;
			}
		}
		fTm10ms = 0;
		return(1);
	}
	return(0);
}
#endif /* end of defined PWM_USED */

