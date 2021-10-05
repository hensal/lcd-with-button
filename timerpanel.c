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
* File Name    : timerpanel.c
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
#include <string.h>
#include "timerpanel.h"

#if defined TIM_USED
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
static UCHAR	ucgTIMER_Last[(TIM_USED / 8) + 1];
static UCHAR	ucgTIMER_LastIn[(TIM_USED / 8) + 1];
static USHORT	usgTIMER_Val[TIM_USED];
static UCHAR	ucgTIMER_Cnt = 0;

static UCHAR TIMER_Hold( UCHAR In, USHORT Cnt, UCHAR Trig);
static UCHAR TIMER_Toggle( UCHAR In, USHORT Cnt, UCHAR Trig);
static UCHAR TIMER_OneShotR( UCHAR In, USHORT Cnt, UCHAR Trig);
static UCHAR TIMER_OneShotN( UCHAR In, USHORT Cnt, UCHAR Trig);

/*******************************************************************************
* Function Name: TIMER_Hold
* Description  : TIMER panel Hold-Type.
* Arguments    : In   ... ON/OFF
*                Cnt  ... time count
*                Trig ... time unit (1sec or 50ms)
* Return Value : out
********************************************************************************/
UCHAR TIMER_Hold( UCHAR In, USHORT Cnt, UCHAR Trig )
{
	UCHAR	ucret;
	USHORT	usval;
	
	if(In == LOW)
	{
		ucret = LOW;
		usval = 0;
	}
	else if(In == HIGH)
	{
		ucret = BitMemGet(ucgTIMER_Last, ucgTIMER_Cnt);
		usval = usgTIMER_Val[ucgTIMER_Cnt];
		if(Trig == HIGH)
		{
			usval ++;
			if(usval >= Cnt)
			{
				ucret = HIGH;
				usval = Cnt;
			}
		}
	}
	
	BitMemSet(ucgTIMER_Last, ucgTIMER_Cnt, ucret);
	usgTIMER_Val[ucgTIMER_Cnt] = usval;
	
	return (ucret);
}

/*******************************************************************************
* Function Name: TIMER_Toggle
* Description  : TTIMER panel TOGGLE-Type.
* Arguments    : In   ... ON/OFF
*                Cnt  ... time count
*                Trig ... time unit (1sec or 50ms)
* Return Value : out
********************************************************************************/
UCHAR TIMER_Toggle( UCHAR In, USHORT Cnt, UCHAR Trig )
{
	UCHAR	ucret;
	USHORT	usval;

	if(In == LOW)
	{
		ucret = LOW;
		usval = 0;
	}
	else if(In == HIGH)
	{
		ucret = BitMemGet(ucgTIMER_Last, ucgTIMER_Cnt);
		usval = usgTIMER_Val[ucgTIMER_Cnt];
		if(Trig == HIGH)
		{
			usval ++;
			if(usval >= Cnt)
			{
				ucret = NOT1_(ucret);
				usval = 0;
			}
		}
	}

	BitMemSet(ucgTIMER_Last, ucgTIMER_Cnt, ucret);
	usgTIMER_Val[ucgTIMER_Cnt] = usval;
	
	return (ucret);
}

/*******************************************************************************
* Function Name: TIMER_OneShotR
* Description  : TIMER panel OneShot(Retriggerable)-Type.
* Arguments    : In   ... ON/OFF
*                Cnt  ... time count
*                Trig ... time unit (1sec or 50ms)
* Return Value : out
********************************************************************************/
UCHAR TIMER_OneShotR( UCHAR In, USHORT Cnt, UCHAR Trig )
{
	UCHAR	ucret;
	UCHAR	uclastin;
	USHORT	usval;
	
	ucret = BitMemGet(ucgTIMER_Last, ucgTIMER_Cnt);
	uclastin = BitMemGet(ucgTIMER_LastIn, ucgTIMER_Cnt);
	usval = usgTIMER_Val[ucgTIMER_Cnt];

	if(In == HIGH)
	{
		if(uclastin == LOW)
		{
			ucret = HIGH;
			usval = 0;
		}
	}
	
	if(ucret == HIGH)
	{
		if(Trig == HIGH)
		{
			usval ++;
			if(usval > Cnt)		ucret = LOW;
		}
	}

	usgTIMER_Val[ucgTIMER_Cnt] = usval;
	BitMemSet(ucgTIMER_LastIn, ucgTIMER_Cnt, In);
	BitMemSet(ucgTIMER_Last, ucgTIMER_Cnt, ucret);

	return (ucret);
}

