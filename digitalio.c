
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
* File Name    : digitalio.c
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
#include "digitalio.h"

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
#if defined DGIN_USED
UCHAR g_ucDGIN_LastRet[(DGIN_USED / 8) + 1];
UCHAR g_ucDGIN_ElapsedTime[ DGIN_USED ];
UCHAR g_ucDGIN_Count;
#endif /* end of defined DGIN_USED */

/*******************************************************************************
Private variables and functions
*******************************************************************************/

#if defined DGOUT_USED
/*******************************************************************************
* Function Name: DGOUT_setValue
* Description  : Digital Process
* Arguments    : port   ... output port number
*                In     ... Out Value.
*                Active ... high or low.
* Return Value : none
********************************************************************************/
void DGOUT_setValue( UCHAR port, UCHAR In, UCHAR Active )
{
	UCHAR	ucVal;

	ucVal = In & 0x01;
	if (Active==LOW){
		ucVal = (~ucVal) & 0x01;
	}

	Port_Set(port/10,port%10,ucVal);
}
#endif /* end of defined DGOUT_USED */

#if defined DGIN_USED
/*******************************************************************************
* Function Name: DGIN_Initialize
* Description  : Digital Process
* Arguments    : Active
* Return Value : none
********************************************************************************/
void DGIN_Initialize( UCHAR Active )
{
	/* BitMemSet( "Last input value of DGIN", "Number of DGIN panels", 0) */
	BitMemSet(g_ucDGIN_LastRet, g_ucDGIN_Count, ~Active & 0x01);

	/* BitMemSet( "Count value of DGIN panel", "Number of DGIN panels", 0) */
	ByteMemSet(g_ucDGIN_ElapsedTime,g_ucDGIN_Count, 0);
}

/*******************************************************************************
* Function Name: DGIN_Counter_Clear
* Description  : DGIN_Counter_Clear
* Arguments    : none
* Return Value : none
********************************************************************************/
void DGIN_Counter_Clear( void )
{
	/* "Count value of DGIN panel" <- 0 */
	g_ucDGIN_Count = 0;
}

/*******************************************************************************
* Function Name: DGIN_getValue
* Description  : DGIN_getValue
* Arguments    : Port     ...Terminal number
*                Active   ...Active
*                Value    ...Chattering absorption time(Each 10ms)
*                Trig     ...Count trigger(Fix 10ms)
* Return Value : Input value
********************************************************************************/
UCHAR DGIN_getValue( UCHAR Port, UCHAR Value, UCHAR Trig )
{

	UCHAR	ucInputValue;	/* Input value of specified port */
	UCHAR	ucRet;			/* Return value */
	UCHAR	uccount;		/* Count value of DGIN */
	UCHAR	ucLastLet;		/* Last input value of DGIN */
	
	/* (Input value of specified port) <- PORT_in( (Port) ) */
	ucInputValue = Port_Get( Port/10, Port%10 );
	if (Value == 0) {
		return ucInputValue;
	}
	/* Last value of DGIN is acquired. */
	ucLastLet = BitMemGet(g_ucDGIN_LastRet, g_ucDGIN_Count);
	
	/* Count value of DGIN panel is acquired. */
	uccount = ByteMemGet(g_ucDGIN_ElapsedTime, g_ucDGIN_Count);
	
	if (ucInputValue != ucLastLet) {

		if (Trig == 1) {
			/*  "Count value of DGIN" <- "Count value of DGIN" + 1 */
			uccount++;
			if ( uccount >= Value) {
				/* (Last value of DGIN) <- (Input value of specified port) */
				ucLastLet = ucInputValue;
				
				/* "Count value of DGIN" <- 0 */
				uccount = 0;
				/* Last value of DGIN is preserved. */
				BitMemSet(g_ucDGIN_LastRet, g_ucDGIN_Count, ucInputValue);
			}
		}
	}
	else {
		/* "Count value of DGIN" <- 0 */
		uccount = 0;
	}
	
	/* "Count value of DGIN" is preserved. */
	ByteMemSet(g_ucDGIN_ElapsedTime,g_ucDGIN_Count, uccount);
	
	/* (Return value) <- Last value of DGIN */
	ucRet = ucLastLet;
	
	return ucRet;

}

/*******************************************************************************
* Function Name: DGIN_Counter
* Description  : DGIN_Counter
* Arguments    : none
* Return Value : none
********************************************************************************/
void DGIN_Counter( void )
{
	/* "Count value of DGIN panel" <- "Count value of DGIN panel" + 1 */
	g_ucDGIN_Count++;
}
#endif /* end of defined DGIN_USED */