/*******************************************************************************
* Function Name: TIMER_OneShotN
* Description  : TIMER panel OneShot(Non-Triggerable)-Type.
* Arguments    : In   ... ON/OFF
*                Cnt  ... time count
*                Trig ... time unit (1sec or 50ms)
* Return Value : out
********************************************************************************/
UCHAR TIMER_OneShotN( UCHAR In, USHORT Cnt, UCHAR Trig )
{
	UCHAR	ucret;
	UCHAR	uclastin;
	USHORT	usval;
	
	ucret = BitMemGet(ucgTIMER_Last, ucgTIMER_Cnt);
	uclastin = BitMemGet(ucgTIMER_LastIn, ucgTIMER_Cnt);
	usval = usgTIMER_Val[ucgTIMER_Cnt];

	if(In == HIGH)
	{
		if(uclastin == LOW)
		{
			if(ucret == LOW)
			{
				ucret = HIGH;
				usval = 0;
			}
		}
	}
	
	if(ucret == HIGH)
	{
		if(Trig == HIGH)
		{
			usval ++;
			if(usval > Cnt)		ucret = LOW;
		}
	}

	usgTIMER_Val[ucgTIMER_Cnt] = usval;
	BitMemSet(ucgTIMER_LastIn, ucgTIMER_Cnt, In);
	BitMemSet(ucgTIMER_Last, ucgTIMER_Cnt, ucret);

	return (ucret);
}

/*******************************************************************************
* Function Name: TIMER_Initialize
* Description  : TIMER Panel Initialize.
* Arguments    : none
* Return Value : none
********************************************************************************/
void TIMER_Initialize( void )
{
	memset(ucgTIMER_Last, 0, (TIM_USED / 8) + 1);
	memset(ucgTIMER_LastIn, 0,(TIM_USED / 8) + 1);
	memset(usgTIMER_Val, 0, TIM_USED * 2);
}

/*******************************************************************************
* Function Name: TIMER_Counter_Clear
* Description  : TIMER Panel Counter Clear.
* Arguments    : none
* Return Value : none
********************************************************************************/
void TIMER_Counter_Clear( void )
{
	ucgTIMER_Cnt = 0;
}

/*******************************************************************************
* Function Name: TIMER_Processing
* Description  : TIMER Panel Processing.
* Arguments    : Mode      ... Timer Mode(TIMER_HOLD/TIMER_TOGGLE/TIMER_ONESHOT_R/TIMER_ONESHOT_N)
*                ucTrg50ms ... 50ms Counter
*                ucTrg1s   ... 1s Counter
*                Sec       ... Second
*                MSec      ... MiliSecound
*                In        ... Input Value
* Return Value : Out       ... Processing Value
********************************************************************************/
UCHAR TIMER_Processing( UCHAR Mode, UCHAR ucTrg50ms, UCHAR ucTrg1s, USHORT Sec, USHORT MSec, UCHAR In )
{
	UCHAR	ucret;
	USHORT	uscnt;
	UCHAR	uctrig;

	if(Sec < 1200)
	{
		uctrig = ucTrg50ms;
		uscnt = (20 * Sec) + (MSec / 50);
	}
	else
	{
		uctrig = ucTrg1s;
		uscnt = Sec;
	}

	switch(Mode)
	{
		case TIMER_HOLD:
			ucret = TIMER_Hold(In, uscnt, uctrig);
			break;
		case TIMER_TOGGLE:
			ucret = TIMER_Toggle(In, uscnt, uctrig);
			break;
		case TIMER_ONESHOT_R:
			ucret = TIMER_OneShotR(In, uscnt, uctrig);
			break;
		case TIMER_ONESHOT_N:
			ucret = TIMER_OneShotN(In, uscnt, uctrig);
			break;
	}

	ucgTIMER_Cnt ++;

	return(ucret & 0x01);
}
#endif /* end of defined TIM_USED */

